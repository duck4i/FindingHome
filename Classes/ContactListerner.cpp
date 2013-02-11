#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact *con)
{
	//CCLog("Contact listerner fired");

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
	}		
}

void ContactListener::EndContact(b2Contact *con) 
{ 
}

void ContactListener::CollectibleHit(GameEntity* entity)
{
	if (!entity->getProperties().isCollectable())
		return;
	
	//	mark for removal
	CCLog("Collectable hit!");
	entity->removeAtNextUpdate();
}
