#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include "Settings.h"
#include "extern/B2DebugDrawLayer.h"
#include "LevelLoader.h"
#include "WeatherHelper.h"

using namespace cocos2d;

#define DEFAULT_SCALE		0.5f
#define DOG_SPEED			10.0f

#define DOG_MID_AIR_FACTOR	0.3f
#define DOG_SHIFT_FACTOR	1.45f
#define DOG_JUMP_VALUE		280.0f
#define DOG_STEP_VALUE		25.0f

enum PlayerDirection
{
	PlayerDirectionLeft,
	PlayerDirectionRight
};

class MainScene : public CCLayerColor
{
private:

	void update(float delta);

	WeatherHelper *weather;

	bool cameraMoveInProgress;
	void toggleCameraProgress();
	void updateCamera(float delta);

	float sceneScale;
	
	unsigned int jumpKeyIsDown;
	bool restartKeyIsDown;
	bool boxDebugKeyIsDown;
	
	bool disableKeyboard;
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
	
	//	initialization and setup
	void setupPhysics();
	void addBodies();

	//	touch events
	bool touchesInProgress;
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