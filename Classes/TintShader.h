#ifndef _TINT_SHADER_H_
#define _TINT_SHADER_H_

#include "cocos2d.h" 
#include "Settings.h"
#include <GL\GL.h>

using namespace cocos2d;

class TintShader : public CCLayer 
{
public:
    
    TintShader();
	virtual ~TintShader();
	
    bool init();
	
	bool start(CCNode* target);
	
    CREATE_FUNC(TintShader);
};

#endif
