#include "GameEntityCollisionPath.h"

bool GameEntityCollisionPath::createBody(b2World* world)
{		
	GameEntity::createBody(world);
	m_b2Body = world->CreateBody(&m_b2BodyDef);
	if (m_b2Body)
	{
		this->retain();
		return true;
	}

	return false;
}

bool GameEntityCollisionPath::createFixture()
{
	//	parse node structures to create a chain shape
	xmlNodePtr root = m_nodeInfo.xmlNode;
	xmlNodePtr points = XMLHelper::findChildNodeWithName(root, "LocalPoints");
	
	unsigned int childCount = xmlChildElementCount(points);
	xmlNodePtr child = points->children;

	b2Vec2 *vecarray = (b2Vec2*) malloc(sizeof(b2Vec2) * childCount);
	if (!vecarray)
		return false;

	unsigned int counter = 0;
	while (child)
	{
		xmlNodePtr x = XMLHelper::findChildNodeWithName(child, "X");
		xmlNodePtr y = XMLHelper::findChildNodeWithName(child, "Y");
		
		if (x && y)
		{
			float xv = SCREEN_TO_WORLD(XMLHelper::readNodeContentF(x));
			float yv = SCREEN_TO_WORLD(1.0 - XMLHelper::readNodeContentF(y));	//invert Y 

			b2Vec2 vec = b2Vec2(xv, yv);
			vecarray[counter++] = vec;
		}		

		child = child->next;
	}
	
	b2ChainShape cs;
	cs.CreateChain(vecarray, counter);	
	m_b2FixtureDef.shape = &cs;

	b2Fixture *fx = m_b2Body->CreateFixture(&m_b2FixtureDef);

	free(vecarray);
	return fx != NULL;
}