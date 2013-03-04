#include "ShapeHelper.h"

ShapeHelper* globalShapeHelper = NULL;

ShapeHelper* ShapeHelper::sharedHelper()
{
	if (globalShapeHelper)
		return globalShapeHelper;

	globalShapeHelper = new ShapeHelper(SHAPE_DATA);
	if (globalShapeHelper != NULL && globalShapeHelper->init())
	{
		return globalShapeHelper;
	}
	else if (globalShapeHelper)
	{
		delete globalShapeHelper;
		globalShapeHelper = NULL;
	}

	return NULL;
}

void ShapeHelper::purge()
{
	CC_SAFE_DELETE(globalShapeHelper);
}

bool ShapeHelper::init()
{
	bool res = false;
	CCLog("%s", __FUNCTION__);

	Json::Value root;
	Json::Reader reader;
	std::ifstream fin;

	fin.open(resourcePath);
	res = reader.parse(fin, root);

	Json::Value v;		
	rigidBodies = root.get("rigidBodies", v);

	unsigned int size = rigidBodies.size();	
	for (unsigned int i = 0; i < rigidBodies.size(); i++)
	{
		Json::Value v = rigidBodies[i];
		if (v == NULL || v.empty())
			continue;
		
		string shapeName = v["name"].asString();
		string imageName = v["imagePath"].asString();
		
		//b2PolygonShape sh;
		list<b2PolygonShape> sh;
		if (defineShapeFromData(v, &sh))
		{
			Shape* s = new Shape(shapeName, imageName, sh);
			shapes.push_front(s);
		}
	}

	CCLog("Returning %d", res);
	return res;
}

bool ShapeHelper::defineShapeFromData(Json::Value data, list<b2PolygonShape> *shapes)
{
	if (data.empty() || shapes == NULL)
		return false;

	bool res = false;
	Json::Value polys = data["polygons"];

	for (unsigned int i = 0; i < polys.size(); i++)
	{
		Json::Value curr = polys[(unsigned int) i];

		unsigned int numVertices = curr.size();
		b2Vec2* vertices = (b2Vec2*) malloc(numVertices * sizeof(b2Vec2));
		memset(vertices, 0, numVertices * sizeof(b2Vec2));

		for (unsigned int j = 0; j < numVertices; j++)	//	all vertices of current poly
		{
			Json::Value set = curr[j];
			float x = set["x"].asDouble();
			float y = set["y"].asDouble();
			vertices[j].Set(x, y);
		}

		b2PolygonShape ps;
		ps.Set(vertices, numVertices);
		
		shapes->push_front(ps);
		free(vertices);
	}
	
	if (polys.size() > 0)	
		return true;

	return false;
}

bool ShapeHelper::shapeForKey(char* name, CCSize size, __out list<b2PolygonShape> *out)
{
	if (name == NULL || out == NULL)
		return false;

	list<Shape*>::iterator pos;	
	
	//	for all shapes in the list
	for (pos = shapes.begin(); pos != shapes.end(); pos++)
	{
		Shape *s = *(pos);
		if (_stricmp(s->name.c_str(), name) == 0)
		{
			list<b2PolygonShape>::iterator polPos;

			//	for each polygon in shape
			for (polPos = s->polygons.begin(); polPos != s->polygons.end(); polPos++)
			{
				b2PolygonShape current = *(polPos);
			
				unsigned int count = current.m_vertexCount;
				b2Vec2* vert = (b2Vec2*) malloc(sizeof(b2Vec2) * count);

				//	correct vertices for current item size
				for (unsigned int i = 0; i < count; i++)
				{
					float x = current.m_vertices[i].x;
					float y = current.m_vertices[i].y;

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
							
					vert[i].Set(x, y);
				}
			
				b2PolygonShape ps;
				ps.Set(vert, count);
				out->push_front(ps);

				free(vert);
			}

			return true;
		}		
	}

	return false;
}