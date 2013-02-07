#include "GameEntity.h"

///
///	GameEntity
///	
bool GameEntity::preInit()
{
	return true;
}

bool GameEntity::init()
{
	//	init properties (if any)
	this->m_customProps.parseFromNode(m_nodeInfo.xmlNode);
	return true;
}

bool GameEntity::postInit() 
{
	return true;
}

CustomProperties& GameEntity::getProperties()
{
	return this->m_customProps;
}

NODEINFO& GameEntity::getNodeInfo()
{
	return this->m_nodeInfo;
}

bool GameEntity::createBody(b2World* world)
{
	if (!world)
		return false;
	m_b2World = world;
	m_bPhysical = true;
	m_b2FixtureDef.density = 1.0f;
	return false;
}

void GameEntity::removeBody()
{
	if (m_b2World && m_b2Body)
	{
		m_b2World->DestroyBody(m_b2Body);
		m_bPhysical = false;
		this->release();
	}
}

void GameEntity::updatePosition(b2Vec2 pos)
{

}

void GameEntity::updateRotation(float32 angle)
{

}