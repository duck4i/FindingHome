#ifndef _GAME_ENTITY_PLAYER_H_
#define _GAME_ENTITY_PLAYER_H_

#include "GameEntitySprite.h"
#include "KeyboardHelper.h"

///
///	Rectangle Primitive Entity
///
class GameEntityPlayer : public GameEntity
{
protected:

	CCNode* m_skin;	

	GameEntityPlayer(NODEINFO info) : GameEntity(info) 
	{
	}
	
	virtual bool init();

public:
	
	static GameEntityPlayer* create(NODEINFO info)
	{
		GameEntityPlayer* p = new GameEntityPlayer(info);
		if (p && p->init())
		{
			p->autorelease();
			return p;
		}
		CC_SAFE_DELETE(p);
		return p;
	}

	virtual bool createBody(b2World* world);

	virtual void updatePosition(b2Vec2 pos);
	virtual void updateRotation(float32 angle);

	virtual void updatePlayerMovement();

	virtual CCNode* getSkin() { return m_skin; } 

};

#endif