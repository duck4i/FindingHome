#ifndef _GAME_ENTITY_H_
#define _GAME_ENTITY_H_

#include <cocos2d.h>
#include <Box2D\Box2D.h>
#include "CustomProperty.h"
#include "LevelNodeInfo.h"
#include "Settings.h"

using namespace cocos2d;

//	macro to create create func
#define NINFO_CREATE_FUNC(T) static T* create(NODEINFO info){\
	T* o = new T(info); if (o) {\
		do { o->preInit(); bool ok = o->init(); if (!ok) break; o->postInit(); o->autorelease(); return o; }\
		while(false); }\
		CC_SAFE_DELETE(o); return NULL;\
	}


///
///	Game Entity Class, all items in game inherit GameEntity class.
///	Inherited CCNode.
///
class GameEntity : public CCObject
{
protected:
	
	//	meta	
	NODEINFO m_nodeInfo;
	CustomProperties m_customProps;

	//	initialization, preInit and postInit can be used to preset and apply styles from nodeInfo diferently for each subclass
	virtual void preInit();
	virtual bool init();
	virtual void postInit();

	//	constructor and destructor
	GameEntity(NODEINFO info)
	{
		m_nodeInfo = info;
	}

public:	
	
	virtual const NODEINFO& getNodeInfo();
	virtual const CustomProperties& getProperties();
	
	//	public creation	
	NINFO_CREATE_FUNC(GameEntity)
};


///
///	GameEntity with sprite attached
///
class GameEntitySprite : public GameEntity
{	

protected:
	
	GameEntitySprite(NODEINFO info) : GameEntity(info)
	{
		sprite = NULL;
	}

	virtual bool init(char* overidePath = NULL);
	virtual void postInit();	//	apply style from nodeInfo

public:

	CCSprite* sprite;

	//	public creation
	NINFO_CREATE_FUNC(GameEntitySprite)
};


///
///	Rectangle Primitive Entity
///
class GameEntityRectangle : public GameEntitySprite
{
protected:
	GameEntityRectangle(NODEINFO info) : GameEntitySprite(info) { }
	virtual bool init();
public:
	NINFO_CREATE_FUNC(GameEntityRectangle);
};

///
///	Circle Primitive Entity
///
class GameEntityCircle : public GameEntitySprite
{
protected:
	GameEntityCircle(NODEINFO info) : GameEntitySprite(info) { }
	virtual bool init();
public:
	NINFO_CREATE_FUNC(GameEntityCircle);
};




#endif