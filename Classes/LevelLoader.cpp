#include "LevelLoader.h"

///
///	XMLHelper static methods
///

xmlNodePtr XMLHelper::findChildNodeWithName(xmlNodePtr parent, char* name)
{
	if (parent == NULL)
		return NULL;

	xmlNodePtr subs = parent->children, ret = NULL;
	while (subs != NULL)
	{
		if (xmlStrcasecmp(subs->name, (const xmlChar*) name) == 0)
		{
			ret = subs;
			break;
		}
		subs = subs->next;
	}
	return ret;
}

char* XMLHelper::readNodeContent(xmlNodePtr node)
{
	if (node == NULL)
		return NULL;
	return (char*) xmlNodeGetContent(node);
}

float XMLHelper::readNodeContentF(xmlNodePtr node)
{
	char* n = readNodeContent(node);
	if (n)
		return atof(n);
	return NULL;
}

bool XMLHelper::readNodeContentB(xmlNodePtr node)
{
	return xmlStrcasecmp((const xmlChar*) readNodeContent(node), (const xmlChar*) "true") == 0;
}

unsigned int XMLHelper::readNodeContentU(xmlNodePtr node)
{
	unsigned int ret = 0;
	char* start = readNodeContent(node);
	char* end = 0;
	if (start == NULL)
		return 0;
	ret = strtoul(start, &end, 10);
	return ret;
}

///
///	LevelLoader Class
///

void LevelLoader::logNode(xmlNodePtr node)
{
	bool consoleOutput = false;

	char* name = (char*) node->name;
	std::string s = "";

	for (xmlAttrPtr attr = node->properties; attr != NULL; attr = attr->next)
	{
		std::string o = "";
		o.append((char*) attr->name);
		o.append(": ");
		o.append((char*) attr->children->content);
		s.append(o);
		s.append("\r\n");
	}

	if (!consoleOutput)
		MessageBox(NULL, s.c_str(), name, MB_OK);
	else
		CCLog("XML Node log: Name: %s Properties: %s", name, s.c_str());
}

void LevelLoader::createLevelLayers()
{
	//	do not change the order of how we create layers, it will affect zOrder
	this->backgroundLayer = CCLayer::create();
	this->worldNode->addChild(this->backgroundLayer);

	this->mainLayer = CCLayer::create();
	this->worldNode->addChild(this->mainLayer);	
}

bool LevelLoader::parse()
{
	bool success = false;

	sharedDoc = xmlReadFile(this->levelPath, "utf-8", XML_PARSE_RECOVER);
	CCAssert(sharedDoc, "Cannot load level file");	
	
	xmlNodePtr currNode = sharedDoc->children->children;
	
	while (currNode)
	{		
		if (xmlStrcasecmp(currNode->name, (const xmlChar*) "Layers") == 0)
		{						
			xmlNodePtr layers = currNode->children;
			while (layers)
			{
				const xmlChar* name = xmlGetProp(layers, (const xmlChar*) "Name");
				if (xmlStrcasecmp(name, (const xmlChar*) MAIN_LAYER_NAME) == 0)
				{
					xmlNodePtr mainLayers = layers->children->next;
					short count = xmlChildElementCount(mainLayers);
					CCLog("Found main layer with %d children", count);

					unsigned int zOrder = 0;
					xmlNodePtr mainLayerChild = mainLayers->children;
					while (mainLayerChild)
					{
						parseCurrentNode(mainLayerChild, 0, zOrder++);
						mainLayerChild = mainLayerChild->next;
					}
				}
				else if (xmlStrcasecmp(name, (const xmlChar*) BACKGROUND_LAYER_NAME) == 0)
				{
					xmlNode *backLayers = layers->children->next;
					short count = xmlChildElementCount(backLayers);
					CCLog("Found background layer with %d children", count);

					unsigned int zOrder = 0;
					xmlNodePtr backLayerChild = backLayers->children;
					while (backLayerChild)
					{						
						parseCurrentNode(backLayerChild, 1, zOrder++);
						backLayerChild = backLayerChild->next;
					}
				}
				layers = layers->next;
			}

			break;	//	we are not interested in custom stuff for now, only layers part
		}
		currNode = currNode->next;
	}

	return success;
}

void LevelLoader::parseCurrentNode(xmlNodePtr node, unsigned int type, unsigned int zOrder)
{
	xmlChar* nodeName = xmlGetProp(node, (const xmlChar*) "Name");
	xmlChar* nodeType = xmlGetProp(node, (const xmlChar*) "type");	

	if (nodeType == NULL)
		return;	//	skipp unknown or closing elements
	
	CCLog("Processing node: %s with name: %s", nodeType, nodeName);

	//	Read everything we need from XML
	CCPoint nodePosition = parseNodePosition(node);
	CCSize nodeSize = parseNodeSize(node);
	float nodeRotation = parseNodeRotation(node);
	float nodeRadius = parseNodeRadius(node);
	float nodeScale = parseNodeScale(node);
	ccColor4B nodeColor = parseNodeColor(node);
	ccColor4B nodeColorTint = parseNodeColor(node, true);
	char* nodeTexture = parseNodeTexture(node);

	//	select layer to insert it into
	CCNode* layer = type == 0 ? this->mainLayer : this->backgroundLayer;
	CCNode* toInsert = NULL;

	//	NOW DO ACTUAL WORLD CREATIONG -- LIKE A BOSS
	if (xmlStrcasecmp(nodeType, (const xmlChar*) ITEM_TYPE_RECTANGLE) == 0)
	{
		CCLayerColor *a = CCLayerColor::create(nodeColor);
		a->setContentSize(nodeSize);
		
		//	anchor point is always in (0,0) for layer, but our position is mapped to (0.5, 0.5), or element center
		//	compensate (sounds awfully like somethign said in star trek :)		
		nodePosition.y -= nodeSize.height;

		toInsert = a;
	}
	else if (xmlStrcasecmp(nodeType, (const xmlChar*) ITEM_TYPE_CIRCLE) == 0)
	{

	}
	else if (xmlStrcasecmp(nodeType, (const xmlChar*) ITEM_TYPE_TEXTURE) == 0)
	{
		toInsert = CCSprite::create(nodeTexture);
	}

	if (toInsert)
	{
		toInsert->setPosition(nodePosition);
		toInsert->setRotation(CC_RADIANS_TO_DEGREES(nodeRotation));
		toInsert->setScale(nodeScale);
		layer->addChild(toInsert, zOrder);
	}

	//	since parseNodeTexture allocates we release it here
	delete [] nodeTexture;
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

char* LevelLoader::parseNodeTexture(xmlNodePtr node)
{
	char* ret = NULL;
	char* read = XMLHelper::readNodeContent(XMLHelper::findChildNodeWithName(node, "texture_filename"));

	if (read)
	{
		ret = (char*) malloc(255);
		sprintf(ret, "%s%s", RESOURCE_DIR, read);
	}
	CCLog("Texture: %s", ret);
	return ret;
}