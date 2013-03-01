#include "NewAudioSystem.h"
#include "..\Resources\FMOD_DESIGNER\studio.h"

static NewAudioSystem* _staticAudioSystem = NULL;

NewAudioSystem* NewAudioSystem::shared()
{
	if (!_staticAudioSystem)
	{
		_staticAudioSystem = new NewAudioSystem();
		if (!_staticAudioSystem || !_staticAudioSystem->init())
			CC_SAFE_DELETE(_staticAudioSystem);
	}

	return _staticAudioSystem;
}

void NewAudioSystem::purge()
{
	CC_SAFE_DELETE(_staticAudioSystem); 
}

bool NewAudioSystem::init()
{
	do
	{
		FMOD_RESULT result;

		result = FMOD::EventSystem_Create(&system);
		if (result != FMOD_OK)
			break;

		result = system->init(MAX_CHANNELS, FMOD_INIT_NORMAL, NULL);
		if (result != FMOD_OK)
			break;		

		result = system->load(RESOURCE_DIR "FMOD_DESIGNER\\studio.fev", NULL, &project);
		if (result != FMOD_OK)
			break;

		

		return true;
	} 
	while (false);
	return false;
}

void NewAudioSystem::update()
{

}

void NewAudioSystem::pause()
{

}

void NewAudioSystem::resume()
{

}

void NewAudioSystem::playHop()
{

}