#ifndef _GAME_ENTITY_SPRITE_H_
#define _GAME_ENTITY_SPRITE_H_

#include "GameEntity.h"
#include "ShapeHelper.h"
#include "LevelProperties.h"
#include "Settings.h"

using namespace cocos2d;

///
///	GameEntity with sprite attached
///
class GameEntitySprite : public GameEntity
{	
protected:

	CCSprite* m_sprite;
	
	GameEntitySprite(NODEINFO info) : GameEntity(info)
	{
		m_sprite = NULL;
	}

	~GameEntitySprite()
	{
		
	}

	///	overridePath is used for Block and Circle sprites to override texture
	virtual bool init(char* overidePath = NULL);

	///	
	///	Apply style to sprite using NODEINFO structure.
	///
	virtual bool postInit();

	virtual bool createFixture();

public:	

	CCSprite* getSprite() { return m_sprite; }

	virtual bool createBody(b2World* world);
	
	virtual void updatePosition(b2Vec2 pos);
	virtual void updateRotation(float32 angle);
	
	virtual void bodyRemovedFromWorld();

	//	public creation
	NINFO_CREATE_FUNC(GameEntitySprite)
};


#endif