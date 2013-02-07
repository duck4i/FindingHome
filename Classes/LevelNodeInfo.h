#ifndef __LEVEL_NODE_INFO_H__
#define __LEVEL_NODE_INFO_H__

#include <cocos2d.h>

enum NODEINFOType 
{
	NODEINFO_BLOCK = 0,
	NODEINFO_CIRCLE,
	NODEINFO_TEXTURE
};

///
///	Used to simplify function calls due to large number of params;
///
typedef struct 
{
	unsigned int type;
	NODEINFOType nodeType;

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

	bool flipHorizontally;
	bool flipVertically;
	bool visible;

	xmlNodePtr xmlNode;
	CCNode* cocosNode;
	

} NODEINFO;


#endif