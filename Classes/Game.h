#ifndef _GAME_H_
#define _GAME_H_

#include <cocos2d.h>
using namespace cocos2d;


/*
 *	Singleton holder of game data and state.
 *	SCRIPTABLE
 */
class Game
{
private:
	
public:	
	
	float sceneScale;
	char* nextLevel;
	
	void doSomething()
	{
		CCLog("HELLO FROM Game CLASS!");		
	}

	/*
	 *	
	 */
	void newGame()
	{
		
	}

	/*
	 *	Exit from game
	 */
	void exit()
	{		
		::exit(0);
	}

	Game()
	{
		
	}
};

#endif
