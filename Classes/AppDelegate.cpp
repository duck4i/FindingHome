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
	#include "game.hpp"

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

bool doneLoading = false;
AppDelegate::AppDelegate()
{	
	
}

AppDelegate::~AppDelegate()
{    
	NewAudioSystem::purge();

#ifdef ENABLE_SCRIPTING
	CCScriptEngineManager::sharedManager()->purgeSharedManager();
#endif
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

	//	register private JS calls
	sc->addRegisterCallback(register_all_game);
	sc->start();
	
	CCScriptEngineProtocol* p = ScriptingCore::getInstance();
	CCScriptEngineManager::sharedManager()->setScriptEngine(p);
			
	char* msg = "Running JS:" JS_INCLUDE_SCRIPT;
	js_log(msg);

	sc->runScript(JS_INCLUDE_SCRIPT);
	
#endif

	extern char* levelOverride;
	if (levelOverride)
	{
		CCLog("Level override is ENABLED.");
		std::string path = levelOverride;

		if (path.find(".js") != path.npos)
		{
			CCLog("");
			levelOverride = NULL;	//	reset override in that case
			sc->runScript(path.c_str());
			return true;	//	END HERE - special case when JS is loaded only
		}
	}

    // create a scene. it's an autorelease object
    CCScene *pScene = MainScene::scene();    
    pDirector->runWithScene(pScene);

	doneLoading = true;
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
	if (!doneLoading)
		return;

    CCDirector::sharedDirector()->stopAnimation();

    //SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	extern bool disableSound;
	if (!disableSound)
		NewAudioSystem::shared()->pause();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
	if (!doneLoading)
		return;

    CCDirector::sharedDirector()->startAnimation();

    //SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	extern bool disableSound;
	if (!disableSound)
		NewAudioSystem::shared()->resume();
}
