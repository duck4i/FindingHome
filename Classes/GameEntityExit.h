#ifndef _GAME_ENTITY_EXIT_
#define _GAME_ENTITY_EXIT_

#include "GameEntity.h"


class GameEntityExit : public GameEntity
{
protected:	

	GameEntityExit(NODEINFO info) : GameEntity(info)
	{
	}

public:

	virtual bool postInit();
	virtual bool createFixture();
	NINFO_CREATE_FUNC(GameEntityExit);


	bool loadNextLevel();
};


#endif