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
#include "LevelProperties.h"
#include "Performance.h"
#include "Enemies.h"

USING_NS_CC;

#define MAIN_LAYER_NAME			"Main"			//	everything in this layer is made as a rigid bodies in Box2D world
#define BACKGROUND_LAYER_NAME	"Background"	//	only backgrouds and sprites - not collidable

#define ITEM_TYPE_RECTANGLE		"RectangleItem"
#define ITEM_TYPE_CIRCLE		"CircleItem"
#define ITEM_TYPE_TEXTURE		"TextureItem"
#define ITEM_TYPE_COLL_PATH		"CollisionPathItem"

#define ITEM_TYPE_PLAYER		"PlayerItem"
#define ITEM_TYPE_ENTITY		"EntityItem"
#define ITEM_TYPE_EXIT			"ExitItem"

#define ENEMY_TYPE_CHIPMUNK		"EnemyChipmunk"


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
	bool loadedPlayer;
	
	CCParallaxNode* paralaxNode; // this one is displayed before main layer, eg. play gets behind something...
	CCNode* mainLayer;
	
	CCNode* levelLayers;
	void createLevelLayers();

	b2World *boxWorld;

public:

	CCNode* playerNode;
	b2Body* playerBody;	
	CCNode* finishNode;
	BatchManager* manager;
	GameEntityPlayer* player;
	
private:

	///	type 0: main layer; type 1: background layer
	void parseCurrentNode(xmlNodePtr node, CCPoint parallax, CCLayer *parent, bool isMainLayer = false);	
	
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

	///	read properties of main level object
	void		parseLevelProperties();

public:

	LevelLoader(CCNode* world, const char* path, b2World* boxWorld, BatchManager* manager)
	{
		worldNode = world;
		levelPath = path;		
		sharedDoc = NULL;
		this->boxWorld = boxWorld;
		this->playerBody = NULL;
		this->playerNode = NULL;
		loadedPlayer = false;		
		this->manager = manager;
		createLevelLayers();
	}

	~LevelLoader()
	{
		if (sharedDoc)
			delete sharedDoc;
		
	}

	bool parse();
	void logNode(xmlNodePtr node);	
};

#endif