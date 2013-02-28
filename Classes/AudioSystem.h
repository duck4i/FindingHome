#ifndef _AUDIO_SYSTEM_H_
#define _AUDIO_SYSTEM_H_

/**
 *	FMOD Audio Wrapper for our game.
 *	
 */

#include <cocos2d.h>
#include "Settings.h"

#include <fmod.hpp>

#define MAX_CHANNELS 8

class AudioSystem
{
private:
	
	FMOD::System *system;
	FMOD::Channel *channel;
	FMOD::Sound *sound;
	

	AudioSystem()
	{
		sound = NULL;
		channel = NULL;
		system = NULL;
	}

	~AudioSystem()
	{
		if (system)
			system->close();
	}

	bool init();

public:

	//	public Audio methods

	
	//	Static methods
	static AudioSystem* shared();
	static void purge();

	void update();

	void pause();
	void resume();

};


#endif