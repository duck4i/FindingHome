#ifndef __SETTINGS_H__
#define __SETTINGS_H__
#include "Physics.h"

#define WINDOW_WIDTH	960
#define WINDOW_HEIGHT	640

#define WINDOW_TITLE	"Finding Home Alpha"

//	resource dirs and static files
#define RESOURCE_DIR		"..\\Resources\\"

#define SHAPE_DATA					RESOURCE_DIR "ShapeData.json"
#define WEATHER_CONTROLLER_DATA		RESOURCE_DIR "weather_controller.png"
#define GAME_START_LEVEL			RESOURCE_DIR "Level3.xml"

#define STAR_PATH					RESOURCE_DIR "star.png"

#define PLAYER_TAG			1001

#define RESOURCE_BLOCK		RESOURCE_DIR	"block.png"
#define RESOURCE_CIRCLE		RESOURCE_DIR	"circle.png"
#define RESOURCE_PLAYER		RESOURCE_DIR	"dog.png"
#define RESOURCE_LOADING	RESOURCE_DIR	"loading.png"

#define RESOURCE_SHIFT		RESOURCE_DIR	"shift.png"


inline static bool doesFileExits(char* file)
{
#ifdef CC_PLATFORM_WIN32

	unsigned short attrs = GetFileAttributes(file);
	if (!(attrs == INVALID_FILE_ATTRIBUTES || attrs & FILE_ATTRIBUTE_DIRECTORY))
		return true;

#endif
	return false;
}

#endif