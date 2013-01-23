#include "MainScene.h"

short backgroundAlphaStart = 80;
short backgroundAlphaEnd = 255;

short backgroundMatrix[][3] = 
{ 	
	{134, 193, 253},	//day
	{255, 201, 14},		//sunset
	{80, 80, 180}		//night
};

CCScene* MainScene::scene()
{
	CCScene* scene = CCScene::create();	

	MainScene *ms = MainScene::create();
	if (ms)
		scene->addChild(ms);

	return scene;
}

MainScene::~MainScene()
{
	CCLog("MainScene destructor called");
	if (boxWorld)
		delete boxWorld;	
}

bool MainScene::init()
{
	lastUsedBackgroundIndex = 0;
	firstBackgroundChange = true;
	backgroundTimer = NULL;
	gback = CCLayerGradient::create(
		ccc4(backgroundMatrix[0][0], backgroundMatrix[0][1], backgroundMatrix[0][2], backgroundAlphaStart), 
		ccc4(backgroundMatrix[0][0], backgroundMatrix[0][1], backgroundMatrix[0][2], backgroundAlphaEnd)
		);
	this->addChild(gback);
		
	this->debugLayer = NULL;
	this->lastKeyboardUpdate = 0;

	this->player = NULL;
	this->playerBody = NULL;

	direction = PlayerDirectionRight;
	
	//	Create world layer
	this->worldLayer = CCLayer::create();		

	sceneScale = DEFAULT_SCALE;
	this->worldLayer->setScale(sceneScale);
	this->addChild(worldLayer);

	//	setup physics object
	this->setupPhysics();
	this->addBodies();

	this->scheduleUpdate();
	this->schedule(schedule_selector(MainScene::updateBackground));	

	if (this->player)
	{
		this->cameraMoveInProgress = false;	
		CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();
		CCPoint playerStart = this->worldLayer->convertToWorldSpace(player->getPosition());

		//	always start in (20%/20%) coordinates
		float twentyPercent = 0.25f;
		float xs = ( playerStart.x - (size.width * twentyPercent) ) * -1;
		float ys = ( playerStart.y - (size.height * twentyPercent) ) * -1;				
		this->worldLayer->runAction(CCMoveBy::create(0.0f, ccp(xs, ys)));
	
		this->schedule(schedule_selector(MainScene::updateCamera));
		this->cameraScheduled = true;		
	}

	this->setKeypadEnabled(true);

	this->touchesInProgress = false;
	this->setTouchEnabled(true);

	return true;
}

void MainScene::toggleCameraProgress()
{
	this->cameraMoveInProgress = !this->cameraMoveInProgress;
}

void MainScene::updateCamera(float delta)
{
	if (this->touchesInProgress)
	{
		unschedule(schedule_selector(MainScene::updateCamera));
		this->cameraScheduled = false;
		return;
	}
	else if (this->cameraMoveInProgress)
		return;

	CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();
	CCPoint realPos = this->worldLayer->convertToWorldSpace(this->player->getPosition());
	CCPoint pos = this->player->getPosition();

	float rCol = size.width - realPos.x;
	float twentyPercent = size.width * 0.2f;
	float nx = 0, ny = 0;
	float margin = 0;

	if (realPos.x <= twentyPercent) 
	{
		nx = ((size.width - twentyPercent) - realPos.x) - margin;		
	}
	else if (rCol <= twentyPercent)
	{
		nx = -1 * (realPos.x - twentyPercent) + margin;
	}

	float twentyPercentHeight = size.height * 0.2f;
	if (realPos.y <= twentyPercentHeight)
	{
		ny = size.height - twentyPercent - margin;
	}

	//if (

	//	do actual moving
	if (nx != 0 || ny != 0)
	{
		this->cameraMoveInProgress = true;
		CCFiniteTimeAction *move = CCEaseInOut::create(CCMoveBy::create(1.0f, ccp(nx, ny)), 1.0f);
		CCCallFunc *reset = CCCallFunc::create(this, callfunc_selector(MainScene::toggleCameraProgress));
		
		CCSequence *s = CCSequence::createWithTwoActions(move, reset);
		this->worldLayer->runAction(s);
	}

	bool ok = true;

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
	
	long down = 0x8000; // hi bit
	short step = 30.0f;

	//	Update player movement
	if (playerBody)
	{
		short l = GetKeyState(VK_LEFT);
		short r = GetKeyState(VK_RIGHT);
		short d = GetKeyState(VK_DOWN);
		short u = GetKeyState(VK_UP);

		float x = 0;
		float y = 0;
	
		if (l & down)
			x -= step;	
		if (r & down)	
			x += step;	
		//if (d & down)	
		//	y -= step;	
		if ((u & down) || (u2 & down))	
			y += step;		

		b2Vec2 vel = playerBody->GetLinearVelocity();
		bool midAir = abs(vel.y) >= 0.01f;
		bool topSpeed = abs(vel.x) >= 5.0f;

		if (y && !midAir)
			playerBody->ApplyLinearImpulse(b2Vec2(0, step), playerBody->GetWorldCenter());
		if (x && !midAir && !topSpeed)
			playerBody->ApplyForce(b2Vec2(x, 0), playerBody->GetWorldCenter());	
			//playerBody->ApplyLinearImpulse(b2Vec2(x, 0), playerBody->GetWorldCenter());
	
		//	Check player direction
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
	
	if (cameraContinue & down )
	{
		if (!this->cameraScheduled)
		{
			this->schedule(schedule_selector(MainScene::updateCamera));
			this->cameraScheduled = true;

			if (sceneScale != DEFAULT_SCALE)
			{
				this->worldLayer->setScale(DEFAULT_SCALE);
				this->sceneScale = DEFAULT_SCALE;
			}
		}
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

}

short tweenColor(short start, short end)
{
	if (start == end)
		return end;
	else if (start > end)
		return max(start - 1, 0);
	else
		return min(start + 1, 255);
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
}

void MainScene::updateBackground(float delta)
{
	//	update background color
	short timeToChange = 15;
	backgroundTimer += delta;
	//CCLog("Background timer %f", backgroundTimer);

	if (backgroundTimer >= timeToChange)
	{
		if (!firstBackgroundChange)
			lastUsedBackgroundIndex++;
		if (lastUsedBackgroundIndex > 2)
			lastUsedBackgroundIndex = 0;
		backgroundTimer = 0;
		firstBackgroundChange = false;
	}

	if (!firstBackgroundChange)
	{
		ccColor3B currentColor = gback->getStartColor();
		ccColor3B nextColor = lastUsedBackgroundIndex < 2 ? 
			ccc3(backgroundMatrix[lastUsedBackgroundIndex + 1][0], backgroundMatrix[lastUsedBackgroundIndex + 1][1], backgroundMatrix[lastUsedBackgroundIndex + 1][2])
			:
			ccc3(backgroundMatrix[0][0], backgroundMatrix[0][1], backgroundMatrix[0][2]);

		short r = tweenColor(currentColor.r, nextColor.r);
		short g = tweenColor(currentColor.g, nextColor.g);
		short b = tweenColor(currentColor.b, nextColor.b);
	
		ccColor3B newColor = ccc3(r, g, b);
		gback->setStartColor(newColor);
		gback->setEndColor(newColor);
	}
}

void MainScene::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	CCLog("Touches began");
	this->touchesInProgress = true;
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
