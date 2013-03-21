#ifndef __ENEMY_CHIPMUNK_H__
#define __ENEMY_CHIPMUNK_H__ 1

#include <cocos2d.h>
using namespace cocos2d;

#include "GameEntities.h"

#define CHIPMUNK_PATH RESOURCE_EM_DIR "chipmunk.png"

//	after the chipmunk is invisible for 5 seconds but was visible destroy it
#define DESTROY_CHIPMUNK_AFTER	5.0f

class EnemyChipmunk : public GameEntitySprite
{
private:
	bool wasVisible;
	float timeSinceInvisible;

	void hide();
public:

	virtual bool init();
	virtual bool postInit();
	virtual void updatePosition(b2Vec2 pos);


	EnemyChipmunk(NODEINFO info) : GameEntitySprite(info)
	{
		wasVisible = false;
		timeSinceInvisible = 0;
	}

	NINFO_CREATE_FUNC(EnemyChipmunk);

};


#endif