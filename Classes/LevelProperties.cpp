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

	xmlNodePtr currNode = m_node->FirstChildElement("Level");
		
	xmlChar* Name = XMLHelper::readNodeAttribute(currNode, (xmlChar*) "Name");
	xmlChar* Visible = XMLHelper::readNodeAttribute(currNode, (xmlChar*) "Visible");
	xmlChar* WeatherActive = XMLHelper::readNodeAttribute(currNode, (xmlChar*) "WeatherActive");
	xmlChar* CameraZoom = XMLHelper::readNodeAttribute(currNode, (xmlChar*) "CameraZoom");
	xmlChar* PlayerThrust = XMLHelper::readNodeAttribute(currNode, (xmlChar*) "PlayerThrust");
	xmlChar* PlayerJump = XMLHelper::readNodeAttribute(currNode, (xmlChar*) "PlayerJump");
	xmlChar* PlayerMaxSpeed = XMLHelper::readNodeAttribute(currNode, (xmlChar*) "PlayerMaxSpeed");
	xmlChar* PlayerShiftModifier = XMLHelper::readNodeAttribute(currNode, (xmlChar*) "PlayerShiftModifier");
	xmlChar* PlayerMidAirModifier = XMLHelper::readNodeAttribute(currNode, (xmlChar*) "PlayerMidAirModifier");

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


#ifdef CC_PLATFORM_WIN32
			//	Set window title
			 CCEGLView* view = CCEGLView::sharedOpenGLView();
			 HWND window = view->getHWnd();
			 SetWindowText(window, (char*) Name);
#endif

	return true;
}