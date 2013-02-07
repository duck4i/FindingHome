#include "CustomProperty.h"

bool CustomProperties::parseFromNode(xmlNodePtr node)
{
	//	skip if no properties 
	xmlNodePtr customProps = XMLHelper::findChildNodeWithName(node, "CustomProperties");
	if (!customProps || xmlChildElementCount(customProps) == 0)
		return false;

	customProps = customProps->children;
	while (customProps)
	{		
		xmlChar* name = xmlGetProp(customProps, (const xmlChar*) "Name");
		xmlChar* type = xmlGetProp(customProps, (const xmlChar*) "Type");
		
		//	skip unknowns
		if (type != NULL && name != NULL)
		{
			//MessageBox(NULL, (char*) name, (char*) type, MB_OK);

			//	check for helper types
			if (xmlStrcasecmp(name, (const xmlChar*) PLAYER_TAG_NAME) == 0)
				foundPropNamedPlayer = true;
			//	cannot be player and finish so we else if here
			else if (xmlStrcasecmp(name, (const xmlChar*) FINISH_TAG_NAME) == 0)
				foundPropNamedFinish = true;
			
			if (xmlStrcasecmp(name, (const xmlChar*) DYNAMIC_TAG_NAME) == 0)
				foundPropNamedDynamic = true;
			if (xmlStrcasecmp(name, (const xmlChar*) BOUNCE_TAG_NAME) == 0)
				foundPropNamedBounce = true;
			if (xmlStrcasecmp(name, (const xmlChar*) COLLECTABLE_TAG_NAME) == 0)
				foundPropNamedCollectable = true;


		}

		customProps = customProps->next;
	}

	return true;
}