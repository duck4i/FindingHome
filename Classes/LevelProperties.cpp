#include "LevelProperties.h"

LevelProperties* _sLevelProperties = NULL;

LevelProperties* LevelProperties::sharedProperties(xmlNodePtr node)
{
	if (_sLevelProperties == NULL && node != NULL)
	{
		_sLevelProperties = new LevelProperties(node);
		if (!_sLevelProperties->init())
			CC_SAFE_DELETE(_sLevelProperties);		
	}
	return _sLevelProperties;
}

void LevelProperties::purge()
{
	CC_SAFE_DELETE(_sLevelProperties);
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
			xmlChar* PlayerThrust = xmlGetProp(currNode, (xmlChar*) "PlayerThrust");
			xmlChar* PlayerJump = xmlGetProp(currNode, (xmlChar*) "PlayerJump");
			xmlChar* PlayerMaxSpeed = xmlGetProp(currNode, (xmlChar*) "PlayerMaxSpeed");
			xmlChar* PlayerShiftModifier = xmlGetProp(currNode, (xmlChar*) "PlayerShiftModifier");
			xmlChar* PlayerMidAirModifier = xmlGetProp(currNode, (xmlChar*) "PlayerMidAirModifier");

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

			if (PlayerThrust)
				this->PlayerThrust = atof((char*) PlayerThrust);
			if (PlayerJump)
				this->PlayerJump = atof((char*) PlayerJump);
			if (PlayerMaxSpeed)
				this->PlayerMaxSpeed = atof((char*) PlayerMaxSpeed);
			
			if (PlayerShiftModifier)
				this->PlayerShiftModifier = atof((char*) PlayerShiftModifier);
			if (PlayerMidAirModifier)
				this->PlayerMidAirModifier = atof((char*) PlayerMidAirModifier);

			break;
		}
		currNode = currNode->next;
	}


	return true;
}