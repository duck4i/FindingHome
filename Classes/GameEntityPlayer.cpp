#include "GameEntityPlayer.h"

bool GameEntityPlayer::init()
{
	m_skin = CCSprite::create(RESOURCE_PLAYER);
	if (!m_skin)
		return false;

	m_skin->setPosition(m_nodeInfo.position);
	m_skin->setScale(1.3f);

	return true;
}

bool GameEntityPlayer::createBody(b2World *world)
{
	GameEntity::createBody(world);

	b2BodyDef def;

	def.userData = this;
	this->retain();

	def.type = b2_dynamicBody;
	def.position.Set(SCREEN_TO_WORLD(m_nodeInfo.position.x), SCREEN_TO_WORLD(m_nodeInfo.position.y));		

	m_b2Body = world->CreateBody(&def);

	CCSize playerSize = m_skin->getContentSize();

	b2CircleShape doggyShape;
	doggyShape.m_radius = SCREEN_TO_WORLD(playerSize.height * m_skin->getScale() / 2 + 5);
	
	m_b2FixtureDef.density = 3.0f;
	m_b2FixtureDef.friction = 0.8f;
	m_b2FixtureDef.restitution = 0;
	m_b2FixtureDef.shape = &doggyShape;	

	m_b2Body->CreateFixture(&m_b2FixtureDef);
			
	b2FixtureDef groundBody;
	b2PolygonShape groundBodyShape;
	
	playerSize.height += 60;	//	more than player size - so it goes into ground
	groundBodyShape.SetAsBox(SCREEN_TO_WORLD(playerSize.width / 2), SCREEN_TO_WORLD(playerSize.height / 2));

	groundBody.isSensor = true;
	groundBody.shape = &groundBodyShape;

	m_b2Body->CreateFixture(&groundBody);

	return true;
}

void GameEntityPlayer::updatePosition(b2Vec2 pos)
{
	CCPoint posRecalc = ccp(WORLD_TO_SCREEN(pos.x), WORLD_TO_SCREEN(pos.y) - 15);
	m_skin->setPosition(posRecalc);
}

void GameEntityPlayer::updateRotation(float32 angle)
{
	
}

void GameEntityPlayer::updatePlayerMovement()
{

}