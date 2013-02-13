#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "SimpleAudioEngine.h"
#include "extern/B2DebugDrawLayer.h"
#include "Settings.h"
#include "KeyboardHelper.h"
#include "LevelLoader.h"
#include "WeatherHelper.h"
#include "ContactListener.h"

using namespace cocos2d;

#define DEFAULT_SCALE		0.5f
#define SCREEN_MARGIN		0.35f
#define ZOOM_STEP			0.1f
#define ZOOM_TIME			0.5f


class MainScene : public CCLayerColor
{
private:

	void loadMap(float delta);
	
	void update(float delta);
	void updatePhysics(float delta);	

	bool cameraMoveInProgress;
	void toggleCameraProgress();
	void updateCamera(float delta);

	float sceneScale;
	bool zoomInProgress;
	void resetZoomInProgress();
	
	bool disableKeyboard;
	void updateKeyboard(float delta);

	//	weather
	WeatherHelper *weather;

	//	player
	GameEntityPlayer* gamePlayer;
	CCSprite* shiftSprite;
	
	//	world
	CCSize winSize;
	CCNode *loadLayer;
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

	//	sets scene zoom value (scale)
	void setSceneZoom(float value);
	void incSceneZoom();
	void descSceneZoom();
	void resetSceneZoom();

	void playerDied();

	//	contact listener
	ContactListener* worldListener;

public:

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  	

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static CCScene* scene();

    // implement the "static node()" method manually
	CREATE_FUNC(MainScene);

	MainScene();
	~MainScene();
};

#endif