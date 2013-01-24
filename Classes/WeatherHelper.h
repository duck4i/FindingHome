#ifndef __WEATHER_HELPER_H__
#define __WEATHER_HELPER_H__

#include <cocos2d.h>
#include "Settings.h"

using namespace cocos2d;

//	Get pixel from image - IOS
//	http://stackoverflow.com/questions/448125/how-to-get-pixel-data-from-a-uiimage-cocoa-touch-or-cgimage-core-graphics

//	Fez weather system
//	http://theinstructionlimit.com/wp-content/uploads/2012/03/fez_tech_postmort_pdf_no_notes.pdf

//	Use openGL to capture pixel
/*
location = ccp(x * CC_CONTENT_SCALE_FACTOR(), y * CC_CONTENT_SCALE_FACTOR());
UInt8 data[4];
CCRenderTexture* renderTexture = [[CCRenderTexture alloc] initWithWidth:sprite.boundingBox.size.width * CC_CONTENT_SCALE_FACTOR() 
                                                                 height:sprite.boundingBox.size.height * CC_CONTENT_SCALE_FACTOR() 
                                                            pixelFormat:kCCTexture2DPixelFormat_RGBA8888];
[renderTexture begin];
[sprite draw];
glReadPixels((GLint)location.x,(GLint)location.y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, data);
[renderTexture end];
[renderTexture release];
NSLog(@"R: %d, G: %d, B: %d, A: %d", data[0], data[1], data[2], data[3]);
*/



class WeatherHelper
{
private:

	CCNode *parent;
	static ccColor4B getColorFromPixel(CCSprite* sprite, float x, float y);

	bool init();

public:

	WeatherHelper(CCNode* parent)
	{
		this->parent = parent;
	}

	void update(float delta);
};

#endif