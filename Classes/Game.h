#ifndef _GAME_H_
#define _GAME_H_

#include <cocos2d.h>

using namespace cocos2d;

class Game
{
private:
	
public:

	CCPoint p;
	
	float sceneScale;
	char* nextLevel;
	
	int doSomething()
	{
		CCLog("HELLO FROM Game CLASS!");
		return 0;
	}

	void exit()
	{
		//	exit game
		::exit(0);
	}

	Game()
	{
		
	}
};

#endif
