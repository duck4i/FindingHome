#ifndef _PERFORMANCE_H_
#define _PERFORMANCE_H_

///
///	Marcos and includes for performance optimizations of the game code
///

#ifdef CC_PLATFORM_WIN32

	#ifndef DISABLE_MEMORY_TRACE
		//	http://vld.codeplex.com/
		#include "vld.h"
	#endif

	#ifndef DISABLE_SHINY
		//	http://sourceforge.net/projects/shinyprofiler/?source=dlp
		#include "Shiny.h"
	#else
		#define PROFILER_UPDATE() {}
		#define PROFILER_OUTPUT() {}
		#define PROFILE_FUNC() {}
	#endif

#endif

#endif	//_PERFORMANCE_H_