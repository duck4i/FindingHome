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

	
	BatchManager();

public:
	
	list<BatchManagerItem*> items;	

	static BatchManager* sharedManager();

	bool addItem(GameEntitySprite* entity, CCNode* layer, CCPoint parallax);


	~BatchManager();
};


#endif