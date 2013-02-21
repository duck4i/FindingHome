#include "LevelLoader.h"

///
///	LevelLoader Class
///

void LevelLoader::createLevelLayers()
{
	paralaxNode = CCParallaxNode::create();
	paralaxNode->setPosition(0, 0);
	this->worldNode->addChild(paralaxNode);
}

bool LevelLoader::parse()
{
	PROFILE_FUNC();

	bool success = false;

	sharedDoc = xmlReadFile(this->levelPath, "utf-8", XML_PARSE_RECOVER);
	CCAssert(sharedDoc, "Cannot load level file");	

	//	now parse level properties
	parseLevelProperties();
	
	xmlNodePtr currNode = sharedDoc->children->children;
	
	while (currNode)
	{		
		if (xmlStrcasecmp(currNode->name, (const xmlChar*) "Layers") == 0)
		{
			xmlNodePtr layers = currNode->children;

			while (layers)
			{
				bool visible = parseNodeVisible(layers);
				const xmlChar* name = xmlGetProp(layers, (const xmlChar*) "Name");
				bool main = xmlStrcasecmp(name, (const xmlChar*) MAIN_LAYER_NAME) == 0;
				
				//	get paralax info
				CCPoint parallax = ccp(1, 1);	//default
				CCLayer *parent = NULL;
				
				parent = CCLayer::create();

				if (main)
					mainLayer = parent;
				
				xmlNodePtr speed = XMLHelper::findChildNodeWithName(layers, "ScrollSpeed");
				if (speed)
				{
					xmlNodePtr xn = XMLHelper::findChildNodeWithName(speed, "X");
					if (xn)
						parallax.x = XMLHelper::readNodeContentF(xn);
					xmlNodePtr yn = XMLHelper::findChildNodeWithName(speed, "Y");
					if (yn)
						parallax.y = XMLHelper::readNodeContentF(yn);
				}

				paralaxNode->addChild(parent, 0, parallax, ccp(0, 0));						

				if (layers->children)
				{
					xmlNodePtr subLayers = layers->children->next;
					if (subLayers)
					{
						xmlNodePtr ptr = subLayers->children;
						while (ptr)
						{
							parseCurrentNode(ptr, parallax, parent, main);
							ptr = ptr->next;
						}
					}
				}
				layers = layers->next;
			}

			break;	//	we are not interested in custom stuff for now, only layers part
		}
		currNode = currNode->next;
	}

	success = this->playerNode != NULL && this->playerBody != NULL;

	return success;
}

void LevelLoader::parseCurrentNode(xmlNodePtr node, CCPoint parallax, CCLayer* parent, bool isMainLayer)
{
	PROFILE_FUNC();

	xmlChar* nodeName = xmlGetProp(node, (const xmlChar*) "Name");
	xmlChar* nodeType = xmlGetProp(node, (const xmlChar*) "type");

	if (nodeType == NULL)
		return;	//	skipp unknown or closing elements
	
	//CCLog("Processing node: %s with name: %s", nodeType, nodeName);

	//	Read everything we need from XML
	NODEINFO info;	
	info.xmlNode = node;
	info.position = parseNodePosition(node);
	info.size = parseNodeSize(node);
	info.rotation = parseNodeRotation(node);
	info.radius = parseNodeRadius(node);
	info.scale = parseNodeScale(node);
	info.color = parseNodeColor(node);
	info.tint = parseNodeColor(node, true);
	info.texture = parseNodeTexture(node);
	info.rawTexture = parseNodeTexture(node, true);
	info.assetTexture = parseNodeAssetName(node);
	info.flipHorizontally = parseNodeFlip(node);
	info.flipVertically = parseNodeFlip(node, true);
	info.visible = parseNodeVisible(node);	

	if (!info.visible)
	{
		//CCLog("Node hidden. Skipping.");
		return;
	}


	if (xmlStrcasecmp(nodeType, (const xmlChar*) ITEM_TYPE_PLAYER) == 0 && !loadedPlayer)
	{
		loadedPlayer = true;
		info.nodeType = NodeTypePlayer;
		GameEntityPlayer* player = GameEntityPlayer::create(info);		
		if (player)
		{
			player->createBody(this->boxWorld);
			this->mainLayer->addChild(player->getSkin(), 1000000);

			this->playerBody = player->getBody();
			this->playerNode = player->getSkin();

			this->player = player;			
		}
	}
	else if (xmlStrcasecmp(nodeType, (const xmlChar*) ITEM_TYPE_EXIT) == 0)
	{
		info.nodeType = NodeTypeExit;
		xmlNodePtr np = XMLHelper::findChildNodeWithName(info.xmlNode, "NextLevel");
		if (np)		
			info.nextLevel = XMLHelper::readNodeContent(np);		

		GameEntityExit* ge = GameEntityExit::create(info);
		ge->createBody(this->boxWorld);
		ge->createFixture();
	}
	else
	{
		//	select layer to insert it into
		CCNode* layer = parent;
		CCNode* toInsert = NULL;
		GameEntitySprite *sprite;

		//	check type
		if (xmlStrcasecmp(nodeType, (const xmlChar*) ITEM_TYPE_TEXTURE) == 0)
		{		
			info.nodeType = NodeTypeTexture;
			sprite = GameEntitySprite::create(info);
		}	
		if (xmlStrcasecmp(nodeType, (const xmlChar*) ITEM_TYPE_RECTANGLE) == 0)
		{		
			info.nodeType = NodeTypeBlock; 
			sprite = GameEntityRectangle::create(info);
		}
		else if (xmlStrcasecmp(nodeType, (const xmlChar*) ITEM_TYPE_CIRCLE) == 0)
		{
			info.nodeType = NodeTypeCircle;
			sprite = GameEntityCircle::create(info);
		}
	
		//	then instert to view
		if (sprite)
		{
			//layer->addChild(sprite->getSprite());
			BatchManager::sharedManager()->addItem(sprite, layer, parallax);
		
			if (isMainLayer || sprite->getProperties().isSolid() || sprite->getProperties().isCollectable())
				sprite->createBody(this->boxWorld);
		}
	}

	//	since parseNodeTexture allocates we release it here	
	//if (info.texture)
	//	delete [] info.texture;	
}

