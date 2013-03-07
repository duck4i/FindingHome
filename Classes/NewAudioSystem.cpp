#include "NewAudioSystem.h"
#include "..\Resources\FMOD_Designer\studio.h"

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

		result = project->getGroupByIndex(EVENTGROUP_STUDIO_MAIN, true, &eventGroup);
		if (result != FMOD_OK)
			break;

		result = eventGroup->getEventByIndex(EVENTID_STUDIO_MAIN_LOOPCRICKETSEVENT, 0, &loopCricketsEvent);
		if (result != FMOD_OK)
			break;
		result = eventGroup->getEventByIndex(EVENTID_STUDIO_MAIN_LOOPSTORMEVENT, 0, &loopStormEvent);
		if (result != FMOD_OK)
			break;
		result = eventGroup->getEventByIndex(EVENTID_STUDIO_MAIN_PLAYHOPEVENT, 0, &playHopEvent);
		if (result != FMOD_OK)
			break;

		loopCricketsEvent->setPaused(true);
		loopCricketsEvent->start();

		loopStormEvent->setPaused(true);
		loopStormEvent->start();

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
	loopCricketsEvent->setPaused(true);
	loopStormEvent->setPaused(true);
}

void NewAudioSystem::resume()
{
	loopCricketsEvent->setPaused(false);
	loopStormEvent->setPaused(false);	
}

void NewAudioSystem::playHop()
{
	playHopEvent->stop();
	playHopEvent->start();
}

