#ifndef __LEVEL_LOADER_H__
#define __LEVEL_LOADER_H__

#include <cocos2d.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <Box2D/Box2D.h>
#include "Physics.h"
#include "XMLHelper.h"
#include "CustomProperty.h"

using namespace cocos2d;

#define RESOURCE_DIR		"..\\Resources\\"

#define MAIN_LAYER_NAME			"Main"			//	everything in this layer is made as a rigid bodies in Box2D world
#define BACKGROUND_LAYER_NAME	"Background"	//	only backgrouds and sprites - not collidable

#define ITEM_TYPE_RECTANGLE		"RectangleItem"
#define ITEM_TYPE_CIRCLE		"CircleItem"
#define ITEM_TYPE_TEXTURE		"TextureItem"

//	Z-INDEX IS DEFINED USING ORDER IN XML FILE > THE LATEST WE PARSE IT THE HIGHER IS Z-ORDER
//	EXCEPTION FOR THIS ARE PLAYER AND FINISH ELEMENTS THAT HAVE HIGH ORDER

class CustomProperties;

typedef struct 
{
	CCPoint position;
	CCSize size;
	float rotation;
	float radius;
	float scale;
	ccColor4B color;
	ccColor4B tint;
	char* texture;
	unsigned int type;
	CCNode* cocosNode;
	xmlNodePtr xmlNode;
} NODEINFO;

///
///	Level loading class. 
///	Accepts world node to insert layers into and path to XML level file
///	Level editor used: 
///
class LevelLoader 
{
private:

	CCNode* worldNode;
	const char* levelPath;

	xmlDocPtr sharedDoc;

	CCNode* mainLayer;	
	CCNode* backgroundLayer;
	void createLevelLayers();

	b2World *boxWorld;

public:
	CCNode* playerNode;
	b2Body* playerBody;

	CCNode* finishNode;
	
private:

	//	type 0: main layer; type 1: background layer
	void parseCurrentNode(xmlNodePtr node, unsigned int type = 0, unsigned int zOrder = 0);
	
	bool parseNodeToCocosNode(NODEINFO &info, __in CustomProperties props, unsigned int type = 0, unsigned int zOrder = 0);
	bool parseNodeProperties(NODEINFO &info, __out CustomProperties *props);	
	bool parseNodePhysics(NODEINFO &info, __in CustomProperties props);
	
	
	//	parser helpers
	CCPoint		parseNodePosition(xmlNodePtr node);
	CCSize		parseNodeSize(xmlNodePtr node);
	ccColor4B	parseNodeColor(xmlNodePtr node, bool tint = false);
	float		parseNodeRotation(xmlNodePtr node);
	float		parseNodeRadius(xmlNodePtr node);
	float		parseNodeScale(xmlNodePtr node);
	char*		parseNodeTexture(xmlNodePtr node);

public:

	LevelLoader(CCNode* world, const char* path, b2World* boxWorld)
	{
		worldNode = world;
		levelPath = path;		
		sharedDoc = NULL;
		this->boxWorld = boxWorld;
		this->playerBody = NULL;
		this->playerNode = NULL;

		createLevelLayers();
	}

	LevelLoader(CCNode* world, const char* path, b2World* boxWorld, CCNode* mainLayer, CCNode* backLayer)
	{
		worldNode = world;
		levelPath = path;
		sharedDoc = NULL;
		this->mainLayer = mainLayer;
		this->backgroundLayer = backLayer;
		this->boxWorld = boxWorld;
		this->playerBody = NULL;
		this->playerNode = NULL;
	}

	~LevelLoader()
	{
		if (sharedDoc)
			xmlFreeDoc(sharedDoc);
	}

	bool parse();
	void logNode(xmlNodePtr node);	
};

#endif