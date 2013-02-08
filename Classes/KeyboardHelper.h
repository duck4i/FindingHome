#ifndef _KEYBOARD_HELPER_H_
#define _KEYBOARD_HELPER_H_

#include "cocos2d.h"
using namespace cocos2d;

//	http://stackoverflow.com/questions/9149600/global-keyboard-hooks-in-c

enum KeyState
{
	KeyStateUp,
	KeyStateDown
};

class KeyboardHelper 
{
private:
	
	HHOOK m_hook;
	HINSTANCE m_module;

	static LRESULT CALLBACK HookProc(int code, WPARAM wParam, LPARAM lParam);

	bool init();

	KeyboardHelper()
	{
		m_hook = NULL;
		m_module = NULL;
	}

	~KeyboardHelper()
	{
	}

public:	

	//	movement keys
	KeyState b_up;
	KeyState b_down;
	KeyState b_left;
	KeyState b_right;

	//	special keys
	KeyState b_shift;

	//	utility keys
	KeyState b_F1;
	KeyState b_F2;
	KeyState b_F4;
	KeyState b_F7;
	KeyState b_F8;
	KeyState b_F9;
	

	static KeyboardHelper* sharedHelper();

};

#endif