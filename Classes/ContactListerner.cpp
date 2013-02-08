#include "ContactListener.h"


void ContactListener::BeginContact(b2Contact *con)
{
	CCLog("Contact listerner fired");

	//GameEntity* a = (GameEntity*) con->GetFixtureA()->GetBody()->GetUserData();
	//GameEntity* b = (GameEntity*) con->GetFixtureB()->GetBody()->GetUserData();

	

	//CCLog("A: %s B: %s", a->getNodeInfo().assetTexture, b->getNodeInfo().assetTexture);
}

void ContactListener::EndContact(b2Contact *con)
{
	CCLog("Contact listerner done");
}