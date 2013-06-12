#ifndef _XML_HELPER_H__
#define _XML_HELPER_H__

#include <cocos2d.h>
#include <tinyxml2.h>

using namespace cocos2d;

typedef char					xmlChar;
typedef tinyxml2::XMLNode		xmlNode ;
typedef xmlNode*				xmlNodePtr;
typedef tinyxml2::XMLDocument*	xmlDocPtr;

//	Define comparng mthood
typedef int (*LEGACY_BYPASS)(const char*, const char*);
static const LEGACY_BYPASS xmlStrcasecmp = _strcmpi;

//
//	XML helper utilities class. Makes XML code easier to read and work with.
//
class XMLHelper
{
public:
	static xmlNodePtr	findChildNodeWithName(xmlNodePtr parent, char* name);

	static char*		readNodeContent(xmlNodePtr node);

	static float		readNodeContentF(xmlNodePtr node);
	static bool			readNodeContentB(xmlNodePtr node);
	static unsigned int	readNodeContentU(xmlNodePtr node);

	static void			logNode(xmlNodePtr node);

	static unsigned int getChildCount(tinyxml2::XMLNode* parent, const char* tag  = NULL);
	static char*		readNodeAttribute(xmlNodePtr node, const char* name);
	static xmlDocPtr	loadFile(const char* filename);
};


#endif