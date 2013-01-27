#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"
#include "Settings.h"
#include <string>

USING_NS_CC;

// uncomment below line, open debug console
// #define USE_WIN32_CONSOLE

char* commandLine = NULL;

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
	
	if (lpCmdLine && strlen(lpCmdLine) > 0)
	{				
		commandLine = lpCmdLine + 1;
		commandLine[strlen(commandLine) - 1] = 0;				
	}	
	
	//commandLine = _strdup(lpCmdLine);
	//MessageBox(NULL, lpCmdLine, "line", MB_OK);


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

    return ret;
}
