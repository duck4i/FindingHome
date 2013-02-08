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
			if (key == VK_UP)
				helper->b_up = KeyStateDown;

			break;
		}
		case WM_KEYUP:
		{
			unsigned int key = pKeyBoard->vkCode;


			break;
		}
	}

	return CallNextHookEx(NULL, code, wParam, lParam);
}