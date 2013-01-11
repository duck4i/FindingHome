#include "MainScene.h"




CCScene* MainScene::scene()
{
	CCScene* scene = CCScene::create();	

	MainScene *ms = MainScene::create();
	if (ms)
		scene->addChild(ms);

	return scene;
}

bool MainScene::init()
{	
	ccColor4B start = ccc4(80, 80, 180, 80);
	ccColor4B end = ccc4(80, 80, 180, 255);

	CCLayerGradient *gback = CCLayerGradient::create(start, end);		
	this->addChild(gback);

	whiteBox = CCLayerColor::create(ccc4(255, 255, 255, 255));
	whiteBox->setContentSize(CCSizeMake(100, 100));
	whiteBox->setPosition(ccp(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 50));

	this->addChild(whiteBox);

	//	process keydown	
	this->schedule(schedule_selector(MainScene::tickKeyboard));
	this->setKeypadEnabled(true);

	return true;
}

void MainScene::tickKeyboard(float delta)
{
	//CCLog("Tick keyboard");
	short l = GetKeyState(VK_LEFT);
	short r = GetKeyState(VK_RIGHT);
	short d = GetKeyState(VK_DOWN);
	short u = GetKeyState(VK_UP);

	short down = 0x8000; // hi bit
	short step = 5;

	float x = whiteBox->getPositionX();
	float y = whiteBox->getPositionY();
	
	if (l & down)	
		x -= step;	
	if (r & down)	
		x += step;	
	if (d & down)	
		y -= step;	
	if (u & down)	
		y += step;	

	whiteBox->setPosition(x, y);
}