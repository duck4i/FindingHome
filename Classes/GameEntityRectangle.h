#ifndef _GAME_ENTITY_RECTANGLE_H_
#define _GAME_ENTITY_RECTANGLE_H_

#include "GameEntitySprite.h"

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