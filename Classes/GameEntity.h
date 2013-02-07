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
		do { if (!o->preInit()) break; if (!o->init()) break; if (!o->postInit()) break; o->autorelease(); return o; }\
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
	virtual bool preInit();
	virtual bool init();
	virtual bool postInit();

	bool m_bPhysical;

	b2World* m_b2World;
	b2Body* m_b2Body;
	b2FixtureDef m_b2FixtureDef;

	//	constructor and destructor
	GameEntity(NODEINFO info)
	{
		m_nodeInfo = info;
		m_bPhysical = false;
		m_b2World = NULL;
		m_b2Body = NULL;
	}

	virtual bool createFixture();

public:
	
	//	info and properties
	virtual NODEINFO& getNodeInfo();
	virtual CustomProperties& getProperties();

	//	physical objects
	virtual bool createBody(b2World* world);
	virtual void removeBody();

	virtual void updatePosition(b2Vec2 pos);
	virtual void updateRotation(float32 angle);

	virtual bool isPhysical() { return m_bPhysical; }
	virtual b2Body* getBody() { return m_b2Body; }
	
	//	public creation	
	NINFO_CREATE_FUNC(GameEntity)
};

#endif