#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include "Settings.h"
#include "B2DebugDrawLayer.h"


using namespace cocos2d;

enum PlayerDirection
{
	PlayerDirectionLeft,
	PlayerDirectionRight
};

class MainScene : public CCLayer
{
private:

	bool firstBackgroundChange;
	float backgroundTimer;
	short lastUsedBackgroundIndex;
	CCLayerGradient *gback;

	void update(float delta);
	
	void updateBackground(float delta);

	float sceneScale;
	void updateKeyboard(float delta);

	//	player
	CCNode* player;
	b2Body *playerBody;
	PlayerDirection direction;	
	
	
	//	world
	CCNode *worldLayer;
	b2World *boxWorld;
	B2DebugDrawLayer *debugLayer;
	bool boxWorldSleep;
	
	void setupPhysics();
	void addBodies();

	//	touch events
	//void ccTouchesBegan(
	void ccTouchesBegan(CCSet* touches, CCEvent* event);
	void ccTouchesEnded(CCSet* touches, CCEvent* event);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static CCScene* scene();

    // implement the "static node()" method manually
	CREATE_FUNC(MainScene);

	~MainScene();
};

#endif