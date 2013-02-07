#ifndef __LEVEL_LOADER_H__
#define __LEVEL_LOADER_H__

#include <cocos2d.h>
#include <Box2D/Box2D.h>
#include "XMLHelper.h"
#include "ShapeHelper.h"
#include "Settings.h"
#include "LevelNodeInfo.h"
#include "CustomProperty.h"
#include "GameEntities.h"

USING_NS_CC;

#define MAIN_LAYER_NAME			"Main"			//	everything in this layer is made as a rigid bodies in Box2D world
#define BACKGROUND_LAYER_NAME	"Background"	//	only backgrouds and sprites - not collidable

#define ITEM_TYPE_RECTANGLE		"RectangleItem"
#define ITEM_TYPE_CIRCLE		"CircleItem"
#define ITEM_TYPE_TEXTURE		"TextureItem"


//	Z-INDEX IS DEFINED USING ORDER IN XML FILE > THE LATEST WE PARSE IT THE HIGHER IS Z-ORDER
//	EXCEPTION FOR THIS ARE PLAYER AND FINISH ELEMENTS THAT HAVE HIGH ORDER

class CustomProperties;

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

	
	CCNode* frontLayer; // this one is displayed before main layer, eg. play gets behind something...
	CCNode* mainLayer;	
	CCNode* backgroundLayer;
	
	CCNode* levelLayers;
	void createLevelLayers();

	b2World *boxWorld;
	ShapeHelper *shapeHelper;

public:

	CCNode* playerNode;
	b2Body* playerBody;
	//b2Fixture* playerSensorFixture;

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
	char*		parseNodeTexture(xmlNodePtr node, bool raw = false);
	char*		parseNodeAssetName(xmlNodePtr node);
	bool		parseNodeFlip(xmlNodePtr node, bool vertical = false);
	bool		parseNodeVisible(xmlNodePtr node);

public:

	LevelLoader(CCNode* world, const char* path, b2World* boxWorld)
	{
		worldNode = world;
		levelPath = path;		
		sharedDoc = NULL;
		this->boxWorld = boxWorld;
		this->playerBody = NULL;
		this->playerNode = NULL;
		this->shapeHelper = new ShapeHelper(SHAPE_DATA);

		createLevelLayers();
	}

	~LevelLoader()
	{
		if (sharedDoc)
			xmlFreeDoc(sharedDoc);
		if (shapeHelper)
			delete shapeHelper;
	}

	bool parse();
	void logNode(xmlNodePtr node);	
};

#endif