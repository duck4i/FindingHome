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

Value ShapeHelper::itemWithName(char* name)
{	
	if (!initOK || name == NULL)
		return NULL;

	unsigned int size = rigidBodies.size();	
	for (unsigned int i = 0; i < rigidBodies.size(); i++)
	{
		Value v = rigidBodies[i];
		if (v == NULL || v.empty())
			continue;
		
		string shapeName = v["name"].asString();
		string imageName = v["imagePath"].asString();
		string s(name);
		
		if (!s.compare(shapeName) || !s.compare(imageName))		
			return v;
	}
	return NULL;
}

bool ShapeHelper::createShapeForItem(char* name, b2Body* body, CCSize size, float density, float friction)
{
	bool res = false;
	CCLog("%s Name: %s", __FUNCTION__, name);

	//	http://www.box2d.org/forum/viewtopic.php?f=3&t=8418

	Value v = itemWithName(name);
	if (v != NULL && body != NULL)
	{
		Value polys = v["polygons"];
		unsigned int numPoly = polys.size();
		res = numPoly > 0;

		for (unsigned int i = 0; i < numPoly; i++)
		{
			Value curr = polys[i];
			unsigned int numVertices = curr.size();
			b2Vec2* vertices = (b2Vec2*) malloc(numVertices * sizeof(b2Vec2));

			for (unsigned int j = 0; j < curr.size(); j++)	//	all vertices of current poly
			{
				Value set = curr[j];
				float x = set["x"].asDouble();
				float y = set["y"].asDouble();

				float width = SCREEN_TO_WORLD(size.width);
				float height = SCREEN_TO_WORLD(size.height);

				//	correct proportions
				float xCorrector = 1.0f;
				float yCorrector = 1.0f;

				if(size.height < size.width)
					yCorrector = size.width/size.height;
				if(size.width < size.height)
					xCorrector = size.height/size.width;				
				
				//	scale properly from content size
				x *= width * xCorrector;
				y *= height * yCorrector;

				//	adjusting anchor point (physics editor 0x0 but box2d 0.5x0.5x)
				x -= width / 2.0f;
				y -= height / 2.0f;				

				vertices[j].Set(x, y);
			}

			b2PolygonShape ps;
			ps.Set(vertices, numVertices);		
			
			b2FixtureDef fd;
			fd.shape = &ps;			
			fd.density = density;			

			b2Fixture *f = body->CreateFixture(&fd);			
		}		
	}
	else
		CCLog("%s Cannot create shape, something is wrong. (%s)", __FUNCTION__, name);
	
	return res;
}