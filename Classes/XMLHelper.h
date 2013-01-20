#ifndef _XML_HELPER_H__
#define _XML_HELPER_H__
#include "LevelLoader.h"

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
};


#endif