#include "MainScene.h"


CCScene* MainScene::scene()
{
	CCScene* scene = CCScene::create();	

	MainScene *ms = MainScene::create();
	if (scene && ms)
		scene->addChild(ms);

	return scene;
}

MainScene::~MainScene()
{
	CCLog("MainScene destructor called");
	if (boxWorld)
		delete boxWorld;	
	if (weather)
		delete weather;	
}

bool MainScene::init()
{	
	//	this->initWithColor(ccc4(100, 149, 237, 255));	//	cornflower blue
	this->initWithColor(ccc4(0, 0, 0, 255));	//	

	this->debugLayer = NULL;
	this->lastKeyboardUpdate = 0;

	this->player = NULL;
	this->playerBody = NULL;
	this->weather = NULL;

	direction = PlayerDirectionRight;

	//this->addChild(CCLayerColor::create(ccc4(255, 255, 255, 255)), 1);
	
	//	Create world layer
	this->worldLayer = CCLayer::create();
	this->weather = new WeatherHelper(this, this->worldLayer, WEATHER_CONTROLLER_DATA);

	sceneScale = DEFAULT_SCALE;
	this->worldLayer->setScale(sceneScale);
	this->addChild(worldLayer);

	//	setup physics object
	this->setupPhysics();
	this->addBodies();	

	//	schedule keyboard and touch events
	this->jumpKeyIsDown = false;
	this->disableKeyboard = false;
	this->setKeypadEnabled(true);

	this->touchesInProgress = false;
	this->setTouchEnabled(true);

	this->scheduleUpdate();

	//	schedule camera update
	if (this->player)
	{
		this->playerBody->SetFixedRotation(true);
		this->cameraMoveInProgress = false;	
		CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();
		CCPoint playerStart = this->worldLayer->convertToWorldSpace(player->getPosition());

		//	always start in (20%/20%) coordinates
		float twentyPercent = 0.25f;
		float xs = ( playerStart.x - (size.width * twentyPercent) ) * -1;
		float ys = ( playerStart.y - (size.height * twentyPercent) ) * -1;	
		this->worldLayer->setPosition(this->getPositionX() + xs, this->getPositionY() + ys);		
	
		this->schedule(schedule_selector(MainScene::updateCamera));	
	}


	return true;
}

void MainScene::toggleCameraProgress()
{
	this->cameraMoveInProgress = !this->cameraMoveInProgress;
}

void MainScene::updateCamera(float delta)
{	
	if (this->cameraMoveInProgress)
		return;

	CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();
	CCPoint realPos = this->worldLayer->convertToWorldSpace(this->player->getPosition());
	CCPoint prevPos = this->worldLayer->getPosition();
	
	float margin = 0.35f;
	float rightMargin = size.width - size.width * margin;
	float leftMargin = size.width * margin;

	float topMargin = size.height - size.height * margin;
	float bottomMargin = size.height * margin;

	float xm = prevPos.x;
	float ym = prevPos.y;

	if (realPos.x >= rightMargin)
		xm -= (realPos.x - rightMargin) * sceneScale;
	else if (realPos.x <= leftMargin)
		xm += (leftMargin - realPos.x) * sceneScale;

	if (realPos.y <= bottomMargin)
		ym += (bottomMargin - realPos.y) * sceneScale;
	else if (realPos.y >= topMargin)
		ym -= (realPos.y - topMargin) * sceneScale;
	
	this->worldLayer->setPosition(xm, ym);
}


void MainScene::setupPhysics()
{
	//	setup Physics
	const b2Vec2 gravity(0.0f, -10.0f);
	this->boxWorldSleep = true;

	this->boxWorld = new b2World(gravity);
	this->boxWorld->SetAllowSleeping(this->boxWorldSleep);			
	
	//	setup debug drawing	
	if (true)
	{
		this->debugLayer = B2DebugDrawLayer::create(this->boxWorld, PTM_RATIO);
		this->debugLayer->setVisible(false);
		this->worldLayer->addChild(this->debugLayer, 9999);	
	}
}

void MainScene::addBodies()
{
	//	load level
	LevelLoader l(this->worldLayer, "..\\Resources\\Level1.xml", this->boxWorld);
	if (l.parse())
	{		
		this->playerBody = l.playerBody;
		this->player = l.playerNode;

		//CCAssert(this->player, "Player buddy missing?");

		if (this->player)
		{			
			CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();
			CCPoint pos = this->player->getPosition();
		}

		return;
	}
		
	MessageBox(NULL, "Player object is not found in this level.", "How are you gona play?", MB_ICONWARNING | MB_OK);

}

