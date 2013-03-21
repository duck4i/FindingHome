#include "GameEntityPlayer.h"

bool GameEntityPlayer::init()
{
	//	init main image
	CCTextureCache *cache = CCTextureCache::sharedTextureCache();
	CCTexture2D *player1 = cache->addImage(RESOURCE_PLAYER);
		
	//	add sprite frames
	m_animationStill = CCAnimation::create();
	m_animationStill->addSpriteFrameWithFileName(RESOURCE_PLAYER);
	m_animationStill->addSpriteFrameWithFileName(RESOURCE_PLAYER2);
	m_animationStill->addSpriteFrameWithFileName(RESOURCE_PLAYER3);
	m_animationStill->addSpriteFrameWithFileName(RESOURCE_PLAYER4);
	m_animationStill->setDelayPerUnit(0.2f);	

	LevelProperties* opt = LevelProperties::sharedProperties();
	if (opt)
	{
		if (opt->PlayerJump)
			jumpValue = opt->PlayerJump;
		if (opt->PlayerMaxSpeed)
			maxSpeed = opt->PlayerMaxSpeed;
		if (opt->PlayerThrust)
			stepValue = opt->PlayerThrust;
		if (opt->PlayerMidAirModifier)
			midAirFactor = opt->PlayerMidAirModifier;
		if (opt->PlayerShiftModifier)
			shiftFactor = opt->PlayerShiftModifier;
	}
	
	//	Create animation
	CCAction* a = CCRepeatForever::create(CCAnimate::create(m_animationStill));	

	m_skin = CCSprite::createWithTexture(player1);
	if (!m_skin)
		return false;
	
	//	run animation
	m_skin->runAction(a);

	//	set scale
	m_skin->setPosition(m_nodeInfo.position);
	m_skin->setScale(1.3f);

	return true;
}

bool GameEntityPlayer::createBody(b2World *world)
{
	b2BodyDef def;

	def.userData = this;
	this->retain();

	def.type = b2_dynamicBody;
	def.position.Set(SCREEN_TO_WORLD(m_nodeInfo.position.x), SCREEN_TO_WORLD(m_nodeInfo.position.y));		

	m_b2Body = world->CreateBody(&def);

	CCSize playerSize = m_skin->getContentSize();

	b2CircleShape doggyShape;
	doggyShape.m_radius = SCREEN_TO_WORLD(playerSize.height * m_skin->getScale() / 2 + 5);
	
	m_b2FixtureDef.density = 4.0f;
	m_b2FixtureDef.friction = 1.0f;
	m_b2FixtureDef.restitution = 0;
	m_b2FixtureDef.shape = &doggyShape;	
	m_b2FixtureDef.filter.categoryBits = 0x0002;
	//m_b2FixtureDef.filter.maskBits = 0x0004;	//	filter out collectables

	m_b2Body->CreateFixture(&m_b2FixtureDef);
			
	b2FixtureDef groundBody;
	b2PolygonShape groundBodyShape;
	
	playerSize.height = 60;	//	more than player size - so it goes into ground
	playerSize.width -= 20;
	b2Vec2 center = m_b2Body->GetLocalCenter();
	center.y -= SCREEN_TO_WORLD(40);

	groundBodyShape.SetAsBox(SCREEN_TO_WORLD(playerSize.width / 2), SCREEN_TO_WORLD(playerSize.height / 2), center, 0);	

	groundBody.isSensor = true;
	groundBody.shape = &groundBodyShape;

	m_sensorFixture = m_b2Body->CreateFixture(&groundBody);

	return true;
}

void GameEntityPlayer::updatePosition(b2Vec2 pos)
{
	CCPoint posRecalc = ccp(WORLD_TO_SCREEN(pos.x), WORLD_TO_SCREEN(pos.y) - 15);
	m_skin->setPosition(posRecalc);
}

void GameEntityPlayer::updateRotation(float32 angle)
{
	///	todo rotation when on steep hils etc
}

