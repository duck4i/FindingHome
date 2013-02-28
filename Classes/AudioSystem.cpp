#include "AudioSystem.h"

static AudioSystem* _staticAudioSystem = NULL;


AudioSystem* AudioSystem::shared()
{
	if (!_staticAudioSystem)
	{
		_staticAudioSystem = new AudioSystem();
		if (!_staticAudioSystem || !_staticAudioSystem->init())
			CC_SAFE_DELETE(_staticAudioSystem);
	}

	return _staticAudioSystem;
}

void AudioSystem::purge()
{
	CC_SAFE_DELETE(_staticAudioSystem); 
}

bool AudioSystem::init()
{
	do
	{
		FMOD_RESULT result;

		result = FMOD::System_Create(&system);
		if (result != FMOD_OK)
			break;
		
		result = system->init(MAX_CHANNELS, FMOD_INIT_NORMAL, NULL);
		if (result != FMOD_OK)
			break;

		result = system->createSound(RESOURCE_DIR "crickets_background.wav", FMOD_2D | FMOD_HARDWARE | FMOD_LOOP_NORMAL, NULL, &sound);
		if (result != FMOD_OK)
			break;		

		channel->setVolume(70);

		result = system->createSound(RESOURCE_DIR "storm.wav", FMOD_2D | FMOD_HARDWARE | FMOD_LOOP_NORMAL, NULL, &soundStorm);
		if (result != FMOD_OK)
			break;

		result = system->playSound(FMOD_CHANNEL_FREE, sound, true, &channel);
		if (result != FMOD_OK)
			break;

		result = system->playSound(FMOD_CHANNEL_FREE, soundStorm, true, &channelStorm);
		if (result != FMOD_OK)
			break;

		result = system->createSound(RESOURCE_DIR "hop.mp3", FMOD_DEFAULT, NULL, &soundHop);
		if (result != FMOD_OK)
			break;

		//result = system->playSound(FMOD_CHANNEL_FREE, soundHop, false, &channelEffects);


		//return true;	//	NO DSP FOR NOW ;)
		


		return true;
	} 
	while (false);


	return false;
}

void AudioSystem::update()
{
	if (system)
		system->update();
}

void AudioSystem::pause()
{
	if (channel)	
		channel->setPaused(true);
	if (channelEffects)
		channelEffects->setPaused(true);
	if (channelStorm)
		channelStorm->setPaused(true);
}

void AudioSystem::resume()
{
	if (channel)
		channel->setPaused(false);		
	if (channelEffects)
		channelEffects->setPaused(false);
	if (channelStorm)
		channelStorm->setPaused(false);
}

void AudioSystem::playHop()
{
	if (!system || !soundHop)
		return;
	/*
	bool first = false;
	if (channelEffects == NULL)
		first = true;
	*/

	system->playSound(FMOD_CHANNEL_FREE, soundHop, false, &channelEffects);
	/*
	if (first)
	{		
		FMOD_RESULT result = system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dsp);
		if (result != FMOD_OK)
			return;

		channelEffects->addDSP(dsp, &dspConnection);
	}
	*/
}