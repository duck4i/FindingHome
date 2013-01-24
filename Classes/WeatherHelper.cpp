#include "WeatherHelper.h"

ccColor4B WeatherHelper::getColorFromPixel(CCSprite* sprite, float x, float y)
{
	ccColor4B c;
	c.r = c.g = c.b = c.a = 0;

	if (!sprite)
		return c;
	
	unsigned int data[4] = {0};
	CCPoint loc = ccp(x * CC_CONTENT_SCALE_FACTOR(), y * CC_CONTENT_SCALE_FACTOR());
	CCSize size = CCSizeMake(sprite->getContentSize().width * CC_CONTENT_SCALE_FACTOR(), sprite->getContentSize().height * CC_CONTENT_SCALE_FACTOR());
	
	CCRenderTexture *t = CCRenderTexture::create(size.width, size.height, kCCTexture2DPixelFormat_RGB888);
	if (t)
	{

		delete t;
	}

	return c;
}

bool WeatherHelper::init()
{

	return false;
}