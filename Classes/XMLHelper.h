#ifndef _XML_HELPER_H__
#define _XML_HELPER_H__

#include <cocos2d.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

using namespace cocos2d;

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
};


#endif