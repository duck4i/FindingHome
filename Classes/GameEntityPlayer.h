#ifndef _GAME_ENTITY_PLAYER_H_
#define _GAME_ENTITY_PLAYER_H_

#include "GameEntitySprite.h"
#include "KeyboardHelper.h"

#define PLAYER_SPEED			10.0f
#define PLAYER_JUMP_VALUE		280.0f
#define PLAYER_STEP_VALUE		25.0f

#define PLAYER_MID_AIR_FACTOR	0.3f
#define PLAYER_SHIFT_FACTOR		1.45f

#define IN_AIR_BEFORE_DEATH		2.5f

#define RESOURCE_PLAYER			RESOURCE_DIR	"dog.png"
#define RESOURCE_PLAYER2		RESOURCE_DIR	"dog2.png"
#define RESOURCE_PLAYER3		RESOURCE_DIR	"dog3.png"
#define RESOURCE_PLAYER4		RESOURCE_DIR	"dog4.png"

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
	CCAnimation* m_animationStill;
	
	///	Keeps permanent record of player death state in case of tunneling
	bool m_bPlayerDied;

	float stepValue;
	float jumpValue;
	float maxSpeed;
	float shiftFactor;
	float midAirFactor;

	GameEntityPlayer(NODEINFO info) : GameEntity(info) 
	{
		m_secondsInAir = 0;
		m_bPlayerDied = false;
		direction = PlayerDirectionRight;

		stepValue = PLAYER_STEP_VALUE;
		jumpValue = PLAYER_JUMP_VALUE;		
		maxSpeed = PLAYER_SPEED;
		shiftFactor = PLAYER_SHIFT_FACTOR;
		midAirFactor = PLAYER_MID_AIR_FACTOR;
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

	PlayerDirection direction;	

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