#include "GameInstance.h"

GameInstance* _globalGame = NULL;

GameInstance* GameInstance::sharedInstance()
{	
	if (!_globalGame)
	{
		_globalGame = new GameInstance();
	}
	
	return _globalGame;
}

void GameInstance::purge()
{
	CC_SAFE_DELETE(_globalGame);
}
