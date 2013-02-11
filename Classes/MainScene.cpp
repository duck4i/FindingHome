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
	CCLayerColor::initWithColor(ccc4(0, 0, 0, 255));
	
	winSize = CCDirector::sharedDirector()->getWinSizeInPixels();	

	this->debugLayer = NULL;
	this->boxDebugKeyIsDown = false;
	this->player = NULL;
	this->playerBody = NULL;	
	this->boxWorld = NULL;	
	this->weather = NULL;
	this->totalTimeInAir = 0;

	direction = PlayerDirectionRight;	
	
	//	Create world layer
	this->worldLayer = CCLayer::create();	
	sceneScale = DEFAULT_SCALE;
	this->worldLayer->setScale(sceneScale);	
	this->addChild(worldLayer, 1000);

	//	add loading layer
	this->loadLayer = CCSprite::create(RESOURCE_LOADING);	
	loadLayer->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	this->addChild(loadLayer, 10000);

	//	load map after 1 second
	this->scheduleOnce(schedule_selector(MainScene::loadMap), 0.0f);	

	return true;
}

void MainScene::loadMap(float none)
{
	//	weather data
	this->weather = new WeatherHelper(this, this->worldLayer, WEATHER_CONTROLLER_DATA);	

	//	setup physics object 
	this->setupPhysics();
	this->addBodies();

	this->shiftSprite = CCSprite::create(RESOURCE_SHIFT);
	this->shiftSprite->setAnchorPoint(ccp(0, 0));
	this->shiftSprite->setPosition(ccp(10, 30));
	this->shiftSprite->setVisible(false);
	this->addChild(this->shiftSprite, 100000);

	//	schedule keyboard and touch events
	this->jumpKeyIsDown = false;
	this->disableKeyboard = false;
	this->setKeypadEnabled(true);

	this->touchesInProgress = false;

	//	schedule camera update
	if (this->player)
	{
		//	set rotation and friction damping and gravity scale
		this->playerBody->SetFixedRotation(true);
		this->playerBody->SetLinearDamping(0.5f);
		this->playerBody->SetGravityScale(2);

		this->cameraMoveInProgress = false;			
		
		CCPoint playerStart = this->worldLayer->convertToWorldSpace(player->getPosition());

		//	always start in (25%/25%) coordinates
		float twentyPercent = 0.25f;
		float xs = ( playerStart.x - (winSize.width * twentyPercent) ) * -1;
		float ys = ( playerStart.y - (winSize.height * twentyPercent) ) * -1;	
		this->worldLayer->setPosition(this->getPositionX() + xs, this->getPositionY() + ys);
		
		this->schedule(schedule_selector(MainScene::updateCamera));
	}

	//	schedule controls
	char* message = "[F1] Enable debug mode [F2] Reset camera [F4] Restart game [F7] Zoom in [F8] Zoom out [F9] Reset zoom";
	CCLabelTTF* lab = CCLabelTTF::create(message, "Arial", 18.0f);		
	lab->setPosition(ccp(CCDirector::sharedDirector()->getWinSizeInPixels().width / 2, CCDirector::sharedDirector()->getWinSizeInPixels().height - 15));
	this->addChild(lab, 100000);

	//	remove loading layer
	//this->loadLayer->removeFromParentAndCleanup(true);
	this->loadLayer->runAction(CCFadeTo::create(1.0f, 0));

	//	now do UPDATE schedule
	this->setTouchEnabled(true);
	this->scheduleUpdate();
}

void MainScene::setupPhysics()
{
	//	setup Physics
	const b2Vec2 gravity(0.0f, -10.0f);
	this->boxWorldSleep = true;

	this->boxWorld = new b2World(gravity);
	this->boxWorld->SetAllowSleeping(this->boxWorldSleep);
	this->boxWorld->SetContactListener(&this->worldListener);	
	
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
	char *level = "..\\Resources\\Level2.xml";
	extern char* commandLine;
	if (commandLine && strlen(commandLine))
		level = commandLine;

	LevelLoader l(this->worldLayer, level, this->boxWorld);
	if (l.parse())
	{
		this->playerBody = l.playerBody;
		this->player = l.playerNode;
		gamePlayer = l.player;
		return;
	}
	
#ifdef CC_PLATFORM_WIN32
	MessageBox(NULL, "Player object is not found in this level.", "How are you gona play?", MB_ICONWARNING | MB_OK);
#endif

}

void MainScene::toggleCameraProgress()
{
	this->cameraMoveInProgress = !this->cameraMoveInProgress;
}

void MainScene::updateCamera(float delta)
{	
	//CCLog("DELTA CAMERA: %f", delta);
	if (this->cameraMoveInProgress)
		return;
	
	CCPoint realPos = this->worldLayer->convertToWorldSpace(this->player->getPosition());
	CCPoint prevPos = this->worldLayer->getPosition();
	
	float margin = 0.35f;

#ifndef DISABLE_FLOAT_CAMERA
	float rightMargin = winSize.width / 2;//winSize.width - winSize.width * margin;
	float leftMargin = winSize.width / 2; //winSize.width * margin;
	float timeDelay = delta * 2;//delta /* / (1.0f / 60.0f)*/;
#else
	float rightMargin = winSize.width - winSize.width * margin;
	float leftMargin = winSize.width * margin;
	float timeDelay = 1;
#endif

	float topMargin = winSize.height - winSize.height * margin;
	float bottomMargin = winSize.height * 0.25;

	float xm = prevPos.x;
	float ym = prevPos.y;	

	if (realPos.x >= rightMargin)
		xm -= (realPos.x - rightMargin) * sceneScale * timeDelay;
	else if (realPos.x <= leftMargin)
		xm += (leftMargin - realPos.x) * sceneScale * timeDelay;

	if (realPos.y <= bottomMargin)
		ym += (bottomMargin - realPos.y) * sceneScale * timeDelay;
	else if (realPos.y >= topMargin)
		ym -= (realPos.y - topMargin) * sceneScale * timeDelay;
	
	this->worldLayer->setPosition(xm, ym);
}

