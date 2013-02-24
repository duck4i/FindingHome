#ifndef __SHAPE_HELPER_H__
#define __SHAPE_HELPER_H__

#include <cocos2d.h>
#include <fstream>
#include <Box2D\Box2D.h>
#include "json\json.h"
#include "Physics.h"
#include "Settings.h"

using namespace cocos2d;
using namespace Json;
using namespace std;

//	JSON LIB HELP HERE
//	http://jsoncpp.sourceforge.net/


class Shape 
{
public:
	string name;
	string imagePath;
	list<b2PolygonShape> polygons;

	Shape(string key, string path, list<b2PolygonShape> pol) : name(key), imagePath(path), polygons(pol)
	{
	}
};

class ShapeHelper
{
private:

	list<Shape*> shapes;

	const char* resourcePath;
	bool init();

	Value rigidBodies;
	Value itemWithName(char* name);

	bool defineShapeFromData(Value data, __out list<b2PolygonShape> *shapes);

	ShapeHelper(const char* resourcePath)
	{
		this->resourcePath = resourcePath;		
	}

	~ShapeHelper()
	{
		list<Shape*>::iterator ptr;
		for (ptr = shapes.begin(); ptr != shapes.end(); ptr++)
		{
			CC_SAFE_DELETE(*ptr);
		}
	}

public:
	
	static ShapeHelper* sharedHelper();
	static void purge();

	///	Gets b2PolygonShape for asset name
	bool shapeForKey(char* name, CCSize size, __out list<b2PolygonShape> *out);
};


#endif