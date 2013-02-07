#include "GameEntity.h"

///
///	GameEntity
///	
void GameEntity::preInit()
{
}

bool GameEntity::init()
{
	this->m_customProps.parseFromNode(m_nodeInfo.xmlNode);
	return true;
}

void GameEntity::postInit() 
{ 
}

const CustomProperties& GameEntity::getProperties()
{
	return this->m_customProps;
}

const NODEINFO& GameEntity::getNodeInfo()
{
	return this->m_nodeInfo;
}


///
///	GameEntitySprite
///	
bool GameEntitySprite::init(char* overidePath)
{
	bool pre = GameEntity::init();
	char* path = overidePath != NULL ? overidePath : m_nodeInfo.texture;
	if (path == NULL)
		return false;
	
	CCTextureCache* cache = CCTextureCache::sharedTextureCache();
	if (cache == NULL)
		return false;

	CCTexture2D* tex = cache->textureForKey(path);
	if (tex == NULL)
		tex = cache->addImage(path);
	
	sprite = CCSprite::createWithTexture(tex);
	return sprite != NULL;
}

///	
///	Apply style to sprite using NODEINFO structure.
///
void GameEntitySprite::postInit()
{
	
}

///
///	GameEntityRectangle
///
bool GameEntityRectangle::init()
{
	return GameEntitySprite::init(RESOURCE_BLOCK);
}

///
///	GameEntityCircle
///
bool GameEntityCircle::init()
{
	return GameEntitySprite::init(RESOURCE_CIRCLE);
}