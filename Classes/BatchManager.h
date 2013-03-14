#ifndef _BATCH_MANAGER_H_
#define _BATCH_MANAGER_H_

#include "GameEntities.h"
#include <list>
#include <string>

using namespace std;

class BatchManagerItem : CCObject
{
public:

	CCSpriteBatchNode* batchNode;
	GameEntitySprite* sprite;
	CCPoint parallax;
};

class BatchManager 
{
private:

	list<BatchManagerItem*> items;	

public:
#if 0	
	static BatchManager* sharedManager();
	static void purge();
#endif

	bool addItem(GameEntitySprite* entity, CCNode* layer, CCPoint parallax);

	BatchManager()
	{
	}
	~BatchManager();
};


#endif