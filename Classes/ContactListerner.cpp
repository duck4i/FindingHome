#include "ContactListener.h"


void ContactListener::BeginContact(b2Contact *con)
{
	CCLog("Contact listerner fired");
}

void ContactListener::EndContact(b2Contact *con)
{
	CCLog("Contact listerner done");
}