CCPoint LevelLoader::parseNodePosition(xmlNodePtr node)
{
	CCPoint r(0, 0);	
	xmlNodePtr pos = XMLHelper::findChildNodeWithName(node, "Position");
	if (pos)
	{
		r.x = XMLHelper::readNodeContentF(XMLHelper::findChildNodeWithName(pos, "X"));
		r.y =  (1 /* WE HAVE TO INVERT Y */) - XMLHelper::readNodeContentF(XMLHelper::findChildNodeWithName(pos, "Y"));
	}
	//CCLog("POSITION x: %f y: %f", r.x, r.y);
	return r;
}

CCSize LevelLoader::parseNodeSize(xmlNodePtr node)
{
	CCSize r(0, 0);
	r.width = XMLHelper::readNodeContentF(XMLHelper::findChildNodeWithName(node, "Width"));
	r.height = XMLHelper::readNodeContentF(XMLHelper::findChildNodeWithName(node, "Height"));
	//CCLog("SIZE width: %f height: %f", r.width, r.height);
	return r;
}

float LevelLoader::parseNodeRotation(xmlNodePtr node)
{
	float ret = XMLHelper::readNodeContentF(XMLHelper::findChildNodeWithName(node, "Rotation"));
	//CCLog("Rotation: %f", ret);
	return ret;
}

float LevelLoader::parseNodeRadius(xmlNodePtr node)
{
	float ret = XMLHelper::readNodeContentF(XMLHelper::findChildNodeWithName(node, "Radius"));
	//CCLog("Radius: %f", ret);
	return ret;
}

float LevelLoader::parseNodeScale(xmlNodePtr node)
{
	float ret = XMLHelper::readNodeContentF(XMLHelper::findChildNodeWithName(XMLHelper::findChildNodeWithName(node, "Scale"), "X"));
	if (ret == NULL)
		ret = 1; //	default scale
	//CCLog("Scale: %f", ret);
	return ret;
}

bool LevelLoader::parseNodeFlip(xmlNodePtr node, bool vertical)
{
	char* name = vertical ? "FlipVertically" : "FlipHorizontally";
	bool res = XMLHelper::readNodeContentB(XMLHelper::findChildNodeWithName(node, name));
	return res;
}

bool LevelLoader::parseNodeVisible(xmlNodePtr node)
{	
	const xmlChar* res = xmlGetProp(node, (const xmlChar*) "Visible");
	return xmlStrcasecmp(res, (const xmlChar*) "true") == 0;
}

ccColor4B LevelLoader::parseNodeColor(xmlNodePtr node, bool tint)
{
	ccColor4B ret;
	char* name = tint == true ? "TintColor" : "FillColor";
	xmlNodePtr color = XMLHelper::findChildNodeWithName(node, name);	
	ret.r = XMLHelper::readNodeContentU(XMLHelper::findChildNodeWithName(color, "R"));
	ret.g = XMLHelper::readNodeContentU(XMLHelper::findChildNodeWithName(color, "G"));
	ret.b = XMLHelper::readNodeContentU(XMLHelper::findChildNodeWithName(color, "B"));
	ret.a = XMLHelper::readNodeContentU(XMLHelper::findChildNodeWithName(color, "A"));	
	//CCLog("Color (%s) r: %d g: %d b: %d a: %d", name, ret.r, ret.g, ret.b, ret.a);
	return ret;
}

char* LevelLoader::parseNodeTexture(xmlNodePtr node, bool raw)
{
	char* ret = NULL;
	char* read = XMLHelper::readNodeContent(XMLHelper::findChildNodeWithName(node, "texture_filename"));

	if (read && !raw)
	{
		ret = (char*) malloc(255);
		sprintf(ret, "%s%s", RESOURCE_DIR, read);
	}
	else if (read)
		ret = read;

	//CCLog("Texture: %s", ret);
	return ret;
}

char* LevelLoader::parseNodeAssetName(xmlNodePtr node)
{
	char* ret = NULL;
	char* read = XMLHelper::readNodeContent(XMLHelper::findChildNodeWithName(node, "asset_name"));
	return read;
}


void LevelLoader::parseLevelProperties()
{
	
	LevelProperties::sharedProperties(sharedDoc->children);

}