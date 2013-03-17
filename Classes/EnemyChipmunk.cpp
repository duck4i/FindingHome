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
	m_sprite->setScale(1.5f);
	return true;
}