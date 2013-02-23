#include "LevelProperties.h"

static LevelProperties* _sLevelProperties;

LevelProperties* LevelProperties::sharedProperties(xmlNodePtr node)
{
	if (_sLevelProperties == NULL && node != NULL)
	{
		_sLevelProperties = new LevelProperties(node);
		bool ok = _sLevelProperties->init();
		if (!ok)
		{
			delete _sLevelProperties;
		}
	}
	return _sLevelProperties;
}

void LevelProperties::purge()
{
	if (_sLevelProperties)
	{
		delete _sLevelProperties;
		_sLevelProperties = NULL;
	}
}

LevelProperties::~LevelProperties()
{	
}

//Name="Tutorial Level" Visible="true" WeatherActive="true" 
//CameraZoom="0.5" PlayerSpeed="0" PlayerJump="0" PlayerShiftModifier="0"

bool LevelProperties::init()
{
	xmlNodePtr currNode = m_node;
	while (currNode)
	{
		if (xmlStrcasecmp(currNode->name, (const xmlChar*) "Level") == 0)
		{
			xmlChar* Name = xmlGetProp(currNode, (xmlChar*) "Name");
			xmlChar* Visible = xmlGetProp(currNode, (xmlChar*) "Visible");
			xmlChar* WeatherActive = xmlGetProp(currNode, (xmlChar*) "WeatherActive");
			xmlChar* CameraZoom = xmlGetProp(currNode, (xmlChar*) "CameraZoom");
			xmlChar* PlayerSpeed = xmlGetProp(currNode, (xmlChar*) "PlayerSpeed");
			xmlChar* PlayerJump = xmlGetProp(currNode, (xmlChar*) "PlayerJump");
			xmlChar* PlayerShiftModifier = xmlGetProp(currNode, (xmlChar*) "PlayerShiftModifier");

#ifdef CC_PLATFORM_WIN32
			//	Set window title
			 CCEGLView* view = CCEGLView::sharedOpenGLView();
			 HWND window = view->getHWnd();
			 SetWindowText(window, (char*) Name);
#endif

			if (STRING_TRUE(WeatherActive))
				this->WeatherActive = true;
			
			if (CameraZoom)
				this->CameraZoom = atof((char*) CameraZoom);
			if (PlayerSpeed)
				this->PlayerSpeed = atof((char*) PlayerSpeed);
			if (PlayerJump)
				this->PlayerJump = atof((char*) PlayerJump);
			if (PlayerShiftModifier)
				this->PlayerShiftModifier = atof((char*) PlayerShiftModifier);

			break;
		}
		currNode = currNode->next;
	}


	return true;
}