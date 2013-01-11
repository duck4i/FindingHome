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
	
	whiteBox = CCLayerColor::create(ccc4(255, 255, 255, 255));
	whiteBox->setContentSize(CCSizeMake(100, 100));
	whiteBox->setPosition(ccp(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 - 50));

	this->addChild(whiteBox);

	blackBox = CCLayerColor::create(ccc4(0, 0, 0, 255));
	blackBox->setContentSize(CCSizeMake(WINDOW_WIDTH, 50));
	blackBox->setPosition(ccp(0, 0));
	blackBox->setAnchorPoint(ccp(0, 0));
	this->addChild(blackBox);

	//	process keydown	
	this->schedule(schedule_selector(MainScene::tickKeyboard));
	this->setKeypadEnabled(true);

	this->scheduleUpdate();
	this->schedule(schedule_selector(MainScene::tickBackground));

	return true;
}

void MainScene::tickKeyboard(float delta)
{
	//CCLog("Tick keyboard");
	short l = GetKeyState(VK_LEFT);
	short r = GetKeyState(VK_RIGHT);
	short d = GetKeyState(VK_DOWN);
	short u = GetKeyState(VK_UP);

	long down = 0x8000; // hi bit
	short step = 5;

	float x = whiteBox->getPositionX();
	float y = whiteBox->getPositionY();
	
	if (l & down)	
		x -= step;	
	if (r & down)	
		x += step;	
	if (d & down && y > blackBox->getContentSize().height)	
		y -= step;	
	if (u & down)	
		y += step;	

	whiteBox->setPosition(x, y);
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
	short gravity = 4;

	CCPoint pos = whiteBox->getPosition();

	if (pos.y > blackBox->getContentSize().height)
	{
		pos.y -= gravity;
		whiteBox->setPosition(pos);	
	}
}

void MainScene::tickBackground(float delta)
{
	//	update background color
	short timeToChange = 15;
	backgroundTimer += delta;
	CCLog("Background timer %f", backgroundTimer);

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