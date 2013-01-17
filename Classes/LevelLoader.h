#ifndef __LEVEL_LOADER_H__
#define __LEVEL_LOADER_H__

#include <cocos2d.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <Box2D/Box2D.h>

using namespace cocos2d;

//	Custom property mappings
//	We wont check custom level property type, only if it exists. 
//	Maybe later if needed (for message boards, etc...) we can add value check for those types.

#define PLAYER_TAG_NAME		"Player"
#define FINISH_TAG_NAME		"Finish"
#define DYNAMIC_TAG_NAME	"Dynamic"	//	dynamic Box2D objects

#define MAIN_LAYER_NAME			"Main"			//	everything in this layer is made as a rigid bodies in Box2D world
#define BACKGROUND_LAYER_NAME	"Background"	//	only backgrouds and sprites - not collidable

#define ITEM_TYPE_RECTANGLE		"RectangleItem"
#define ITEM_TYPE_CIRCLE		"CircleItem"
#define ITEM_TYPE_TEXTURE		"TextureItem"


///
///	Level loading class. 
///	Accepts world node to insert layers into and path to XML level file
///	Level editor used: 
///
class LevelLoader 
{
private:

	CCLayer* worldNode;
	const char* levelPath;

	xmlDocPtr sharedDoc;

	CCNode* playerNode;
	CCNode* finishNode;

public:

	LevelLoader(CCLayer* world, const char* path)
	{
		this->worldNode = world;
		levelPath = path;		
		sharedDoc = NULL;
	}

	~LevelLoader()
	{
		if (sharedDoc)
			xmlFreeDoc(sharedDoc);
	}

	bool parse();


};

#endif