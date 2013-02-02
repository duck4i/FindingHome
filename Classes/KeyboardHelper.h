#ifndef _KEYBOARD_HELPER_H_
#define _KEYBOARD_HELPER_H_

#include "cocos2d.h"
using namespace cocos2d;

//	http://stackoverflow.com/questions/9149600/global-keyboard-hooks-in-c

class KeyboardHelper
{
private:

	bool hookOK;

public:

	KeyboardHelper();
	~KeyboardHelper();

	void initHook();

};

#endif