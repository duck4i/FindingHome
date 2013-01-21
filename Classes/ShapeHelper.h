#ifndef __SHAPE_HELPER_H__
#define __SHAPE_HELPER_H__

#include <cocos2d.h>
#include <Box2D\Box2D.h>
#include "json\json.h"

using namespace cocos2d;
using namespace Json;

/*
Content example.
{
    "rigidBodies": [{
        "name": "dog.png",
        "imagePath": "dog.png",
        "origin": {
            "x": 0,
            "y": 0
        },
        "polygons": [],
        "circles": [],
        "shapes": [{
            "type": "POLYGON",
            "vertices": [{
                "x": 0.6200000047683716,
                "y": 0.7900000214576721
            }, {
                "x": 0.6600000262260437,
                "y": 0.7900000214576721
            }, {
                "x": 0.49000000953674316,
                "y": 0.010000050067901611
            }, {
                "x": 0.6000000238418579,
                "y": 0.7700000405311584
            }]
        }]
    }],
    "dynamicObjects": []
}
*/

class ShapeHelper
{
private:

	const char* resourcePath;

public:
	
	ShapeHelper(const char* resourcePath)
	{
		this->resourcePath = resourcePath;
	}

	bool hasShapeForItem(char* name);
	bool createShapeForItem(b2Body* body, char* name);

};


#endif