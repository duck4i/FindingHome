#ifndef _LEVEL_PROPERTIES_H_
#define _LEVEL_PROPERTIES_H_

#include <cocos2d.h>
#include "XMLHelper.h"

#define STRING_TRUE(s) xmlStrcasecmp(s, (xmlChar*) "true") == 0

class LevelProperties
{
public:
		
	bool WeatherActive;
	float CameraZoom;
		
	float PlayerThrust;
	float PlayerJump;
	float PlayerMaxSpeed;	

	float PlayerMidAirModifier;
	float PlayerShiftModifier;

	CCRect SceneSize;

	CCNode* WorldLayer;

	void reset()
	{
		CameraZoom = 0;
		PlayerThrust = 0;
		PlayerMaxSpeed = 0;
		PlayerJump = 0;
		PlayerMidAirModifier = 0;
		PlayerShiftModifier = 0;
		WeatherActive = false;
		WorldLayer = NULL;
	}

	LevelProperties(xmlNodePtr node)
	{
		reset();
		m_node = node;
	}

	~LevelProperties();

private:

	xmlNodePtr m_node;
	bool init();

public:

	static LevelProperties* sharedProperties(xmlNodePtr node = NULL);
	static void purge();
};


#endif