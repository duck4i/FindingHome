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

	NewAudioSystem()
	{
		
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