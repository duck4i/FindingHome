#ifndef _ENTITY_COLL_PATH_
#define _ENTITY_COLL_PATH_

#include "GameEntity.h"

class GameEntityCollisionPath : public GameEntity
{
private:

	GameEntityCollisionPath(NODEINFO info) : GameEntity(info)
	{
	}

public:
	
	virtual bool createBody(b2World *world);
	virtual bool createFixture();
	NINFO_CREATE_FUNC(GameEntityCollisionPath);

};


#endif