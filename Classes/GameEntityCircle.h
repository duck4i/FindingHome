#ifndef _GAME_ENTITY_CIRCLE_H_
#define _GAME_ENTITY_CIRCLE_H_

#include "GameEntitySprite.h"
using namespace cocos2d;

///
///	Circle Primitive Entity
///
class GameEntityCircle : public GameEntitySprite
{
protected:
	GameEntityCircle(NODEINFO info) : GameEntitySprite(info) { }
	
	virtual bool init();
	virtual bool postInit();
	
	virtual bool createFixture();

public:

	NINFO_CREATE_FUNC(GameEntityCircle);
};

#endif