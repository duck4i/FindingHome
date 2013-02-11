#ifndef _GAME_ENTITY_PLAYER_H_
#define _GAME_ENTITY_PLAYER_H_

#include "GameEntitySprite.h"
#include "KeyboardHelper.h"

#define PLAYER_SPEED			10.0f

#define PLAYER_MID_AIR_FACTOR	0.3f
#define PLAYER_SHIFT_FACTOR		1.45f
#define PLAYER_JUMP_VALUE		280.0f
#define PLAYER_STEP_VALUE		25.0f
#define IN_AIR_BEFORE_DEATH		5.0f

///	Player direction
enum PlayerDirection
{
	PlayerDirectionLeft,
	PlayerDirectionRight
};

///
///	Rectangle Primitive Entity
///
class GameEntityPlayer : public GameEntity
{
protected:

	CCNode* m_skin;
	
	///	Keeps permanent record of player death state in case of tunneling
	bool m_bPlayerDied;
	PlayerDirection direction;

	GameEntityPlayer(NODEINFO info) : GameEntity(info) 
	{
		m_secondsInAir = 0;
		m_bPlayerDied = false;
		direction = PlayerDirectionRight;
	}
	
	virtual bool init();

public:
	
	static GameEntityPlayer* create(NODEINFO info)
	{
		GameEntityPlayer* p = new GameEntityPlayer(info);
		if (p && p->init())
		{
			p->autorelease();
			return p;
		}
		CC_SAFE_DELETE(p);
		return p;
	}

	virtual bool createBody(b2World* world);

	virtual void updatePosition(b2Vec2 pos);
	virtual void updateRotation(float32 angle);

	virtual void updatePlayerMovement();

	virtual CCNode* getSkin() { return m_skin; } 

	///	Checks if player is touching the ground
	float m_secondsInAir;
	virtual bool isPlayerMidAir();	
	virtual bool checkForDeath();	

};

#endif