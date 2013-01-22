#ifndef __SHAPE_HELPER_H__
#define __SHAPE_HELPER_H__

#include <cocos2d.h>
#include <fstream>
#include <Box2D\Box2D.h>
#include "json\json.h"
#include "Physics.h"

using namespace cocos2d;
using namespace Json;
using namespace std;

//	HELP HERE
//	http://jsoncpp.sourceforge.net/

class ShapeHelper
{
private:

	const char* resourcePath;

	bool initOK;
	bool init();

	Value rigidBodies;

	Value itemWithName(char* name);

public:
	
	ShapeHelper(const char* resourcePath)
	{
		this->resourcePath = resourcePath;
		initOK = init();
	}

	bool createShapeForItem(char* name, __in b2Body* body, CCSize size, float density = 1.0f, float friction = 1.0f);

};


#endif