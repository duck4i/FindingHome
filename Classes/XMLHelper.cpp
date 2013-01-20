#include "XMLHelper.h"

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

void XMLHelper::logNode(xmlNodePtr node)
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