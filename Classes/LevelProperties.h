#ifndef _LEVEL_PROPERTIES_H_
#define _LEVEL_PROPERTIES_H_

#include <cocos2d.h>
#include "XMLHelper.h"

#define STRING_TRUE(s) xmlStrcasecmp(s, (xmlChar*) "true") == 0

class LevelProperties
{
public:

	bool PlayerFlipped;
	bool WeatherActive;
	float CameraZoom;
	float PlayerSpeed;
	float PlayerJump;
	float PlayerShiftModifier;
	CCRect SceneSize;

	CCNode* WorldLayer;

	void reset()
	{
		CameraZoom = 0;
		PlayerSpeed = 0;
		PlayerJump = 0;
		PlayerShiftModifier = 0;
		PlayerFlipped = false;
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