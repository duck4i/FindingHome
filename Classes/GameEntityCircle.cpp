#include "GameEntityCircle.h"

///
///	GameEntityCircle
///
bool GameEntityCircle::init()
{
	return GameEntitySprite::init(RESOURCE_CIRCLE);
}

bool GameEntityCircle::postInit()
{
	//m_sprite->getTexture()->setAliasTexParameters();

	float width = m_sprite->getContentSize().width;
	m_nodeInfo.scale =  m_nodeInfo.radius * 2 / width; //	diametar is 2xradius

	//	add color
	m_sprite->setColor(ccc3(m_nodeInfo.color.r, m_nodeInfo.color.g, m_nodeInfo.color.b));

	strcpy_s(m_nodeInfo.texture, RESOURCE_CIRCLE);
	m_nodeInfo.assetTexture = "circle.png";
	m_nodeInfo.rawTexture = m_nodeInfo.assetTexture;

	return GameEntitySprite::postInit();
}

bool GameEntityCircle::createFixture()
{
	b2CircleShape cs;
	cs.m_radius = SCREEN_TO_WORLD(m_nodeInfo.radius);
	m_b2FixtureDef.shape = &cs;

	b2Fixture* b = m_b2Body->CreateFixture(&m_b2FixtureDef);
	return b != NULL;
}