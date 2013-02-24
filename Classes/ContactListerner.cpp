#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact *con)
{
	PROFILE_FUNC();

	//CCLog("Contact listerner fired");
	if (reachedEndOfTheScene)
		return;

	GameEntity* a = (GameEntity*) con->GetFixtureA()->GetBody()->GetUserData();
	GameEntity* b = (GameEntity*) con->GetFixtureB()->GetBody()->GetUserData();
	
	GameEntityPlayer* pA = dynamic_cast<GameEntityPlayer*>(a);
	GameEntityPlayer* pB = dynamic_cast<GameEntityPlayer*>(b);

	if (pA || pB)
	{		
		GameEntityPlayer *player = NULL;
		GameEntity* other = NULL;
		
		if (pA) { player = pA; other = b; }
		else 	{ player = pB; other = a; }

		//	now check for hits
		CollectibleHit(other);
		ExitHit(other);
	}
}

void ContactListener::EndContact(b2Contact *con) 
{ 
}

void ContactListener::CollectibleHit(GameEntity* entity)
{
	if (!entity->getProperties().isCollectable())
		return;	
	
	PROFILE_FUNC();

	//	mark for removal
	CCLog("Collectable hit!");
	entity->removeAtNextUpdate();
}

void ContactListener::ExitHit(GameEntity* entity)
{
	GameEntityExit* exit = dynamic_cast<GameEntityExit*>(entity);
	if (!exit)
		return;
	
	CCLog("Exit hit!");
	reachedEndOfTheScene = true;	
	exit->loadNextLevel();
}