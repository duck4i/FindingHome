#ifndef __ENEMY_CHIPMUNK_H__
#define __ENEMY_CHIPMUNK_H__ 1

#include <cocos2d.h>
using namespace cocos2d;

#include "GameEntities.h"

#define CHIPMUNK_PATH RESOURCE_EM_DIR "chipmunk.png"

class EnemyChipmunk : public GameEntitySprite
{
private:
public:

	virtual bool init();
	virtual bool postInit();

	EnemyChipmunk(NODEINFO info) : GameEntitySprite(info)
	{
	}

	NINFO_CREATE_FUNC(EnemyChipmunk);

};


#endif