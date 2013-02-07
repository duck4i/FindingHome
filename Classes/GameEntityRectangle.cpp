#include "GameEntityRectangle.h"

///
///	GameEntityRectangle
///
bool GameEntityRectangle::init()
{
	return GameEntitySprite::init(RESOURCE_BLOCK);
}

bool GameEntityRectangle::preInit()
{
	m_nodeInfo.position.x += m_nodeInfo.size.width / 2.0f;
	m_nodeInfo.position.y -= m_nodeInfo.size.height / 2.0f;

	return true;
}

bool GameEntityRectangle::postInit()
{
	float sx = m_nodeInfo.size.width / m_sprite->getContentSize().width;
	float sy = m_nodeInfo.size.height / m_sprite->getContentSize().height;
	
	//	override scale
	m_sprite->setScaleX(sx);
	m_sprite->setScaleY(sy);
	m_nodeInfo.scale = 0;

	//	add color
	m_sprite->setColor(ccc3(m_nodeInfo.color.r, m_nodeInfo.color.g, m_nodeInfo.color.b));

	return GameEntitySprite::postInit();	
}
