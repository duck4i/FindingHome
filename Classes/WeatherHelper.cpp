#include "WeatherHelper.h"
#include "Settings.h"

bool WeatherHelper::init()
{
	controllerImage = new CCImage;	
	if (!controllerImage->initWithImageFile(this->controllerPath))
	{
		CCLog("Error initializing weather image data");
		return false;
	}

	CCSize s = CCSizeMake(controllerImage->getWidth(), controllerImage->getHeight());
	controller = new CCTexture2DMutable;
	
	if (!controller->initWithData(controllerImage->getData(), kCCTexture2DPixelFormat_RGBA8888, s.width, s.height, s))
	{
		CCLog("Error creating mutable weather texture");
		delete controllerImage;
		return false;
	}

	//	now init layer
	this->background = CCLayerGradient::create();
	this->backgroundNext = CCLayerGradient::create();
	this->backgroundNext->setOpacity(0);

	//	now set position of controller	
	this->controllerPosition = random(0, this->controllerImage->getWidth() - 1);
	colorAtThisTime(lastStart, lastEnd);

	this->background->setStartColor(ccc3(lastStart.r, lastStart.g, lastStart.b));
	this->background->setEndColor(ccc3(lastEnd.r, lastEnd.g, lastEnd.b));
	
	this->parent->addChild(this->background);
	this->parent->addChild(this->backgroundNext);

	//	and now - stars
	this->createStarrySky();




	//	TV scan sprite? Not for long!
	CCSize winSize = CCDirector::sharedDirector()->getWinSizeInPixels();
	CCSprite *tv_scan = CCSprite::create("..\\Resources\\tv_scan.png");
	tv_scan->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	this->parent->addChild(tv_scan, 1000);


	//	My first shader lady and gentleman
	//TintShader *shader = TintShader::create();	
	//this->parent->addChild(shader, 100000);
	//shader->start(this->parent);

	return true;
}

void WeatherHelper::createStarrySky()
{
	char* starPath = STAR_PATH;
	CCTexture2D *tex = CCTextureCache::sharedTextureCache()->addImage(STAR_PATH);	
	CCSize sajz = CCDirector::sharedDirector()->getWinSizeInPixels();

	starrySky = CCSpriteBatchNode::create(STAR_PATH);
	starrySky->setTag(isNight() ? 100 : 0);

	int scale = 2;
	int numberOfMotherfuckers = random(150 * scale, 400 * scale);

	for (int i = 0; i < numberOfMotherfuckers; i++)
	{
		CCSprite *star = CCSprite::createWithTexture(tex);
		CCPoint pos = ccp(random(-sajz.width * scale, sajz.width * scale), random(-sajz.width * scale, sajz.height * scale));
		star->setPosition(pos);
		float scale = random(0.25, 0.85);
		star->setScale(scale);
		if (!isNight())
			star->setOpacity(0);

		//	color the small stars occasionally
		if (scale < 0.4)
		{
			int colR = random(0, 20);
			if (colR == 0)
				star->setColor(ccc3(145, 212, 255));
			else if (colR == 5)
				star->setColor(ccc3(226, 181, 160));
			else if (colR == 10)
				star->setColor(ccc3(105, 91, 135));
		}

		//this->parent->addChild(star);
		starrySky->addChild(star);
	}
	
	this->parent->addChild(starrySky);
}

void WeatherHelper::colorAtThisTime(ccColor4B &start, ccColor4B &end)
{
	if (!this->controller)
		return;
	
	start = this->controller->pixelAt(ccp(controllerPosition, 0));	
	end = this->controller->pixelAt(ccp(controllerPosition, controller->getPixelsHigh() - 1));
}

bool WeatherHelper::isNight()
{
	//float margin = 32;
	//return this->controllerPosition <= margin || this->controllerPosition >= (unsigned int) (this->controllerImage->getWidth() - margin) ;
	int index = getColorPercivedBrigthness(lastStart.r, lastStart.g, lastStart.b);
	bool night = index <= 60;
	return night;
}

