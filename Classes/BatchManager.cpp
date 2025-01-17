#include "BatchManager.h"

#if 0
static BatchManager* _smanager = NULL;

BatchManager* BatchManager::sharedManager()
{
	if (_smanager == NULL)
		_smanager = new BatchManager();

	return _smanager;
}

BatchManager::BatchManager()
{
}

void BatchManager::purge()
{
	CC_SAFE_DELETE(_smanager);
}
#endif

BatchManager::~BatchManager()
{
	std::list<BatchManagerItem*>::iterator ptr;
	for (ptr = items.begin(); ptr != items.end(); ptr++)
	{
		BatchManagerItem* item = *ptr;
		CC_SAFE_DELETE(item);
	}	
}

bool BatchManager::addItem(GameEntitySprite* entity, CCNode* layer, CCPoint parallax)
{
	char* name = entity->getNodeInfo().texture;
	
	bool found = false;
	std::list<BatchManagerItem*>::iterator item;
	for (item = items.begin(); item != items.end(); item++)
	{
		BatchManagerItem* i = dynamic_cast<BatchManagerItem*>(*item);
		if (!i)
			continue;

		char* iName = i->sprite->getNodeInfo().texture;
		if (xmlStrcasecmp((xmlChar*) iName, (xmlChar*) name) == 0 && parallax.equals(i->parallax) )
		{
			found = true;
			break;
		}
	}
	
	//	Add sprite to batch if exists, or create new batch
	if (found)
		(*item)->batchNode->addChild(entity->getSprite());
	else
	{
		BatchManagerItem* mgr = new BatchManagerItem();

		CCSpriteBatchNode *node = CCSpriteBatchNode::create(name);
		mgr->batchNode = node;
		mgr->sprite = entity;
		mgr->parallax = parallax;
		node->addChild(entity->getSprite());

		items.push_front(mgr);

		layer->addChild(mgr->batchNode);
	}

	return false;
}

