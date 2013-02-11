#include "KeyboardHelper.h"

KeyboardHelper* singleInstanceHelper = NULL;

KeyboardHelper* KeyboardHelper::sharedHelper()
{
	if (singleInstanceHelper)
		return singleInstanceHelper;

	singleInstanceHelper = new KeyboardHelper();
	if (singleInstanceHelper && singleInstanceHelper->init())
	{
		return singleInstanceHelper;
	}

	CC_SAFE_DELETE(singleInstanceHelper);
	return NULL;
}

bool KeyboardHelper::init()
{
	m_module = (HINSTANCE) GetModuleHandle(NULL);
	m_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookProc, m_module, 0);
	return true;
}

LRESULT KeyboardHelper::HookProc(int code, WPARAM wParam, LPARAM lParam)
{
	KeyboardHelper* helper = KeyboardHelper::sharedHelper();
	KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;

	switch (wParam)
	{
		case WM_KEYDOWN:
		{
			unsigned int key = pKeyBoard->vkCode;

			if (key == VK_LEFT)
				helper->b_left = KeyStateDown;
			if (key == VK_RIGHT)
				helper->b_right = KeyStateDown;
			if ( (key == VK_UP || key == VK_SPACE) && helper->b_up == KeyStateUp)
				helper->b_up = KeyStateDown;
			if (key == VK_DOWN)
				helper->b_down = KeyStateDown;
			if (key == VK_LSHIFT || key == VK_RSHIFT)
				helper->b_shift = KeyStateDown;
			
			if (key == VK_F1 && helper->b_F1 == KeyStateUp)
				helper->b_F1 = KeyStateDown;
			if (key == VK_F2 && helper->b_F2 == KeyStateUp)
				helper->b_F2 = KeyStateDown;
			if (key == VK_F4 && helper->b_F4 == KeyStateUp)
				helper->b_F4 = KeyStateDown;

			if (key == VK_F7)
				helper->b_F7 = KeyStateDown;
			if (key == VK_F8)
				helper->b_F8 = KeyStateDown;
			if (key == VK_F9)
				helper->b_F9 = KeyStateDown;

			break;
		}
		case WM_KEYUP:
		{
			unsigned int key = pKeyBoard->vkCode;

			if (key == VK_LEFT)
				helper->b_left = KeyStateUp;
			if (key == VK_RIGHT)
				helper->b_right = KeyStateUp;
			if (key == VK_UP || key == VK_SPACE)
				helper->b_up = KeyStateUp;
			if (key == VK_DOWN)
				helper->b_down = KeyStateUp;
			if (key == VK_SHIFT || key == VK_LSHIFT)
				helper->b_shift = KeyStateUp;

			if (key == VK_F1)
				helper->b_F1 = KeyStateUp;
			if (key == VK_F2)
				helper->b_F2 = KeyStateUp;
			if (key == VK_F4)
				helper->b_F4 = KeyStateUp;

			if (key == VK_F7)
				helper->b_F7 = KeyStateUp;
			if (key == VK_F8)
				helper->b_F8 = KeyStateUp;
			if (key == VK_F9)
				helper->b_F9 = KeyStateUp;

			break;
		}
	}

	return CallNextHookEx(NULL, code, wParam, lParam);
}

KeyState KeyboardHelper::getUp()
{
	KeyState s = b_up;
	if (s == KeyStateDown) b_up = KeyStateUndefined;
	return s;
}
KeyState KeyboardHelper::getLeft()
{
	return b_left;
}
KeyState KeyboardHelper::getRight()
{
	return b_right;
}
KeyState KeyboardHelper::getDown()
{
	return b_down;
}
KeyState KeyboardHelper::getShift()
{
	return b_shift;
}

KeyState KeyboardHelper::getF1()
{
	KeyState s = b_F1;
	if (s == KeyStateDown) b_F1 = KeyStateUndefined;
	return s;
}

KeyState KeyboardHelper::getF2()
{
	KeyState s = b_F2;
	if (s == KeyStateDown) b_F2 = KeyStateUndefined;
	return s;
}

KeyState KeyboardHelper::getF4()
{
	KeyState s = b_F4;
	if (s == KeyStateDown) b_F4 = KeyStateUndefined;	
	return s;
}

KeyState KeyboardHelper::getF7()
{
	return b_F7;
}
KeyState KeyboardHelper::getF8()
{
	return b_F8;
}
KeyState KeyboardHelper::getF9()
{
	return b_F9;
}