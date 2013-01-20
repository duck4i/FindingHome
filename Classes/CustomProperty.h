#ifndef _CUSTOM_PROPERTY_H_
#define _CUSTOM_PROPERTY_H_

#include "LevelLoader.h"

//	Custom property mappings
//	We wont check custom level property type, only if it exists. 
//	Maybe later if needed (for message boards, etc...) we can add value check for those types.

#define PLAYER_TAG_NAME		"Player"
#define FINISH_TAG_NAME		"Finish"
#define DYNAMIC_TAG_NAME	"Dynamic"	//	dynamic Box2D objects

/*
<Property Name="obicanItem" Type="Item" Description="">Rectangle_0010</Property>
<Property Name="player" Type="bool" Description="">
    <boolean>false</boolean>
</Property>
<Property Name="obicanText" Type="string" Description="">
    <string>helooooo</string>
</Property>
*/

class CustomProperty
{
private:	
	char name[255];	
	char description[512];
public:
	CustomProperty(char* name, char* desc)
	{
		memcpy(this->name, name, sizeof(name));
		memcpy(this->description, desc, sizeof(desc));
	}

	virtual char* getName() { return name; }
	virtual char* getDescription() { return description; }
};

class CustomPropertyBool : CustomProperty
{
private:
	bool m_val;	
public:
	CustomPropertyBool(char* name, char* desc, bool val) : CustomProperty(name, desc)
	{
		m_val = val;
	}	
	bool getValue() { return m_val; }
};

class CustomPropertyText : CustomProperty
{
private:
	char text[1024];

};

class CustomProperties
{
private:
	bool foundPropNamedPlayer;
	bool foundPropNamedFinish;	
	bool foundPropNamedDynamic;
	

public:

	CustomProperties()
	{
		foundPropNamedPlayer = false;
		foundPropNamedFinish = false;
		foundPropNamedDynamic = false;		
	}
		
	std::vector<CustomProperty> properties;	

	bool parseFromNode(xmlNodePtr node);	

	//	few helpers
	bool isDynamicObject() { return foundPropNamedDynamic; }
	bool isMessageBoard();
	
	bool isPlayerObject() { return foundPropNamedPlayer; }
	bool isFinishObject() { return foundPropNamedFinish; }


};

#endif