#ifndef __WEATHER_HELPER_H__
#define __WEATHER_HELPER_H__

#include <cocos2d.h>
#include "extern\CCTexture2DMutable.h"
#include "TintShader.h"
#include "Performance.h"
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



///
///	Resources and controller
///	
#define STAR_PATH					RESOURCE_DIR	"star.png"
#define MOON_RESOURCE				RESOURCE_WH_DIR "moon.png"
#define WEATHER_CONTROLLER_DATA		RESOURCE_WH_DIR "weather_controller.png"



///
///	These control the weather :)
///
#define MASTER_SPEED		10.0f

#define CHANGE_SPEED		30.0f / MASTER_SPEED
#define STARS_FADE_SPEED	30.0f / MASTER_SPEED
#define MOON_FADE_SPEED		STARS_FADE_SPEED * 1.3f
#define STARS_NATURAL_DROP	0.02f * MASTER_SPEED	//	used for moon too

#define STARS_PARALAX_DIV	25
#define MOON_PARALAX_DIV	50

#define CLOUDS_1_PARALAX	15
#define CLOUDS_2_PARALAX	20
#define CLOUDS_3_PARALAX	30
#define HIDDEN_CLOUD_ALPHA	0

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
	ccColor3B tintColorAtThisTime(unsigned int index = 0);

	bool isNight();

	CCPoint starrySkyNaturalRotation;
	CCSpriteBatchNode* starrySky;
	void createStarrySky();
	void flipStarVisibility();	

	CCSprite* moon;
	CCPoint moonPosition;
	void createMoon();

	CCNode* clouds;
	CCSpriteBatchNode* bigOnes; 
	CCSpriteBatchNode* mediumOnes;
	CCSpriteBatchNode* smallOnes;

	CCPoint cloudPos[3];
	void createClouds();
	void updateCloudColors();


	//	get how bright color is percieved by human eye
	//	http://www.nbdtech.com/Blog/archive/2008/04/27/Calculating-the-Perceived-Brightness-of-a-Color.aspx
	int getColorPercivedBrigthness(int r, int g, int b);

	ccColor4B lastStart;
	ccColor4B lastEnd;

	CCLayerGradient *background;
	CCLayerGradient *backgroundNext;
	
	bool backgroundChanging;
	void backgroundDoneChanging();
	
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

		moon = NULL;
		clouds = NULL;				
	}

public:

	~WeatherHelper()
	{
		CC_SAFE_FREE(controller);
		CC_SAFE_FREE(controllerImage);
	}

	static WeatherHelper* create(CCNode* parent, CCNode* worldLayer, char* controllerPath)
	{
		WeatherHelper* w = new WeatherHelper(parent, worldLayer, controllerPath);
		if (w && w->init())
		{
			w->initOK = true;
			return w;
		}
		CC_SAFE_DELETE(w);
		return NULL;
	}

	//	call this method on scene update
	void update(float delta);
};

#endif