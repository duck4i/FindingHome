#ifndef __LEVEL_NODE_INFO_H__
#define __LEVEL_NODE_INFO_H__

#include <cocos2d.h>

enum NodeType 
{
	NodeTypeBlock = 0,
	NodeTypeCircle,
	NodeTypeTexture,
	NodeTypePlayer
};

///
///	Used to simplify function calls due to large number of params;
///
class NODEINFO
{
public:

	NodeType nodeType;

	CCPoint position;
	CCSize size;
	float rotation;
	float radius;
	float scale;
	ccColor4B color;
	ccColor4B tint;
	
	char* texture;
	char* rawTexture;
	char* assetTexture;	
	char* nextLevel;

	bool flipHorizontally;
	bool flipVertically;
	bool visible;

	xmlNodePtr xmlNode;
	CCNode* cocosNode;

	NODEINFO()
	{		
		nodeType = NodeTypeBlock;
		position = ccp(0,0);
		size = CCSizeMake(100, 100);
		rotation = 0;
		radius = 10;
		scale = 1;
		texture = NULL;
		rawTexture = NULL;
		assetTexture = NULL;
		flipHorizontally = false;
		flipVertically = false;
		visible = true;
		xmlNode = NULL;
		cocosNode = NULL;
		nextLevel = NULL;
	}

};


#endif