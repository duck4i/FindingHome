#include "NewAudioSystem.h"

static NewAudioSystem* _staticAudioSystem = NULL;

#ifdef USE_FMOD_DESIGNER
#include "..\Resources\FMOD_DESIGNER\studio.h"

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

#else

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
	int success = false;
	do
	{
		#define CHECK(x) if (x != FMOD_OK) break; else ++success;
		FMOD_RESULT result;

		system = new FMOD::Studio::System();
		result = FMOD::Studio::System::create(system);
		CHECK(result);
		
		result = system->getLowLevelSystem(&lowLevelSystem);
		CHECK(result);

		FMOD_SPEAKERMODE speakerMode = FMOD_SPEAKERMODE_STEREO;
		result = lowLevelSystem->getDriverCaps(0, NULL, NULL, &speakerMode);
		CHECK(result);

		result = system->initialize(MAX_CHANNELS,  FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, NULL);
		CHECK(result);

		//result = lowLevelSystem->setSpeakerMode(speakerMode);
		//CHECK(result);
		
		bank = new FMOD::Studio::Bank();
		result = system->loadBank(RESOURCE_DIR "studio\\Build\\Desktop\\Master Bank.bank", bank);
		CHECK(result);

		/*
			{f52ab7dd-4c03-48ac-a123-01d97a46f25a} /LoopStorm
			{9c49fc1b-c2ad-49f8-89f9-2533bb71d38a} /LoopCrickets
			{2a490b5b-b58a-4a97-b641-29b1cf812e91} /PlayHop
		*/

		const char* loopingCricketsGUID = "{e168b827-6d12-408e-8b3d-161e3a885f95}";
		FMOD::Studio::ID loopingCricketsID = {0};
		FMOD::Studio::parseID(loopingCricketsGUID, &loopingCricketsID);

		const char* loopingStormGUID = "{e7acf07a-4c9f-4477-9d4b-1f877c15f0ae}";
		FMOD::Studio::ID loopingStormID = {0};
		FMOD::Studio::parseID(loopingStormGUID, &loopingStormID);

		const char* playHopGUID = "{e6807338-34e0-4b0c-ae0d-b6c5b14a92f6}";
		FMOD::Studio::ID playHopID = {0};
		FMOD::Studio::parseID(playHopGUID, &playHopID);

		loopCricketsEvent = new FMOD::Studio::EventDescription();
		result = system->getEvent(&loopingCricketsID, FMOD_STUDIO_LOAD_BEGIN_NOW, loopCricketsEvent);
		CHECK(result);

		loopStormEvent = new FMOD::Studio::EventDescription();
		result = system->getEvent(&loopingStormID, FMOD_STUDIO_LOAD_BEGIN_NOW, loopStormEvent);
		CHECK(result);

		playHopEvent = new FMOD::Studio::EventDescription();
		result = system->getEvent(&playHopID, FMOD_STUDIO_LOAD_BEGIN_NOW, playHopEvent);
		CHECK(result);
		
		//	now play
		cricketsInstance = new FMOD::Studio::EventInstance();
		result = loopCricketsEvent->createInstance(cricketsInstance);
		CHECK(result);

		stormInstance = new FMOD::Studio::EventInstance();
		result = loopStormEvent->createInstance(stormInstance);
		CHECK(result);
		
		cricketsInstance->start();		
		stormInstance->start();	
	} 
	while (false);

	//	TODO: Cleanup
	if (!success)
	{
	}


	return success;
}

void NewAudioSystem::update()
{
	if (system)	
		system->update();
	if (lowLevelSystem)
		lowLevelSystem->update();

}

void NewAudioSystem::pause()
{
	if (cricketsInstance)
		cricketsInstance->setPaused(true);
	if (stormInstance)
		stormInstance->setPaused(true);
}

void NewAudioSystem::resume()
{
	if (cricketsInstance)
		cricketsInstance->setPaused(false);
	if (stormInstance)
		stormInstance->setPaused(false);
}

void NewAudioSystem::playHop()
{
	if (playHopEvent)
	{
		FMOD::Studio::EventInstance instance;
		playHopEvent->createInstance(&instance);


		//FMOD::Channel *ch0 = NULL;
		//FMOD::ChannelGroup *group = NULL;

		//instance.getChannelGroup(&group);		
		//group->getChannel(0, &ch0);
		
		
		


		instance.start();	
		

	}
//	playHopEvent->stop();
//	playHopEvent->start();
}

#endif