float lastk = 0;
void MainScene::updateKeyboard(float delta)
{
	if (disableKeyboard)
		return;

	//	set interval between keys
	lastk += delta;
	if (lastk >= 0.02f)	
		lastk = 0;	
	else
		return;

	//CCLog("Tick keyboard");
	short u2 = GetKeyState(VK_SPACE);
	short f1 = GetKeyState(VK_F1);

	short zoomIn = GetKeyState(VK_OEM_PLUS);
	short zoomOut = GetKeyState(VK_OEM_MINUS);
	short zoomReset = GetKeyState(VK_BACK);	

	short cameraContinue = GetKeyState(VK_F2);
	short restart = GetKeyState(VK_F4);
	
	long down = 0x8000; // hi bit

	//	Update player movement
	if (playerBody)
	{		
		short l = GetKeyState(VK_LEFT);
		short r = GetKeyState(VK_RIGHT);
		short d = GetKeyState(VK_DOWN);
		short u = GetKeyState(VK_UP);
		short shift = GetKeyState(VK_LSHIFT);

		bool jumped = (u & down) || (u2 & down) ;

		bool skipY = false;
		if (jumped && jumpKeyIsDown)
			skipY = true;
		else if (jumped)
			jumpKeyIsDown = true;
		else if (!jumped)
			jumpKeyIsDown = false;

		float x = 0;
		float y = 0;
	
		if (l & down)
			x -= DOG_STEP_VALUE;	
		else if (r & down)
			x += DOG_STEP_VALUE;
		
		if (jumped && !skipY)
			y += DOG_JUMP_VALUE;

		//	check if anything to do
		if (x || y)
		{
			//	
			//	Calculate and apply forces for movement
			//
			b2Vec2 vel = playerBody->GetLinearVelocity();

			//	http://www.box2d.org/forum/viewtopic.php?f=3&t=4733
			//	http://www.ikbentomas.nl/other/box2d/
			//	http://www.cocos2d-iphone.org/forum/topic/13501
		
			//	check if any contacts
			bool midAir = true;
			b2ContactEdge *con = playerBody->GetContactList();
			while (con)
			{
				if (con->contact->IsTouching())
				{
					midAir = false;
					break;
				}
				con = con->next;
			}

			//	no more jumping and only slight adjustment of direction when in air
			if (midAir)
			{
				y = 0;
				x *= DOG_MID_AIR_FACTOR;
			}

			float maxSpeed = DOG_SPEED;
			if (shift & down && !midAir)
			{
				x *= DOG_SHIFT_FACTOR;
				maxSpeed *= DOG_SHIFT_FACTOR;
				y *= DOG_SHIFT_FACTOR;
			}			

			playerBody->ApplyLinearImpulse(b2Vec2(x, y), playerBody->GetWorldCenter());

			//
			//	limit top velocity
			//
			const b2Vec2 velocity = playerBody->GetLinearVelocity();
			const float speed = abs(velocity.x);			
			if (speed > maxSpeed)
				playerBody->SetLinearVelocity((maxSpeed / speed) * velocity);
		

			//	Check player direction
			/*
			if (x < 0 && direction == PlayerDirectionRight)
			{
				direction = PlayerDirectionLeft;
				player->runAction(CCFlipX::create(true));
			}
			else if (x > 0 && direction == PlayerDirectionLeft)
			{
				direction = PlayerDirectionRight;
				player->runAction(CCFlipX::create(false));
			}		
			*/
		}
	}

	//	now check for scaling keys
	float scaleStep = 0.01f;
	if (zoomIn & down)
	{		
		this->sceneScale += scaleStep;
		this->worldLayer->setScale(sceneScale);
	}
	else if (zoomOut & down)
	{		
		this->sceneScale -= scaleStep;
		this->sceneScale = max(this->sceneScale, 0.01f); // no less than 0.01
		this->worldLayer->setScale(sceneScale);
	}
	else if (zoomReset & down)
	{		
		this->sceneScale = DEFAULT_SCALE;
		this->worldLayer->setScale(this->sceneScale);		
	}
	
	//	Continue camera and reset scale
	if (cameraContinue & down && this->cameraMoveInProgress)
	{
		this->cameraMoveInProgress = false;
		this->sceneScale = DEFAULT_SCALE;
		this->worldLayer->setScale(this->sceneScale);	
	}

	//	now check for box2D debug, the code bellow acts like WM_KEYUP
	{
		if (f1 & down)
		{
			//	not too fast
			lastKeyboardUpdate += delta;
		}
		else if (lastKeyboardUpdate != 0)
		{			
			this->debugLayer->setVisible(!this->debugLayer->isVisible());			
			lastKeyboardUpdate = 0;
		}
	}

	//	now restart	
	if (restart & down)
	{
		if (!restartKeyIsDown)									
		{
			CCScene* s = CCTransitionFade::create(3.0f, MainScene::scene());
			CCDirector::sharedDirector()->replaceScene(s);
			restartKeyIsDown = true;
		}
	}
	else if (restartKeyIsDown)
		restartKeyIsDown = false;

}

void MainScene::update(float delta)
{
	//	PHYSICS UPDATE FIRST	
	this->boxWorld->Step(BOX_WOLRD_STEP, BOX_WORLD_VELOCITY_PASSES, BOX_WORLD_POSITION_PASSES);	

	for (b2Body* b = this->boxWorld->GetBodyList(); b; b = b->GetNext())
	{
		CCSprite* s = (CCSprite*) b->GetUserData();
		
		if (s != NULL)
		{
			b2Vec2 pos = b->GetPosition();			
			CCPoint posRecalc = ccp(WORLD_TO_SCREEN(pos.x), WORLD_TO_SCREEN(pos.y));			
			s->setPosition(posRecalc);
			s->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
		}
	}

	//	Now keyboard update
	updateKeyboard(delta);

	//	And weather ofcourse
	if (weather)
		weather->update(delta);
}

void MainScene::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	CCLog("Touches began");
	this->touchesInProgress = true;
	this->cameraMoveInProgress = true;
}

void MainScene::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	CCLog("Touches ended");
	this->touchesInProgress = false;	
}

void MainScene::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
	CCLog("Touch moved");
	CCTouch *t = (CCTouch*) touches->anyObject();
	if (!t)
		return;
	
	CCPoint loc = t->getLocationInView();
	CCPoint locPrev = t->getPreviousLocationInView();

	CCPoint diff = ccpSub(loc, locPrev);
	diff.y *= -1;
	this->worldLayer->setPosition(ccpAdd(this->worldLayer->getPosition(), diff));
	//this->debugLayer->setPosition
}