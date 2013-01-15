#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include "Settings.h"
#include "GLES-Render.h"

using namespace cocos2d;

class MainScene : public CCLayer
{

public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static CCScene* scene();

    // implement the "static node()" method manually
	CREATE_FUNC(MainScene);

	void draw();

private:

	bool firstBackgroundChange;
	float backgroundTimer;
	short lastUsedBackgroundIndex;
	CCLayerGradient *gback;

	void update(float delta);
	void tickKeyboard(float delta);
	void tickBackground(float delta);

	CCLayer* whiteBox;
	CCLayer* blackBox;

	b2World *boxWorld;
	bool boxWorldSleep;

	b2Body *boxWhite;

};

#endif