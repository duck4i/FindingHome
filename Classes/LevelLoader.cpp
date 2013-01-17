#include "LevelLoader.h"

bool LevelLoader::parse()
{
	bool success = false;

	sharedDoc = xmlReadFile(this->levelPath, "utf-8", XML_PARSE_RECOVER);
	CCAssert(sharedDoc, "Cannot load level file");


	return success;
}

