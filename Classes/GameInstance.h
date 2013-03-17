#ifndef _GAME_H_
#define _GAME_H_

#include <cocos2d.h>
using namespace cocos2d;


#include "Settings.h"
#include "GameEntities.h"

/*
 *	Singleton holder of game data and state.
 *	SCRIPTABLE
 */
class GameInstance : CCObject
{
private:

	float sceneScale;
	std::string nextLevel;

	GameEntityPlayer* player;
	CCScene* scene;

public:
	
	//	setters and getters
	float getScale() { return sceneScale; }
	void setScale(float scale) { sceneScale = scale; }

	std::string getNextLevel() { return nextLevel; }
	void setNextLevel(std::string level) { nextLevel = level; }

	GameEntityPlayer* getPlayer() { return player; }
	void setPlayer(GameEntityPlayer* p) { player = p; }

	CCScene* getScene() { return scene; }
	void setScene(CCScene* s) { scene = s; }

public:
	
	//	shared instance
	static GameInstance* sharedInstance();
	void purge();

	/*
	 *	
	 */
	void newGame() {}

	/*
	 *	Exit from game
	 */
	void exit() 
	{
		::exit(0);
	}

	GameInstance()
	{		
		sceneScale = 1;
		nextLevel = "";
		player = NULL;
		scene = NULL;
	}

};

#endif
