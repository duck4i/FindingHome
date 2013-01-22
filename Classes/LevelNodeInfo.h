#ifndef __LEVEL_NODE_INFO_H__
#define __LEVEL_NODE_INFO_H__

#include <cocos2d.h>

///
///	Used to simplify function calls due to large number of params;
///
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
	char* rawTexture;
	unsigned int type;

	bool flipHorizontally;
	bool flipVertically;
	bool visible;

	CCNode* cocosNode;
	xmlNodePtr xmlNode;
} NODEINFO;


#endif