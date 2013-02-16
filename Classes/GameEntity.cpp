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
	
	m_b2BodyDef.type = b2_staticBody;
	m_b2BodyDef.position.Set(SCREEN_TO_WORLD(m_nodeInfo.position.x), SCREEN_TO_WORLD(m_nodeInfo.position.y));
	m_b2BodyDef.userData = this;

	return m_b2Body != NULL;
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

bool GameEntity::createFixture()
{
	return true;
}

void GameEntity::updatePosition(b2Vec2 pos)
{

}

void GameEntity::updateRotation(float32 angle)
{

}

void GameEntity::removeAtNextUpdate()
{
	m_bForRemoval = true;
}

void GameEntity::bodyRemovedFromWorld()
{
	m_b2Body = NULL;
}