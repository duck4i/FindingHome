#include "cocos2d.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "MainScene.h"

#include "NewAudioSystem.h"

#ifdef ENABLE_SCRIPTING

	#include <ScriptingCore.h>
	#include "SimpleAudioEngine.h"
	#include "generated/cocos2dx.hpp"
	#include "cocos2d_specifics.hpp"	
	#include "js_bindings_system_registration.h"
	#include "js_bindings_chipmunk_registration.h"
	#include "js_bindings_ccbreader.h"

	#pragma comment(lib, "pthreadVCE2.lib")
	#pragma comment(lib, "libExtensions.lib")
	#pragma comment(lib, "sqlite3.lib")	
	#pragma comment(lib, "ws2_32.lib")
	#pragma comment(lib, "mozjs.lib")
	#pragma comment(lib, "libCocosDenshion.lib")
	#pragma comment(lib, "libChipmunk.lib")
	#pragma comment(lib, "libJSBinding.lib")

#endif

USING_NS_CC;
using namespace CocosDenshion;

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

	//	set resource directory
	SetCurrentDirectory(RESOURCE_DIR);
	
#ifdef ENABLE_SCRIPTING

	ScriptingCore* sc = ScriptingCore::getInstance();
    sc->addRegisterCallback(register_all_cocos2dx);
    sc->addRegisterCallback(register_cocos2dx_js_extensions);
    sc->addRegisterCallback(register_CCBuilderReader);
    sc->addRegisterCallback(jsb_register_chipmunk);
    sc->addRegisterCallback(jsb_register_system);
	sc->start();
	
	CCScriptEngineProtocol* p = sc;
	CCScriptEngineManager::sharedManager()->setScriptEngine(p);	
	
	const char* script = SCRIPT_DIR "include.js";

	char msg[500];
	sprintf(msg, "Running JS: %s", script);
	js_log(msg);

	sc->runScript(script);
	
#endif

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
