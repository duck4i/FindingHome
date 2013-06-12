#include "XMLHelper.h"

///
///	XMLHelper static methods
///

xmlNodePtr XMLHelper::findChildNodeWithName(xmlNodePtr parent, char* name)
{
	if (parent == NULL)
		return NULL;
	return parent->FirstChildElement(name);
}

char* XMLHelper::readNodeContent(xmlNodePtr node)
{
	char* ret = NULL;
	if (node)
	{
		tinyxml2::XMLElement* u = node->ToElement();
		if (u)
			ret = (char*) u->GetText();
	}	
	return ret;
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
	const xmlChar* content= (const xmlChar*) readNodeContent(node);
	if (!content)
		return false;
	return xmlStrcasecmp(content, (const xmlChar*) "true") == 0;
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
	/*
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
	*/
}


unsigned int XMLHelper::getChildCount(tinyxml2::XMLNode* parent, const char* tag)
{
	unsigned int count = 0;
	if (parent)
	{
		tinyxml2::XMLNode* nptr = parent->FirstChildElement(tag);
		while (nptr != NULL)
		{
			nptr = nptr->NextSiblingElement(tag);
			++count;
		}
	}
	return count;
}


char* XMLHelper::readNodeAttribute(xmlNodePtr node, const char* name)
{	
	char* at = (char*) node->ToElement()->Attribute(name);//(char*) xmlGetProp(node, (const xmlChar*) name);
	return at;
}

xmlDocPtr XMLHelper::loadFile(const char* filename)
{
	xmlDocPtr p = new tinyxml2::XMLDocument();
	if (p)
	{
		tinyxml2::XMLError e = p->LoadFile(filename);
		if (e == tinyxml2::XML_NO_ERROR)
			return p;
		else
		{
			delete p;
			p = NULL;
		}
	}
	return p;
}