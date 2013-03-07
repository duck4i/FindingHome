#ifndef _NEW_AUDIO_SYSTEM_
#define _NEW_AUDIO_SYSTEM_

#include <cocos2d.h>
#include <fmod_event.hpp>
#include "Settings.h"

#define MAX_CHANNELS 32

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





#endif