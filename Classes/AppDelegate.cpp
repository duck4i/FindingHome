#include "cocos2d.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "MainScene.h"
#include <script_support\CCScriptSupport.h>

//#include "SimpleAudioEngine.h"
#include "NewAudioSystem.h"
#include <ScriptingCore.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "mozjs.lib")
#pragma comment(lib, "libJSBinding.lib")

using namespace CocosDenshion;

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    //SimpleAudioEngine::end();
	NewAudioSystem::purge();
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();		
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

	pDirector->setProjection(ccDirectorProjection::kCCDirectorProjection2D);
	pDirector->setDepthTest(false);	

    // turn on display FPS
    pDirector->setDisplayStats(false);
	
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	/*
    ScriptingCore* sc = ScriptingCore::getInstance();
    sc->addRegisterCallback(register_all_cocos2dx);
    sc->addRegisterCallback(register_cocos2dx_js_extensions);
    sc->addRegisterCallback(jsb_register_chipmunk);
    sc->addRegisterCallback(jsb_register_system);
    
    sc->start();
    
    CCScriptEngineProtocol *pEngine = ScriptingCore::getInstance();
    CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);
    ScriptingCore::getInstance()->runScript("tests-boot-jsb.js");

	*/
	//ScriptingCore::getInstance()->runScript(RESOURCE_DIR "script.js");
	



    // create a scene. it's an autorelease object
    CCScene *pScene = MainScene::scene();

    // run
    pDirector->runWithScene(pScene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();

    //SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	NewAudioSystem::shared()->pause();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();

    //SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	NewAudioSystem::shared()->resume();
}
