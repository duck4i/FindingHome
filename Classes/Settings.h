#ifndef __SETTINGS_H__
#define __SETTINGS_H__
#include "Physics.h"


#define WINDOW_WIDTH	960
#define WINDOW_HEIGHT	640

#define WORLD_NODE_ID	11234

#define WINDOW_TITLE	"Finding Home Alpha"

///
///	resource dirs and static files
///
#define RESOURCE_DIR		"..\\Resources\\"
#define RESOURCE_SYS_DIR	RESOURCE_DIR "system\\"

///
///	Special Directories
///
#define SCRIPT_DIR			RESOURCE_DIR		"scripting\\"
#define RESOURCE_SH_DIR		RESOURCE_SYS_DIR	"shaders\\"
#define RESOURCE_WH_DIR		RESOURCE_SYS_DIR	"weather\\"
#define RESOURCE_PL_DIR		RESOURCE_SYS_DIR	"player\\"
#define RESOURCE_EM_DIR		RESOURCE_SYS_DIR	"enemies\\"

///
///	Shape controller position
///
#define SHAPE_DATA					RESOURCE_SYS_DIR "ShapeData.json"

///
///	Starting level settings
///
#ifdef _DEBUG
	#define GAME_START_LEVEL			RESOURCE_DIR "ForestTest.xml"//"ForestTest.xml"
#else
	#define GAME_START_LEVEL			RESOURCE_DIR "Level2.xml"
#endif



#define PLAYER_TAG			1001

#define RESOURCE_BLOCK		RESOURCE_SYS_DIR	"block.png"
#define RESOURCE_CIRCLE		RESOURCE_SYS_DIR	"circle.png"
#define RESOURCE_LOADING	RESOURCE_SYS_DIR	"loading.png"

#define RESOURCE_SHIFT		RESOURCE_SYS_DIR	"shift.png"

#define JS_INCLUDE_SCRIPT	SCRIPT_DIR "include.js"

///
///	Checks if file exists on multiplatform
///	TODO: Move it from here to somewhere else
///
inline static bool doesFileExits(char* file)
{
#ifdef CC_PLATFORM_WIN32

	unsigned short attrs = GetFileAttributes(file);
	if (!(attrs == INVALID_FILE_ATTRIBUTES || attrs & FILE_ATTRIBUTE_DIRECTORY))
		return true;
	return false;

#endif
	return true;
}

///	TODO: Move to utilites
static ccColor3B cc4to3(ccColor4B c)
{
	return ccc3(c.r, c.g, c.b);
}

#endif