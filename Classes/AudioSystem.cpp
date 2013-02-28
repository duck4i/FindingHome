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

		result = system->createSound(RESOURCE_DIR "The Sweet Song.mp3", /*FMOD_DEFAULT*/ FMOD_2D | FMOD_HARDWARE | FMOD_LOOP_NORMAL, NULL, &sound);
		if (result != FMOD_OK)
			break;		

		result = system->playSound(FMOD_CHANNEL_FREE, sound, true, &channel);
		if (result != FMOD_OK)
			break;

		return true;
	} 
	while (false);


	return false;
}

void AudioSystem::update()
{

}

void AudioSystem::pause()
{
	if (channel)
		channel->setPaused(true);
}

void AudioSystem::resume()
{
	if (channel)
		channel->setPaused(false);		
}