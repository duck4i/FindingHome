#ifndef __LEVEL_NODE_INFO_H__
#define __LEVEL_NODE_INFO_H__

#include <cocos2d.h>
#include "XMLHelper.h"

using namespace cocos2d;

#ifndef MAX_PATH
	#define MAX_PATH 255
#endif

enum NodeType 
{	
	NodeTypeBlock = 0,
	NodeTypeCircle,
	NodeTypeTexture,
	NodeTypePlayer,
	NodeTypeExit,
	NodeTypeCollisionPath,
	NodeTypeEnemy,
	NodeTypeUndefined
};

enum EnemyType
{
	EnemyTypeUndefined,
	EnemyTypeBat,
	EnemyTypeCrow,
	EnemyTypeSquirel,
	EnemyTypeSquirelBlack,
	EnemyTypeBore
};

///
///	Used to simplify function calls due to large number of params;
///
class NODEINFO
{
public:	
	
	NodeType nodeType;
	EnemyType enemyType;

	CCPoint position;
	CCSize size;
	float rotation;
	float radius;
	float scale;
	ccColor4B color;
	ccColor4B tint;
	
	char texture[MAX_PATH]; 
	char* rawTexture;
	char* assetTexture;	
	char* nextLevel;

	bool flipHorizontally;
	bool flipVertically;
	bool visible;

	xmlNodePtr xmlNode;
	CCNode* cocosNode;

	CCNode* worldLayerNode;
	b2World* boxWorldNode;


	NODEINFO()
	{		
		nodeType = NodeTypeUndefined;
		position = ccp(0,0);
		size = CCSizeMake(100, 100);
		rotation = 0;
		radius = 10;
		scale = 1;
		memset(texture, 0, sizeof(texture));
		rawTexture = NULL;
		assetTexture = NULL;
		flipHorizontally = false;
		flipVertically = false;
		visible = true;
		xmlNode = NULL;
		cocosNode = NULL;
		nextLevel = NULL;
		enemyType = EnemyTypeUndefined;

		worldLayerNode = NULL;
		boxWorldNode = NULL;
	}

};


#endif