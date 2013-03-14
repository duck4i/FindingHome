#include "main.h"
#include "AppDelegate.h"
#include "CCEGLView.h"
#include "Settings.h"
#include <string>
#include <Windows.h>
#include "Settings.h"
#include "Performance.h"
#include "LevelProperties.h"
#include <vector>
#include <string>

USING_NS_CC;

// uncomment below line, open debug console
// #define USE_WIN32_CONSOLE


//	command line options
bool fullScreen = false;
bool disableSound = false;

char* levelOverride =	NULL;
						//"..\\Resources\\Scripting\\main-menu.js";

bool alreadyRunning()
{
	HANDLE h = CreateMutex(NULL, FALSE, "FHomeM00tex");
	if (h != NULL && GetLastError() == ERROR_ALREADY_EXISTS)
		return true;
	return false;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
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

	//lpCmdLine = "-fullscreen \"..\\Resources\\Game Levels\\ForestTest.xml\" -something";

	//	parse command line
	if (lpCmdLine)
	{
		std::string commandLine(lpCmdLine);
		std::vector<std::string> list = split(commandLine, ' ');	//	split commands
		std::vector<std::string>::iterator ptr;

		for (ptr = list.begin(); ptr != list.end(); ptr++)
		{
			std::string line = *ptr;
			const char* linec = line.c_str();			
			
			//	fullscreen ;)
			if (_strcmpi(linec, "-fullscreen") == 0)
			{
				CCLog("Full-screen mode ON.");
				fullScreen = true;
				line.erase(line.find_first_of("-fullscreen"));				
				linec = line.c_str();				
			}

			//	empty level from editor
			if (_strcmpi(linec, "\"untitled\"") == 0)
			{
				CCLog("Input is untitled file from editor.\r\nExiting....");
				return 0;
			}

			//	no sound
			if (_strcmpi(linec, "-nosound") == 0)
			{
				CCLog("Sound engine is DISABLED.");
				disableSound = true;
			}


			//	check for file path - if split across multiple lines join it
			if (line.find_first_of('"') != line.npos)
			{
				int i = line.find_first_of('"');
				if (i != line.npos)
					line.erase(i, 1);
				
				i = line.find_last_of('"');
				if (i != line.npos)
				{
					line.erase(i, 1);//	case when path without spaces
					if (doesFileExits((char*) linec))
						levelOverride = _strdup(line.c_str());
				}
				else
				{
					//	case when file divided - copy rest of the list to string
					std::vector<std::string>::iterator ptr2 = ptr;
					while (++ptr2 != list.end())
					{
						std::string s = *ptr2;
						line.append(" " + s);
						if (s.find_first_of('"'))
							break;
					}

					i = line.find_last_of('"');
					if (i != line.npos)
					{
						line.erase(i, line.length() - i);
						if (doesFileExits((char*) line.c_str()))
							levelOverride = _strdup(line.c_str());
					}
				}				
			}			
		}
	}

	//	Check console output
	bool enableConsoleOutput = false;

#if defined(ENABLE_CONSOLE)
	enableConsoleOutput = true;
#endif

	if (enableConsoleOutput)
	{
		AllocConsole();
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "w", stdout);
		freopen("CONOUT$", "w", stderr);
	}

    // create the application instance
    AppDelegate app;
    CCEGLView* eglView = CCEGLView::sharedOpenGLView();
	
	if (fullScreen)
	{
		HWND desktop = GetDesktopWindow();
		RECT r; 
		//GetClientRect(desktop, &r);
		GetWindowRect(desktop, &r);		
		eglView->setFrameSize(r.right, r.bottom);
		unsigned long ws = GetWindowLong(eglView->getHWnd(), GWL_STYLE);
		SetWindowLong(eglView->getHWnd(), GWL_STYLE, ws & ~(WS_CAPTION | WS_THICKFRAME));

		//	no matter what resolution design size is the same.
		eglView->setDesignResolutionSize(WINDOW_WIDTH, WINDOW_HEIGHT, kResolutionNoBorder);
	}
	else
		eglView->setFrameSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	
	
	//	set window name
	SetWindowText(eglView->getHWnd(), WINDOW_TITLE);

	srand(GetTickCount());

    int ret = CCApplication::sharedApplication()->run();

	if (enableConsoleOutput)
	{
		FreeConsole();
	}


    return ret;
}
