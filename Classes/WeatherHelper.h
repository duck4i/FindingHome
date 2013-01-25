#ifndef __WEATHER_HELPER_H__
#define __WEATHER_HELPER_H__

#include <cocos2d.h>
#include "extern\CCTexture2DMutable.h"
using namespace cocos2d;

//	Get pixel from image - IOS
//	http://stackoverflow.com/questions/448125/how-to-get-pixel-data-from-a-uiimage-cocoa-touch-or-cgimage-core-graphics

//	Fez weather system
//	http://theinstructionlimit.com/wp-content/uploads/2012/03/fez_tech_postmort_pdf_no_notes.pdf

//	Color fading
//	http://stackoverflow.com/questions/319594/calculate-a-color-fade

//	blending ?
//	http://www.andersriggelsen.dk/glblendfunc.php
//	http://www.raywenderlich.com/3857/how-to-create-dynamic-textures-with-ccrendertexture

//	real world day and night
//	http://twistedsifter.com/2012/04/blending-day-and-night-into-single-photo-stephen-wilkes/

//	colors? http://es.appbrain.com/app/winter-snow-cartoon-lwp-pro/com.electricseed.cartoonwinterlandscape

static inline bool ccc4BEqual(ccColor4B a, ccColor4B b)
{
	return a.a == b.a && a.b == b.b && a.g == b.g && a.r == b.r;
}

static inline ccColor4B Blend(ccColor4B c1, ccColor4B c2)
{
    ccColor4B result;
	double a1 = c1.a / 255.0;
    double a2 = c2.a / 255.0;

    result.r = (int) (a1 * c1.r + a2 * (1 - a1) * c2.r);
    result.g = (int) (a1 * c1.g + a2 * (1 - a1) * c2.g);
    result.b = (int) (a1 * c1.b + a2 * (1 - a1) * c2.b);
    result.a = (int) (255 * (a1 + a2 * (1 - a1)));
    return result;
}

static float random(float min, float max)
{
	float r = (float)rand() / (float)RAND_MAX;
	return min + r * (max - min);
}


///
///	These control the weather :)
///
#define MASTER_SPEED		3.0f

#define CHANGE_SPEED		30.0f / MASTER_SPEED
#define STARS_FADE_SPEED	30.0f / MASTER_SPEED

#define CONTROLLER_WIDTH	384.0f
#define FULL_CYCLE			60.0f	//	1h

#define ACTION_IN			CONTROLLER_WIDTH / FULL_CYCLE
#define ACTION_INTERVAL		ACTION_IN / MASTER_SPEED


/**
 *	Class for weather control. 
 */
class WeatherHelper : public CCObject
{
private:

	CCNode *parent;
	CCNode *worldLayer;
	char* controllerPath;
	
	CCTexture2DMutable *controller;
	CCImage* controllerImage;

	float updateTimer;
	bool firstUpdate;

	bool initOK;
	bool init();	

	/*
	 *	Controller position moves with x-axis from 0 -> end of image, increments slighty when update method called
	 *	and is used to determine what vertical stripe of colors to use in simulation.
	 *	Basically tracks time of the day.
	 */
	unsigned int controllerPosition;	
	void colorAtThisTime(ccColor4B &start, ccColor4B &end);
	
	int tintStrengthAtThisTime(ccColor3B c);
	ccColor3B tintColorAtThisTime();

	bool isNight();

	CCPoint starrySkyNaturalRotation;
	CCSpriteBatchNode* starrySky;
	void createStarrySky();
	void flipStarVisibility();

	//	get how bright color is percieved by human eye
	//	http://www.nbdtech.com/Blog/archive/2008/04/27/Calculating-the-Perceived-Brightness-of-a-Color.aspx
	int getColorPercivedBrigthness(int r, int g, int b);

	ccColor4B lastStart;
	ccColor4B lastEnd;

	CCLayerGradient *background;
	CCLayerGradient *backgroundNext;
	CCLayerColor	*topTintLayer;
	
	bool backgroundChanging;
	void backgroundDoneChanging();
	

public:

	WeatherHelper(CCNode* parent, CCNode* worldLayer, char* controllerPath)
	{
		this->parent = parent;
		this->worldLayer = worldLayer;
		this->controllerPath = controllerPath;
		this->controller = NULL;
		this->controllerImage = NULL;
		this->controllerPosition = 0;
		this->updateTimer = 0;
		this->firstUpdate = true;

		this->background = NULL;
		this->backgroundNext = NULL;

		backgroundChanging = false;
		starrySky = NULL;
		starrySkyNaturalRotation.x = 0;
		starrySkyNaturalRotation.y = 0;
		
		this->initOK = init();
	}

	~WeatherHelper()
	{		
		//if (this->controller)
		//	delete controller;
	}

	//	call this method on scene update
	void update(float delta);
};

#endif