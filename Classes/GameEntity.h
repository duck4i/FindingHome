#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

#include <cocos2d.h>
#include <Box2D\Box2D.h>
#include "CustomProperty.h"
#include "LevelNodeInfo.h"

using namespace cocos2d;


class GameEntity : CCObject
{
private:
	
	NODEINFO m_nodeInfo;
	CCNode* m_node;	

public:

	CCNode* getNode()				{ return m_node; }
	void	setNode(CCNode* node)	{ m_node = node; }	

	GameEntity();
	~GameEntity();

	bool init();

	CREATE_FUNC(GameEntity);
};


class PhysicalGameEntity : GameEntity
{
private:

	b2Body *m_body;

public:

	b2Body* getBody()			{ return m_body; }
	void	setBody(b2Body* b)	{ m_body = b; }

	bool init();

	PhysicalGameEntity();
	~PhysicalGameEntity();

	//CREATE_FUNC(PhysicalGameEntity);

};

#endif