void MainScene::updateKeyboard(float delta)
{
	if (disableKeyboard)
		return;

	KeyboardHelper *key = KeyboardHelper::sharedHelper();
	if (key->getF1() == KeyStateDown)
	{
		this->debugLayer->setVisible(!this->debugLayer->isVisible());
		CCDirector* d = CCDirector::sharedDirector();
		d->setDisplayStats(!d->isDisplayStats());
	}
	else if (key->getF4() == KeyStateDown)	
		playerDied();
	else if (key->getF7() == KeyStateDown)
		incSceneZoom();
	else if (key->getF8() == KeyStateDown)
		descSceneZoom();
	else if (key->getF9() == KeyStateDown)
		resetSceneZoom();
	else if (key->getF2() == KeyStateDown)
	{
		resetSceneZoom();
		this->cameraMoveInProgress = false;
	}

	//	shift key sprite
	if (key->getShift() == KeyStateDown)
	{
		if (!this->shiftSprite->isVisible())
			this->shiftSprite->setVisible(true);
	}
	else if (this->shiftSprite->isVisible())
		this->shiftSprite->setVisible(false);
}

void MainScene::update(float delta)
{
	//	Keyboard update
	updateKeyboard(delta);

	if (this->gamePlayer)
		gamePlayer->updatePlayerMovement();

	//	PHYSICS UPDATE
	updatePhysics(delta);
	
	//	And weather ofcourse
	if (weather)
		weather->update(delta);
}

void MainScene::updatePhysics(float delta)
{
	this->boxWorld->Step(BOX_WOLRD_STEP, BOX_WORLD_VELOCITY_PASSES, BOX_WORLD_POSITION_PASSES);

	for (b2Body* b = this->boxWorld->GetBodyList(); b; b = b->GetNext())
	{		
		GameEntity *userData = reinterpret_cast<GameEntity*> (b->GetUserData());
		if (userData)
		{
			userData->updatePosition(b->GetPosition());
			userData->updateRotation(b->GetAngle());
		}
	}
}

void MainScene::ccTouchesBegan(CCSet* touches, CCEvent* event)
{
	CCLog("Touches began");	
}

void MainScene::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
	CCLog("Touches ended");
	this->touchesInProgress = false;	
}

void MainScene::ccTouchesMoved(CCSet* touches, CCEvent* event)
{
#ifndef NO_MOUSE_MOVE

	CCLog("Touch moved");
	this->touchesInProgress = true;
	this->cameraMoveInProgress = true;

	CCTouch *t = (CCTouch*) touches->anyObject();
	if (!t)
		return;
	
	CCPoint loc = t->getLocationInView();
	CCPoint locPrev = t->getPreviousLocationInView();

	CCPoint diff = ccpSub(loc, locPrev);
	diff.y *= -1;
	this->worldLayer->setPosition(ccpAdd(this->worldLayer->getPosition(), diff));

#endif
}

void MainScene::setSceneZoom(float val)
{		
	if (!player || !worldLayer)
		return;

	CCPoint oldPos = this->worldLayer->convertToWorldSpace(player->getPosition());		
	CCPoint oldWPos = this->convertToWorldSpace(worldLayer->getPosition());

	this->worldLayer->setScale(this->sceneScale);

	CCPoint pos = this->worldLayer->convertToWorldSpace(player->getPosition());
	CCPoint wPos = this->convertToWorldSpace(worldLayer->getPosition());
	CCPoint worldPos = this->worldLayer->getPosition();
		
	CCPoint diff = ccpSub(pos, oldPos);
	CCPoint wDiff = ccpSub(wPos, oldWPos);
		
	this->worldLayer->setPosition(worldPos.x + diff.x, worldPos.y + diff.y);	
}

void MainScene::incSceneZoom()
{
	this->sceneScale += ZOOM_STEP;
	this->sceneScale = min(2.0f, this->sceneScale);
	setSceneZoom(this->sceneScale);
}

void MainScene::descSceneZoom()
{
	this->sceneScale -= ZOOM_STEP;
	this->sceneScale = max(0.005f, this->sceneScale);
	setSceneZoom(this->sceneScale);
}

void MainScene::resetSceneZoom()
{
	this->sceneScale = DEFAULT_SCALE;
	setSceneZoom(this->sceneScale);
}

void MainScene::playerDied()
{
	CCDirector::sharedDirector()->replaceScene(MainScene::scene());			
}

bool MainScene::isPlayerMidAir()
{
	if (!playerBody)
		return false;

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

	//	check for death
	if (midAir)
	{
		totalTimeInAir += 1/60.0f;
		if (totalTimeInAir >= IN_AIR_BEFORE_DEATH)
			playerDied();
	}
	else
		totalTimeInAir = 0;

	return midAir;
}