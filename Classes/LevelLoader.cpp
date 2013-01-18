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
					//MessageBox(NULL, "Found MAIN layer", "", MB_OK);
				}
				else if (xmlStrcasecmp(name, (const xmlChar*) BACKGROUND_LAYER_NAME) == 0)
				{
					//MessageBox(NULL, "Found BACKGROUND layer", "", MB_OK);
				}								
				layers = layers->next;
			}

			break;	//	we are not interested in custom stuff for now, only layers part
		}
		currNode = currNode->next;
	}

	return success;
}

