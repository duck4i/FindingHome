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

	//	now set position of controller
	//this->controllerPosition = controller->getPixelsWide() / 2;

	//	now init layer	
	this->background = CCLayerGradient::create();
	this->parent->addChild(this->background);

	return true;
}

void WeatherHelper::colorAtThisTime(ccColor4B &start, ccColor4B &end)
{
	if (!this->controller)
		return;
	
	start = this->controller->pixelAt(ccp(controllerPosition, 0));	
	end = this->controller->pixelAt(ccp(controllerPosition, controller->getPixelsHigh() - 1));
}

void WeatherHelper::update(float delta)
{
	if (!initOK)
		return;

	updateTimer += delta;

	float actionInterval = 0.10f; // each seconds 1 pixel move. That means (for 380 width) complete cycle each ~6 minutes.
	if (updateTimer >= actionInterval || firstUpdate)
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

		//ccc4FEqual

		/*if (start != prevStart || end != prevEnd)
		{
		}*/

		this->background->setStartColor(ccc3(start.r, start.g, start.b));
		this->background->setEndColor(ccc3(end.r, end.g, end.b));						
	}

	//	if tweening needed then do it, first pass is layer start
	if (stepR != 0 || stepG != 0 || stepB != 0) 
	{
		ccColor3B c = this->background->getStartColor();
		c.r += stepR; c.g += stepG; c.b += stepB;
		this->background->setStartColor(c);
	}

	//	now gradient stop
	if (stepR != 0 || stepG != 0 || stepB != 0)
	{
		ccColor3B c = this->background->getEndColor();
		c.r += stepR2; c.g += stepG2; c.b += stepB2;
		this->background->setEndColor(c);
	}

}

bool WeatherHelper::colorsEqual(ccColor4B a, ccColor4B b)
{
	return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;
}