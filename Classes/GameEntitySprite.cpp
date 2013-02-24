#include "GameEntitySprite.h"

///
///	GameEntitySprite
///	
bool GameEntitySprite::init(char* overidePath)
{	
	bool pre = GameEntity::init();
	if (!pre)
		return false;

	char* path = overidePath != NULL ? overidePath : m_nodeInfo.texture;
	if (path == NULL)
		return false;

	//	check if asset file exists
	if (!doesFileExits(path))
	{
		CCLog("Path does not exist:\t%s", path);
		return false;
	}

	CCTextureCache* cache = CCTextureCache::sharedTextureCache();
	if (cache == NULL)
		return false;

	CCTexture2D* tex = cache->textureForKey(path);
	if (tex == NULL)
		tex = cache->addImage(path);
	
	m_sprite = CCSprite::createWithTexture(tex);
	return m_sprite != NULL;
}

///	
///	Apply style to sprite using NODEINFO structure.
///
bool GameEntitySprite::postInit()
{
	//	params
#ifdef DISABLE_ANTIALISING
	m_sprite->getTexture()->setAliasTexParameters();
#endif

	//position rotation and scale
	m_sprite->setPosition(m_nodeInfo.position);
	m_sprite->setRotation(CC_RADIANS_TO_DEGREES(m_nodeInfo.rotation));
	if (m_nodeInfo.scale)
		m_sprite->setScale(m_nodeInfo.scale);
	
	if (m_nodeInfo.nodeType == NodeTypeTexture)
		m_sprite->setColor(cc4to3(m_nodeInfo.tint));
	
	//	transformation
	if (m_nodeInfo.flipHorizontally)
		m_sprite->runAction(CCFlipX::create(true));
	if (m_nodeInfo.flipVertically)
		m_sprite->runAction(CCFlipY::create(true));

	//	transaprency channel
	if (m_nodeInfo.nodeType == NodeTypeTexture)
		m_sprite->setOpacity(m_nodeInfo.tint.a);
	else
		m_sprite->setOpacity(m_nodeInfo.color.a);

	return GameEntity::postInit();
}

bool GameEntitySprite::createBody(b2World* world)
{
	if ( world == NULL )
		return false;
	
	//	default 
	GameEntity::createBody(world);

	//	fix for texture
	if (m_nodeInfo.nodeType == NodeTypeTexture)
	{
		m_nodeInfo.size.width = m_sprite->getContentSize().width * m_nodeInfo.scale;
		m_nodeInfo.size.height = m_sprite->getContentSize().height * m_nodeInfo.scale;
	}

	//	define and retain
	b2BodyDef def;
	def.userData = this;
	this->retain();

	def.type = m_customProps.isDynamicObject() ? b2_dynamicBody : b2_staticBody;
	def.position.Set(SCREEN_TO_WORLD(m_nodeInfo.position.x), SCREEN_TO_WORLD(m_nodeInfo.position.y));
	def.angle = -1 * m_nodeInfo.rotation;
	
	//	create
	m_b2Body = m_b2World->CreateBody(&def);
	if (m_b2Body == NULL)
		return false;

	//	bouncable
	if (m_customProps.isBouncable())
		m_b2FixtureDef.restitution = 0.5f;
	
	//	collectable
	if (m_customProps.isCollectable())	
		m_b2FixtureDef.isSensor = true;

	return createFixture();
}

void GameEntitySprite::updatePosition(b2Vec2 pos)
{
	bool shouldReposition = m_sprite && m_customProps.isDynamicObject();
	if (shouldReposition)
	{
		CCPoint posRecalc = ccp(WORLD_TO_SCREEN(pos.x), WORLD_TO_SCREEN(pos.y));
		m_sprite->setPosition(posRecalc);
	}

	/*
	//	Performance optimization - do not draw (set invisible) items outside of screen
	bool isVisible = true;
	LevelProperties* pr = LevelProperties::sharedProperties();
	if (pr)
	{
		CCNode* world = pr->WorldLayer;
		if (world)
		{			
			CCPoint pos = world->convertToWorldSpace(m_sprite->getPosition());
			CCSize screen = CCDirector::sharedDirector()->getWinSizeInPixels();
			if (pos.x > screen.width || pos.x < 0 || pos.y > screen.height || pos.y < 0)
				isVisible = false;

			this->m_sprite->setVisible(isVisible);
		}
	}
	*/
}

void GameEntitySprite::updateRotation(float32 angle)
{
	bool shouldUpdateRotation = m_sprite && m_customProps.isDynamicObject();
	if (shouldUpdateRotation)
		m_sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(angle));
}

bool GameEntitySprite::createFixture()
{	
	std::list<b2PolygonShape> shapes;
	if (ShapeHelper::sharedHelper()->shapeForKey(m_nodeInfo.assetTexture, m_nodeInfo.size, &shapes))
	{
		//	have to recalculate total weight?
		std::list<b2PolygonShape>::iterator pos;
		for (pos = shapes.begin(); pos != shapes.end(); pos++)
		{
			b2PolygonShape p = *(pos);
			m_b2FixtureDef.shape = &p;
			m_b2Body->CreateFixture(&m_b2FixtureDef);
		}
		return true;
	}
	else
	{
		b2PolygonShape ps;
		ps.SetAsBox(SCREEN_TO_WORLD(m_nodeInfo.size.width / 2), SCREEN_TO_WORLD(m_nodeInfo.size.height / 2));		
		m_b2FixtureDef.shape = &ps;
		b2Fixture* b = m_b2Body->CreateFixture(&m_b2FixtureDef);
		return b != NULL;
	}
	
	return false;
}

void GameEntitySprite::bodyRemovedFromWorld()
{
	GameEntity::bodyRemovedFromWorld();

	//	remove collectable sprite
	if (this->m_sprite && this->m_customProps.isCollectable())
	{
		float duration = 0.4f;
		float move = 50.0f;

		this->m_sprite->runAction(CCMoveBy::create(duration, ccp(0, move)));
		this->m_sprite->runAction(CCFadeOut::create(duration));

		//	remove from layer world
	}
}