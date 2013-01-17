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

public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static CCScene* scene();

    // implement the "static node()" method manually
	CREATE_FUNC(MainScene);

	~MainScene();	

private:

	bool firstBackgroundChange;
	float backgroundTimer;
	short lastUsedBackgroundIndex;
	CCLayerGradient *gback;

	void update(float delta);
	
	void updateBackground(float delta);

	float sceneScale;
	void updateKeyboard(float delta);

	CCNode* player;
	PlayerDirection direction;

	CCLayer* blackBox;
	b2Body *boxWhite;

	void addBodies();
	
	b2World *boxWorld;
	bool boxWorldSleep;
	
	void setupPhysics();		

	//	touch events
	//void ccTouchesBegan(
	void ccTouchesBegan(CCSet* touches, CCEvent* event);
	void ccTouchesEnded(CCSet* touches, CCEvent* event);
	void ccTouchesMoved(CCSet* touches, CCEvent* event);

};

#endif