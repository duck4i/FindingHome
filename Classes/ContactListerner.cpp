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
		MovableHit(other);
		EnemyHit(other);
		ExitHit(other);
	}
}

void ContactListener::EndContact(b2Contact *con) 
{ 
}

void ContactListener::MovableHit(GameEntity* entity)
{
	//if (!entity->getProperties().isDynamicObject())
	//	return;	
}

void ContactListener::EnemyHit(GameEntity* entity)
{
	EnemyChipmunk *chip =  dynamic_cast<EnemyChipmunk*> (entity);
	if (chip)
	{
		chip->removeAtNextUpdate();
		
		//NewAudioSystem::shared()->playHop();//	play bark sound event

		chip->getSprite()->runAction(CCSequence::createWithTwoActions(CCBlink::create(0.5, 3), CCFadeOut::create(0)));
	}
}

void ContactListener::CollectibleHit(GameEntity* entity)
{
	if (!entity->getProperties().isCollectable())
		return;	
		
	PROFILE_FUNC();
		
	if (audio)
		audio->playHop();

	//	mark for removal
	CCLog("Collectable hit!");
	entity->removeAtNextUpdate();
}

void ContactListener::ExitHit(GameEntity* entity)
{
	GameEntityExit* exit = dynamic_cast<GameEntityExit*>(entity);
	if (!exit)
		return;

	PROFILE_FUNC();
	
	CCLog("Exit hit!");
	reachedEndOfTheScene = true;	
	exit->loadNextLevel();
}