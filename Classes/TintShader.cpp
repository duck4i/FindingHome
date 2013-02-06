//
//  Light.cpp
//  NewLightTest
//
//  Created by roko on 20.08.12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "TintShader.h" 
#include <fstream>

TintShader::TintShader()
{		
}

TintShader::~TintShader()
{
	
}

bool TintShader::start(CCNode* target)
{	
	CCSize screen = CCDirector::sharedDirector()->getWinSizeInPixels();

	CCSprite *s = CCSprite::create(RESOURCE_DIR "dog.png");
	s->setPosition(ccp(screen.width / 2, screen.height / 2));
	this->addChild(s);

	CCGLProgram *shaderProgram = new CCGLProgram();
	shaderProgram->initWithVertexShaderFilename(RESOURCE_DIR "TintShader.vsh", RESOURCE_DIR "TintShader.fsh");
	s->setShaderProgram(shaderProgram);

	shaderProgram->addAttribute(kCCAttributeNameColor, kCCVertexAttribFlag_Color);
	shaderProgram->addAttribute(kCCAttributeNamePosition, kCCVertexAttribFlag_Position);	

	shaderProgram->link();
	shaderProgram->updateUniforms();

	//shaderProgram->use();

	return true;
}

bool TintShader::init()
{
    if (CCLayer::init()) {



		//CCGLProgram *shaderProgram_ = new CCGLProgram();

		/*
		sprite = CCSprite::create(SHADER_IMAGE);
        sprite->setAnchorPoint(CCPointZero);
        sprite->setRotation(90);
		sprite->setPosition(ccp(CCDirector::sharedDirector()->getWinSizeInPixels().width / 2, CCDirector::sharedDirector()->getWinSizeInPixels().height / 2));
        this->addChild(sprite);		

		
		sprite->setShaderProgram(shaderProgram_);

		//shaderProgram_->initWithVertexShaderFilename(RESOURCE_DIR "Shader.vsh", RESOURCE_DIR "Shader.fsh");
		
		
		unsigned long size = 0;
		unsigned char* data =  CCFileUtils::sharedFileUtils()->getFileData(RESOURCE_DIR "Shader.fsh", "r", &size);
		std::string s;
		s.append((char*) data);
		
		shaderProgram_->initWithVertexShaderByteArray(ccPositionTextureA8Color_vert, (const GLchar*) s.c_str());
		

        shaderProgram_->addAttribute(kCCAttributeNamePosition, kCCVertexAttrib_Position);
        shaderProgram_->addAttribute(kCCAttributeNameTexCoord, kCCVertexAttrib_TexCoords);
        shaderProgram_->link();
        shaderProgram_->updateUniforms();
                
        // 3
		timeUniformLocation = glGetUniformLocation(shaderProgram_->getProgram(), "u_time");
        
		// 4
		this->scheduleUpdate();
        
        // 5
		shaderProgram_->use();
		*/
		return true;        
    }

    return false;
}