#include "GameEntityPlayer.h"

bool GameEntityPlayer::init()
{
	CCTextureCache *cache = CCTextureCache::sharedTextureCache();
	CCTexture2D *player1 = cache->addImage(RESOURCE_PLAYER);
		
	m_animationStill = CCAnimation::create();
	m_animationStill->addSpriteFrameWithFileName(RESOURCE_PLAYER);
	m_animationStill->addSpriteFrameWithFileName(RESOURCE_PLAYER2);
	m_animationStill->addSpriteFrameWithFileName(RESOURCE_PLAYER3);
	m_animationStill->addSpriteFrameWithFileName(RESOURCE_PLAYER4);
	m_animationStill->setDelayPerUnit(0.2f);	

	CCAction* a = CCRepeatForever::create(CCAnimate::create(m_animationStill));	

	m_skin = CCSprite::createWithTexture(player1);
	if (!m_skin)
		return false;

	//m_skin->setBlendFunc( (ccBlendFunc){GL_ONE, GL_ZERO} ); 
	
	m_skin->runAction(a);

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
	
	m_b2FixtureDef.density = 3.0f;
	m_b2FixtureDef.friction = 0.8f;
	m_b2FixtureDef.restitution = 0;
	m_b2FixtureDef.shape = &doggyShape;	
	m_b2FixtureDef.filter.categoryBits = 0x0002;
	//m_b2FixtureDef.filter.maskBits = 0x0004;	//	filter out collectables

	m_b2Body->CreateFixture(&m_b2FixtureDef);
			
	b2FixtureDef groundBody;
	b2PolygonShape groundBodyShape;
	
	playerSize.height += 60;	//	more than player size - so it goes into ground
	groundBodyShape.SetAsBox(SCREEN_TO_WORLD(playerSize.width / 2), SCREEN_TO_WORLD(playerSize.height / 2));

	groundBody.isSensor = true;
	groundBody.shape = &groundBodyShape;

	m_b2Body->CreateFixture(&groundBody);

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

void GameEntityPlayer::updatePlayerMovement()
{
	KeyboardHelper *key = KeyboardHelper::sharedHelper();
	float x = 0;
	float y = 0;

	bool leftDown = key->getLeft() == KeyStateDown;
	bool rightDown = key->getRight() == KeyStateDown;
				
	if (leftDown)
		x -= PLAYER_STEP_VALUE;
	if (rightDown)
		x += PLAYER_STEP_VALUE;

	if (key->getUp() == KeyStateDown)
		y += PLAYER_JUMP_VALUE;

	float isMidAir = isPlayerMidAir();
	if (x || y)
	{
		//	
		//	Calculate and apply forces for movement
		//
		b2Vec2 vel = m_b2Body->GetLinearVelocity();

		//	http://www.box2d.org/forum/viewtopic.php?f=3&t=4733
		//	http://www.ikbentomas.nl/other/box2d/
		//	http://www.cocos2d-iphone.org/forum/topic/13501				

		float maxSpeed = PLAYER_SPEED;
		const b2Vec2 velocity = m_b2Body->GetLinearVelocity();

		//	no more jumping and only slight adjustment of direction when in air			
		if (isMidAir)
		{
			x *= PLAYER_MID_AIR_FACTOR;
			y = 0;	//	no jumping when mid air
		}
		
		///
		///	Shift button feature
		///
		if (key->getShift() == KeyStateDown)
		{
			x *= PLAYER_SHIFT_FACTOR;
			maxSpeed *= PLAYER_SHIFT_FACTOR;
			y *= PLAYER_SHIFT_FACTOR;
		}

		//	apply horizontal force - take care of max velocity
		const float speed = abs(velocity.x);
		if (speed >= maxSpeed)
			x = 0;
				
		m_b2Body->ApplyLinearImpulse(b2Vec2(x, y), m_b2Body->GetWorldCenter());
	}

	//	in any case constrol the jump velocity to look more real
	b2Vec2 vel = this->m_b2Body->GetLinearVelocity();
	if (vel.y <= 0)
	{
		vel.y -= 0.2f;
		this->m_b2Body->SetLinearVelocity(vel);
	}

	//	Check player direction
	if (leftDown && rightDown); // do nothing if both directions on
	else if (key->getLeft() == KeyStateDown && direction == PlayerDirectionRight)
	{
		direction = PlayerDirectionLeft;
		this->m_skin->runAction(CCFlipX::create(true));
	}
	else if (key->getRight() == KeyStateDown && direction == PlayerDirectionLeft)
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
			midAir = false;
			break;
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