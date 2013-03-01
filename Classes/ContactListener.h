#ifndef _CONTACT_LISTENER_H_
#define _CONTACT_LISTENER_H_

#include <cocos2d.h>
#include <Box2D\Box2D.h>
using namespace cocos2d;
#include "GameEntities.h"
#include "Performance.h"
#include "NewAudioSystem.h"

class MainScene;

///
///	Class used for collision detection with enemies, projectiles and other stuff.
///	
///
class ContactListener : public b2ContactListener
{
private:

	NewAudioSystem* audio;

	void BeginContact(b2Contact *con);
	void EndContact(b2Contact *con);

	MainScene* m_mainScene;
	bool reachedEndOfTheScene;

	void CollectibleHit(GameEntity* entity);
	void ExitHit(GameEntity* entity);
	void MovableHit(GameEntity* entity); 

public:

	ContactListener(MainScene* m) : m_mainScene(m)
	{
		reachedEndOfTheScene = false;
		audio = NewAudioSystem::shared();
	}

};


#endif