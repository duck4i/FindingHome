#ifndef _NEW_AUDIO_SYSTEM_
#define _NEW_AUDIO_SYSTEM_

#include <cocos2d.h>
#include <fmod.hpp>
#include "AudioSystem.h"

#ifdef USE_FMOD_DESIGNER
#include <fmod_event.hpp>

#pragma comment (lib, "fmodstudio_vc.lib")
#pragma comment (lib, "fmod_event.lib")
#pragma comment (lib, "fmodex_vc.lib")

class NewAudioSystem
{			
private:


	FMOD::EventSystem *system;
	FMOD::EventProject *project;
	FMOD::EventGroup *eventGroup;

	FMOD::Event *loopCricketsEvent;
	FMOD::Event *loopStormEvent;
	FMOD::Event *playHopEvent;

	NewAudioSystem()
	{
		system = NULL;
		project = NULL;
		eventGroup = NULL;
	}

	~NewAudioSystem()
	{
		if (system)
		{
			system->release();
			system->unload();
		}
	}
	bool init();

public:	
	
	//	public Audio methods
	void playHop();					

	static NewAudioSystem* shared();	//	Static methods
	static void purge();
	void update();
	void pause();
	void resume();

};

#else

#include <fmod.hpp>
#include <fmod_studio.hpp>

#pragma comment (lib, "fmodstudio_vc.lib")
#pragma comment (lib, "..\\FMOD\\STUDIO2\\lowlevel\\fmod_vc.lib")

class NewAudioSystem
{			
private:

	FMOD::Studio::System *system;
	FMOD::System *lowLevelSystem;
	FMOD::Studio::Bank *bank;

	FMOD::Studio::EventDescription *loopCricketsEvent;
	FMOD::Studio::EventDescription *loopStormEvent;
	FMOD::Studio::EventDescription *playHopEvent;

	FMOD::Studio::EventInstance *cricketsInstance;
	FMOD::Studio::EventInstance *stormInstance;

#endif		

	NewAudioSystem()
	{
		system = NULL;
		bank = NULL;
		loopCricketsEvent = NULL;
		loopStormEvent = NULL;
		playHopEvent = NULL;
		cricketsInstance = NULL;
		stormInstance = NULL;
		lowLevelSystem = NULL;
	}

	~NewAudioSystem()
	{

	}
	bool init();

public:	
	
	//	public Audio methods
	void playHop();					

	static NewAudioSystem* shared();	//	Static methods
	static void purge();
	void update();
	void pause();
	void resume();

};



#endif