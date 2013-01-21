#include "ShapeHelper.h"

bool ShapeHelper::init()
{
	bool res = false;
	CCLog("%s", __FUNCTION__);




	CCLog("Returning %d", res);
	return res;
}

bool ShapeHelper::hasShapeForItem(char* name)
{
	bool res = false;
	CCLog("%s Name: %s", __FUNCTION__, name);

	if (!initOK)
		return res;



	CCLog("Returning %d", res);
	return res;
}


bool ShapeHelper::createShapeForItem(char* name, b2Body* body)
{
	bool res = false;
	CCLog("%s Name: %s", __FUNCTION__, name);


	CCLog("Returning %d", res);
	return res;
}