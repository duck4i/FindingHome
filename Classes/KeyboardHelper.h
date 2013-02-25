#ifndef _KEYBOARD_HELPER_H_
#define _KEYBOARD_HELPER_H_

#include "cocos2d.h"
using namespace cocos2d;

//	http://stackoverflow.com/questions/9149600/global-keyboard-hooks-in-c

enum KeyState
{
	KeyStateUp,
	KeyStateDown,
	KeyStateUndefined
};

class KeyboardHelper 
{
private:
	
	HHOOK m_hook;
	HINSTANCE m_module;

	static LRESULT CALLBACK HookProc(int code, WPARAM wParam, LPARAM lParam);
	bool init();

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
	KeyState b_F12;

	KeyboardHelper()
	{
		m_hook = NULL;
		m_module = NULL;
		
		b_up = KeyStateUp;
		b_down = KeyStateUp;
		b_left = KeyStateUp;
		b_right = KeyStateUp;

		b_shift = KeyStateUp;

		b_F1 = KeyStateUp;
		b_F2 = KeyStateUp;
		b_F4 = KeyStateUp;

		b_F7 = KeyStateUp;
		b_F8 = KeyStateUp;
		b_F9 = KeyStateUp;
	}

	~KeyboardHelper()
	{
		if (m_hook)
			UnhookWindowsHookEx(m_hook);
	}

public:	

	KeyState getUp();
	KeyState getDown();
	KeyState getLeft();
	KeyState getRight();

	KeyState getShift();

	KeyState getF1();
	KeyState getF2();
	KeyState getF4();

	KeyState getF7();
	KeyState getF8();
	KeyState getF9();
	KeyState getF12();

	static KeyboardHelper* sharedHelper();
	static void purge();

};

#endif