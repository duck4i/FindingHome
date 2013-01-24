#ifndef __WEATHER_HELPER_H__
#define __WEATHER_HELPER_H__

#include <cocos2d.h>
#include "extern\CCTexture2DMutable.h"
using namespace cocos2d;

//	Get pixel from image - IOS
//	http://stackoverflow.com/questions/448125/how-to-get-pixel-data-from-a-uiimage-cocoa-touch-or-cgimage-core-graphics

//	Fez weather system
//	http://theinstructionlimit.com/wp-content/uploads/2012/03/fez_tech_postmort_pdf_no_notes.pdf

class WeatherHelper
{
private:

	CCNode *parent;		
	char* controllerPath;
	
	CCTexture2DMutable *controller;

	bool initOK;
	bool init();

	void colorAtThisTime(ccColor4B &start, ccColor4B &end);

	/*
	 *	Controller position moves with x-axis from 0 -> end of image, increments slighty when update method called
	 *	and is used to determine what vertical stripe of colors to use in simulation.
	 *	Basically tracks time of the day.
	 */
	unsigned int controllerPosition;	

	float updateTimer;
	bool firstUpdate;

	CCLayerGradient *background;

public:

	WeatherHelper(CCNode* parent, char* controllerPath)
	{
		this->parent = parent;
		this->controllerPath = controllerPath;
		this->controller = NULL;
		this->controllerPosition = 0;
		this->updateTimer = 0;
		this->firstUpdate = true;
		
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