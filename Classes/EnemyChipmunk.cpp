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
	m_nodeInfo.size = m_sprite->getContentSize();

	m_sprite->setAnchorPoint(ccp(0, 1)); // position is calculated differently in editor	

	m_nodeInfo.position.x += m_nodeInfo.size.width / 2;
	m_nodeInfo.position.y -= m_nodeInfo.size.height / 2;
	
	return true;
}

void EnemyChipmunk::updatePosition(b2Vec2 pos)
{
	if (m_sprite && m_b2Body)
	{
		if (wasVisible || isReallyVisible())
		{
			wasVisible = true;
			if (abs(m_b2Body->GetLinearVelocity().x) <= 10.0f)
			{
				m_b2Body->ApplyLinearImpulse(b2Vec2(-3.0f, 0), m_b2Body->GetWorldCenter());						
			}
		}
	
		//	update position
		CCPoint p = ccp(WORLD_TO_SCREEN(m_b2Body->GetPosition().x), WORLD_TO_SCREEN(m_b2Body->GetPosition().y));
		p.x -= m_nodeInfo.size.width / 2;
		p.y += m_nodeInfo.size.height / 2;

		m_sprite->setPosition(p);
	}

	if (wasVisible && !isReallyVisible())
	{
		timeSinceInvisible += 1.0f / 60.0f;
		
		if (timeSinceInvisible >= DESTROY_CHIPMUNK_AFTER)
		{
			CCLog("Chipmunk destroyed (expired).");
			removeAtNextUpdate();
		}
	}	

}