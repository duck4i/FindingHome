#include "EnemyChipmunk.h"

bool EnemyChipmunk::init()
{
	bool ok = GameEntitySprite::init(CHIPMUNK_PATH);
	CCLog("%s OK: %d", __FUNCTION__, ok);
	return ok;
}

bool EnemyChipmunk::postInit()
{
	m_sprite->setPosition(m_nodeInfo.position);	
	m_sprite->setAnchorPoint(ccp(0, 1)); // position is calculated differently in editor
	return true;
}