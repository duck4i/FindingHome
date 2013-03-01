#ifndef _NEW_AUDIO_SYSTEM_
#define _NEW_AUDIO_SYSTEM_

#include <cocos2d.h>
#include <fmod.hpp>
#include <fmod_event.hpp>
#include "AudioSystem.h"

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