void GameEntityPlayer::updatePlayerMovement(float delta)
{
	PROFILE_FUNC();

	float isMidAir = isPlayerMidAir();
	b2Vec2 playerVelocity = m_b2Body->GetLinearVelocity();

	//	Get key states
	KeyboardHelper *key = KeyboardHelper::sharedHelper();		

	float x = 0;
	float y = 0;

	bool leftDown = key->getLeft() == KeyStateDown;
	bool rightDown = key->getRight() == KeyStateDown;

	if (leftDown)
		x -= stepValue;
	if (rightDown)
		x += stepValue;

	KeyState kup = key->getUp();
	
	if (kup == KeyStateUp)
	{
		m_bVerticalThrustWasOn = 0;
		m_bVerticalThrustCounter = 0;
	}

	if (kup == KeyStateDown || kup == KeyStateUndefined && m_bVerticalThrustWasOn >= 0)
		m_bVerticalThrustWasOn += delta;

	//CCLog("TIME: %f", m_bVerticalThrustWasOn);
	bool halfstepCase = kup == KeyStateUndefined && m_bVerticalThrustWasOn != -1;
	bool enoughTimePassed = m_bVerticalThrustWasOn >= PLAYER_JUMP_HALFSTEP / (m_bVerticalThrustCounter > 0 ? m_bVerticalThrustCounter : 1);
	if (halfstepCase && enoughTimePassed)
	{
		kup = KeyStateDown;
		if (m_bVerticalThrustCounter++ > PLAYER_HALFSTEP_TIMES)
			m_bVerticalThrustWasOn = -1;
		else
			m_bVerticalThrustWasOn = 0;

		y = PLAYER_HALFSTEP_VALUE / m_bVerticalThrustCounter;		
	}
	else
		if ( kup == KeyStateDown )
			y += jumpValue;	

	
	if (x || y)
	{
		if (x)
			m_bForwardTrustWasOn += delta;

		//	
		//	Calculate and apply forces for movement
		//		

		//	http://www.box2d.org/forum/viewtopic.php?f=3&t=4733
		//	http://www.ikbentomas.nl/other/box2d/
		//	http://www.cocos2d-iphone.org/forum/topic/13501				

		float maxSpeed = this->maxSpeed;		

		//	no more jumping and only slight adjustment of direction when in air			
		if (isMidAir)
		{
			x *= midAirFactor;

			bool specialJumpCase = (m_bVerticalThrustWasOn == -1 || m_bVerticalThrustCounter > 0);
			if (specialJumpCase && playerVelocity.y > 0 /* in jump - not falling yet*/);
			else
				y = 0;	//	no jumping when mid air
		}
		
		///
		///	Shift button feature
		///
		if (key->getShift() == KeyStateDown && !isMidAir)
		{
			x *= shiftFactor;
			maxSpeed *= shiftFactor;
			y *= shiftFactor;
		}

		//	apply horizontal force - take care of max velocity
		const float speed = abs(playerVelocity.x);
		if (speed >= maxSpeed)
		{
			x = 0;
			//y = 0;	//	now vertical speed is speed limited too
		}
		

		//	TODOs:
		//	- Player is too light, needs to fall faster
		//	- Arc that is made looks like /----------\ but should be sharper corner like /----\ (no long jumps if not used shift)
		//	- Camera only needs to have affect when player is not MID-AIR??? (super mario style)

		m_b2Body->ApplyLinearImpulse(b2Vec2(x, y), m_b2Body->GetWorldCenter());
		
	}
	else if (m_bForwardTrustWasOn)
	{
		m_bForwardTrustWasOn = 0.0f;
		m_b2Body->SetLinearVelocity(b2Vec2(playerVelocity.x * 0.5f, playerVelocity.y /** 0.5f*/));
	}


	//	Pull down on player to give more natural jumping feel
	if (isMidAir /*&& playerVelocity.y <= 0*/)
	{
		//CCLog("Velocity: y: %f", playerVelocity.y);
		m_b2Body->ApplyLinearImpulse(b2Vec2(0, PLAYER_JUMP_PUSH), m_b2Body->GetWorldCenter());
	}

	//	Check and adjust player direction
	checkPlayerDirection(leftDown, rightDown);
}

void GameEntityPlayer::checkPlayerDirection(bool left, bool right)
{
	if (left && right); // do nothing if both directions on
	else if (left && direction == PlayerDirectionRight)
	{
		direction = PlayerDirectionLeft;
		this->m_skin->runAction(CCFlipX::create(true));
	}
	else if (right && direction == PlayerDirectionLeft)
	{
		direction = PlayerDirectionRight;
		this->m_skin->runAction(CCFlipX::create(false));
	}
}

bool GameEntityPlayer::isPlayerMidAir()
{
	bool midAir = true;

	if (!this->m_b2Body)
		return false;

	b2ContactEdge *con = this->m_b2Body->GetContactList();
	while (con)
	{		
		if (con->contact->IsTouching())
		{
			if (con->contact->GetFixtureA() == m_sensorFixture || con->contact->GetFixtureB() == m_sensorFixture)
			{
				midAir = false;
				break;
			}
		}
		con = con->next;
	}

	return midAir;
}

bool GameEntityPlayer::checkForDeath()
{
	//	check for death
	if (m_bPlayerDied)
		return true;

	if (this->isPlayerMidAir())
	{
		m_secondsInAir += 1/60.0f;
		if (m_secondsInAir >= IN_AIR_BEFORE_DEATH)
		{
			m_bPlayerDied = true;
			return true;
		}
	}
	else
		m_secondsInAir = 0;

	return false;
}