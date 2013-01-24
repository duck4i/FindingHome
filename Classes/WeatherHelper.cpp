#include "WeatherHelper.h"


short tweenColor(short start, short end)
{
	if (start == end)
		return end;
	else if (start > end)
		return max(start - 1, 0);
	else
		return min(start + 1, 255);
}


bool WeatherHelper::init()
{
	CCImage* controllerImage = new CCImage;	
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

	delete controllerImage;

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
	
	start = this->controller->pixelAt(ccp(controllerPosition, 1));
	//end = this->controller->pixelAt(ccp(controllerPosition, controller->getPixelsHigh() - 1));
}

void WeatherHelper::update(float delta)
{
	if (!initOK)
		return;

	updateTimer += delta;

	float actionInterval = 1.0f; // each seconds 1 pixel move. That means (for 380 width) complete cycle each ~6 minutes.
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

		this->background->setStartColor(ccc3(start.r, start.g, start.b));
		this->background->setStartOpacity(start.a);

		this->background->setEndColor(ccc3(start.r, start.g, start.b));
		this->background->setEndOpacity(start.a);

		//this->background->setEndColor(ccc3(end.r, end.g, end.b));
		//this->background->setEndOpacity(end.a);
	}

}