int WeatherHelper::tintStrengthAtThisTime(ccColor3B c)
{	
	return 255;
	if (isNight())
		return 160;	//	fix for nights

	int colorBrightness = getColorPercivedBrigthness(c.r, c.g, c.b);
	
	//	min 20, max 130
	int ret = min(80, max(255 - colorBrightness, 20));
	return ret;
}

ccColor3B WeatherHelper::tintColorAtThisTime()
{	
	if (isNight())
		return ccc3(lastStart.r, lastStart.g, lastStart.b);

	ccColor3B c;
	//if (controllerPosition > (unsigned int)(controllerImage->getWidth() / 2) )
	//	c = ccc3(lastStart.r, lastStart.g, lastStart.b);
	//else
		c = ccc3(lastEnd.r, lastEnd.g, lastEnd.b);
	return c;
}

int WeatherHelper::getColorPercivedBrigthness(int r, int g, int b)
{
	float ret = 
		r * r * 0.241f +
		g * g * 0.691f +
		b * b * 0.068f;	
	return (int) sqrtf(ret);
}

void WeatherHelper::update(float delta)
{
	if (!initOK)
		return;

	updateTimer += delta;
	if (updateTimer >= ACTION_INTERVAL)
	{	
		updateTimer = 0;

		this->starrySkyNaturalRotation.x += STARS_NATURAL_DROP;
		this->starrySkyNaturalRotation.y += STARS_NATURAL_DROP;

		if (backgroundChanging) // thats it
			return;

		this->controllerPosition++;
		firstUpdate = false;

		//	reset when came to the end
		if (this->controllerPosition >= this->controller->getPixelsWide())
		{
			this->controllerPosition = 0;
			return;
		}

		ccColor4B start, end;
		colorAtThisTime(start, end);

		if (!ccc4BEqual(lastStart, start) || !ccc4BEqual(lastEnd, end))
		{
			backgroundChanging = true;			

			this->backgroundNext->setStartColor(ccc3(start.r, start.g, start.b));
			this->backgroundNext->setEndColor(ccc3(end.r, end.g, end.b));			

			CCFadeIn *in = CCFadeIn::create(CHANGE_SPEED);
			CCCallFunc *done = CCCallFunc::create(this, callfunc_selector(WeatherHelper::backgroundDoneChanging));

			this->backgroundNext->runAction(CCSequence::createWithTwoActions(in, done));
			
			lastStart = start;
			lastEnd = end;
			
			ccColor3B col = tintColorAtThisTime();		
		}
	}

	//	update stars position
	if (isNight())
	{
		CCPoint pos = this->worldLayer->getPosition();
		float divider = 50;
		float factorX = (pos.x / divider) - starrySkyNaturalRotation.x;
		float factorY = (pos.y / divider) - starrySkyNaturalRotation.y;		
		this->starrySky->setPosition(factorX, factorY);

		if (starrySky->getTag() == 0)
		{			
			flipStarVisibility();
			starrySky->setTag(100);
		}
	}
	else if (starrySky->getTag() == 100)
	{		
		flipStarVisibility();
		starrySky->setTag(0);
	}
}

void WeatherHelper::flipStarVisibility()
{
	bool show = starrySky->getTag() == 0;
	for (int i = 0; i < starrySky->getChildrenCount(); i++)
	{
		CCSprite* s = (CCSprite*) starrySky->getChildren()->objectAtIndex(i);
		float ran = random(STARS_FADE_SPEED * 0.2f, STARS_FADE_SPEED);
		if (show)
			s->runAction(CCFadeIn::create(ran));
		else
			s->runAction(CCFadeOut::create(ran));
	}
}

void WeatherHelper::backgroundDoneChanging()
{		
	this->background->setStartColor(this->backgroundNext->getStartColor());
	this->background->setEndColor(this->backgroundNext->getEndColor());	
	this->backgroundNext->setOpacity(0);

	backgroundChanging = false;	
}