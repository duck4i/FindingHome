#include "LevelLoader.h"

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
}