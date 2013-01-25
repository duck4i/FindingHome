#include "WeatherHelper.h"


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
	//this->controllerPosition = controller->getPixelsWide() / 2;
	//this->background->setCompressedInterpolation(true);	
	colorAtThisTime(lastStart, lastEnd);	
			
	this->background->setStartColor(ccc3(lastStart.r, lastStart.b, lastStart.g));
	this->background->setEndColor(ccc3(lastEnd.r, lastEnd.g, lastEnd.b));

	this->parent->addChild(this->background);
	this->parent->addChild(this->backgroundNext);

	//	tinting layer
	this->topTintLayer = CCLayerColor::create(ccc4(lastStart.r, lastStart.g, lastStart.b, tintStrengthAtThisTime()));
	this->parent->addChild(this->topTintLayer, 10000);

	return true;
}

void WeatherHelper::colorAtThisTime(ccColor4B &start, ccColor4B &end)
{
	if (!this->controller)
		return;
	
	start = this->controller->pixelAt(ccp(controllerPosition, 0));	
	end = this->controller->pixelAt(ccp(controllerPosition, controller->getPixelsHigh() - 1));
}

int WeatherHelper::tintStrengthAtThisTime()
{
	ccColor4B c;
	if (controllerPosition > controllerImage->getWidth() / 2)
		c = lastStart;
	else
		c = lastEnd;

	int colorBrightness = getColorPercivedBrigthness(c.r, c.g, c.b);
		
	//	min 20, max 130
	int ret = min(130, max(255 - colorBrightness, 20));
	return ret;
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

	float actionInterval = 0.10f; // each seconds 1 pixel move. That means (for 380 width) complete cycle each ~6 minutes.	

	if ( !backgroundChanging &&  (updateTimer >= actionInterval || firstUpdate) )
	{
		updateTimer = 0;
		this->controllerPosition++;
		firstUpdate = false;

		//	reset when came to the end
		if (this->controllerPosition >= this->controller->getPixelsWide())
		{
			this->controllerPosition = 0;
			this->updateTimer = 0;
			return;
		}

		ccColor4B start, end;
		colorAtThisTime(start, end);

		if (!ccc4BEqual(lastStart, start) || !ccc4BEqual(lastEnd, end))
		{
			float changeTime = 10.0f;
			this->backgroundNext->setOpacity(0);
			this->backgroundNext->setStartColor(ccc3(start.r, start.b, start.g));
			this->backgroundNext->setEndColor(ccc3(end.r, end.g, end.b));

			CCFadeTo *in = CCFadeTo::create(changeTime, 255);
			CCFadeTo *out = CCFadeTo::create(changeTime, 0);
			CCTintTo *tint = CCTintTo::create(changeTime, start.r, start.g, start.b);
			int ts = tintStrengthAtThisTime();
			CCFadeTo *tintStrength = CCFadeTo::create(changeTime, ts);

			CCCallFunc *done = CCCallFunc::create(this, callfunc_selector(WeatherHelper::backgroundDoneChanging));

			this->backgroundNext->runAction(CCSequence::createWithTwoActions(in, done));
			this->background->runAction(out);
			
			this->topTintLayer->runAction(tint);
			this->topTintLayer->runAction(tintStrength);

			backgroundChanging = true;

			lastStart = start;
			lastEnd = end;
		}
	}
}

void WeatherHelper::backgroundDoneChanging()
{	
	this->background->stopAllActions();
	this->background->setStartColor(this->backgroundNext->getStartColor());
	this->background->setEndColor(this->backgroundNext->getEndColor());
	this->background->setOpacity(255);
	this->backgroundNext->setOpacity(0);

	backgroundChanging = false;	
}