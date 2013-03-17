#ifndef _GAME_ENTITY_RECTANGLE_H_
#define _GAME_ENTITY_RECTANGLE_H_

#include "GameEntitySprite.h"
using namespace cocos2d;

///
///	Rectangle Primitive Entity
///
class GameEntityRectangle : public GameEntitySprite
{
protected:
	GameEntityRectangle(NODEINFO info) : GameEntitySprite(info) { }
	
	virtual bool preInit();
	virtual bool init();
	virtual bool postInit();
	

public:
	NINFO_CREATE_FUNC(GameEntityRectangle);
};


#endif