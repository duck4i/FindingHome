#include "ShapeHelper.h"

bool ShapeHelper::init()
{
	bool res = false;
	CCLog("%s", __FUNCTION__);

	Json::Value root;
	Json::Reader reader;
	std::ifstream fin;

	fin.open(resourcePath);
	res = reader.parse(fin, root);


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