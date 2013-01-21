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

	Value v;		
	rigidBodies = root.get("rigidBodies", v);

	CCLog("Returning %d", res);
	return res;
}

bool ShapeHelper::hasShapeForItem(char* name)
{
	bool res = false;
	CCLog("%s Name: %s", __FUNCTION__, name);

	if (!initOK || name == NULL)
		return res;	

	unsigned int size = rigidBodies.size();
	CCLog("Found size: %u", size);

	for (unsigned int i = 0; i < rigidBodies.size(); i++)
	{
		Value v = rigidBodies[i];
		//CCLog("%s", v.asString().c_str());
	}

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