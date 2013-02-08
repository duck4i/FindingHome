#ifndef _CONTACT_LISTENER_H_
#define _CONTACT_LISTENER_H_

#include <cocos2d.h>
#include <Box2D\Box2D.h>
using namespace cocos2d;

#include "GameEntities.h"

///
///	Class used for collision detection with enemies, projectiles and other stuff.
///	
///
class ContactListener : public b2ContactListener
{
	void BeginContact(b2Contact *con);
	void EndContact(b2Contact *con);
};


#endif