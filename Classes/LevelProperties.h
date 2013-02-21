#ifndef _LEVEL_PROPERTIES_H_
#define _LEVEL_PROPERTIES_H_

#include <cocos2d.h>
#include "XMLHelper.h"

class LevelProperties
{
public:

	bool playerFlipped;
	bool weatherEnabled;

	LevelProperties()
	{
		playerFlipped = false;
		weatherEnabled = false;
	}

public:

	static LevelProperties* sharedProperties();

};


#endif