#ifndef _FMOD_STUDIO_H
#define _FMOD_STUDIO_H

#include "fmod_studio_common.h"

#ifdef __cplusplus
extern "C" 
{
#endif

FMOD_RESULT F_API FMOD_Studio_ParseID(const char* idString, FMOD_GUID* id);

FMOD_RESULT F_API FMOD_Studio_System_Create(FMOD_STUDIO_SYSTEM** system);

FMOD_RESULT F_API FMOD_Studio_System_Initialize(FMOD_STUDIO_SYSTEM* system, int maxchannels, FMOD_STUDIO_INITFLAGS studioFlags, FMOD_INITFLAGS flags, void *extradriverdata);
FMOD_RESULT F_API FMOD_Studio_System_Release(FMOD_STUDIO_SYSTEM* system);
FMOD_RESULT F_API FMOD_Studio_System_Update(FMOD_STUDIO_SYSTEM* system);
FMOD_RESULT F_API FMOD_Studio_System_GetEvent(FMOD_STUDIO_SYSTEM* system, FMOD_GUID* id, FMOD_STUDIO_LOADING_MODE mode, FMOD_STUDIO_EVENTDESCRIPTION** eventDesc);
FMOD_RESULT F_API FMOD_Studio_System_SetListenerAttributes(FMOD_STUDIO_SYSTEM* system, FMOD_STUDIO_3D_ATTRIBUTES* attributes);
FMOD_RESULT F_API FMOD_Studio_System_LoadBank(FMOD_STUDIO_SYSTEM* system, const char* filename, FMOD_STUDIO_BANK** bank);

FMOD_RESULT F_API FMOD_Studio_EventDescription_CreateInstance(FMOD_STUDIO_EVENTDESCRIPTION* eventDesc, FMOD_STUDIO_EVENTINSTANCE** event);
FMOD_RESULT F_API FMOD_Studio_EventDescription_Release(FMOD_STUDIO_EVENTDESCRIPTION* eventDesc);

FMOD_RESULT F_API FMOD_Studio_EventInstance_Set3DAttributes(FMOD_STUDIO_EVENTINSTANCE* event, FMOD_STUDIO_3D_ATTRIBUTES* attributes);
FMOD_RESULT F_API FMOD_Studio_EventInstance_Start(FMOD_STUDIO_EVENTINSTANCE* event);
FMOD_RESULT F_API FMOD_Studio_EventInstance_Stop(FMOD_STUDIO_EVENTINSTANCE* event, FMOD_STUDIO_STOP_MODE mode);
FMOD_RESULT F_API FMOD_Studio_EventInstance_Release(FMOD_STUDIO_EVENTINSTANCE* event);
FMOD_RESULT F_API FMOD_Studio_EventInstance_GetParameter(FMOD_STUDIO_EVENTINSTANCE* event, const char* name, FMOD_STUDIO_PARAMETERINSTANCE** parameter);

FMOD_RESULT F_API FMOD_Studio_ParameterInstance_SetValue(FMOD_STUDIO_PARAMETERINSTANCE* parameter, float value);


#ifdef __cplusplus
}
#endif

#endif //_FMOD_STUDIO_H