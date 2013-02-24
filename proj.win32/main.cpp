#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"
#include "Settings.h"
#include <string>
#include <Windows.h>
#include "Settings.h"
#include "Performance.h"
#include "LevelProperties.h"

USING_NS_CC;

// uncomment below line, open debug console
// #define USE_WIN32_CONSOLE

char* commandLine = NULL;

bool alreadyRunning()
{
	HANDLE h = CreateMutex(NULL, FALSE, "FHomeM00tex");
	if (h != NULL && GetLastError() == ERROR_ALREADY_EXISTS)
		return true;
	return false;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	//	check double run
	if (alreadyRunning())
		return -1;	

	if (lpCmdLine && strlen(lpCmdLine) > 0)
	{
		commandLine = lpCmdLine + 1;
		commandLine[strlen(commandLine) - 1] = 0;
		
		if (!doesFileExits(commandLine))
			return -2;
	}

#ifdef USE_WIN32_CONSOLE
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
#endif

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();

	bool fullScreen = false;
	if (fullScreen)
	{
		HWND desktop = GetDesktopWindow();
		RECT r; 
		GetClientRect(desktop, &r);
		eglView->setFrameSize(r.right, r.bottom);
	}
	else
		eglView->setFrameSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	//	no matter what resolution design size is the same.
	eglView->setDesignResolutionSize(WINDOW_WIDTH, WINDOW_HEIGHT, kResolutionNoBorder);
	
	//	set window name
	SetWindowText(eglView->getHWnd(), WINDOW_TITLE);

	srand(GetTickCount());

    int ret = CCApplication::sharedApplication()->run();

#ifdef USE_WIN32_CONSOLE
    FreeConsole();
#endif

	/*
#if defined(_DEBUG) && !defined(DISABLE_SHINY)
	PROFILER_UPDATE();
	PROFILER_OUTPUT("profiler_out.txt");
#endif
	*/
	

    return ret;
}
