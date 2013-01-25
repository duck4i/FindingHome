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

static inline bool ccc4BEqual(ccColor4B a, ccColor4B b)
{
	return a.a == b.a && a.b == b.b && a.g == b.g && a.r == b.r;
}

class WeatherHelper : public CCObject
{
private:

	CCNode *parent;		
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
	int tintStrengthAtThisTime();

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

	WeatherHelper(CCNode* parent, char* controllerPath)
	{
		this->parent = parent;
		this->controllerPath = controllerPath;
		this->controller = NULL;
		this->controllerImage = NULL;
		this->controllerPosition = 0;
		this->updateTimer = 0;
		this->firstUpdate = true;

		this->background = NULL;
		this->backgroundNext = NULL;

		backgroundChanging = false;				
		
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