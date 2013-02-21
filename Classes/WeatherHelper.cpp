#include "WeatherHelper.h"
#include "Settings.h"

bool WeatherHelper::init()
{
	PROFILE_FUNC();

	controllerImage = new CCImage;	
	if (!controllerImage->initWithImageFile(this->controllerPath))
	{
		CCLog("Error initializing weather image data");
		return false;
	}

	CCSize s = CCSizeMake(controllerImage->getWidth(), controllerImage->getHeight());
	controller = new CCTexture2DMutable;
	
	if (!controller->initWithData(controllerImage->getData(), kCCTexture2DPixelFormat_RGBA8888, s.width, s.height, s))
	{
		CCLog("Error creating mutable weather texture");
		delete controllerImage;
		return false;
	}

	//	now init layer
	this->background = CCLayerGradient::create();
	this->backgroundNext = CCLayerGradient::create();
	this->backgroundNext->setOpacity(0);

	//	now set position of controller	
#ifndef START_ONLY_AT_NIGHT
	this->controllerPosition = random(0, this->controllerImage->getWidth() - 1);
#endif

	colorAtThisTime(lastStart, lastEnd);

	this->background->setStartColor(ccc3(lastStart.r, lastStart.g, lastStart.b));
	this->background->setEndColor(ccc3(lastEnd.r, lastEnd.g, lastEnd.b));
	
	this->parent->addChild(this->background);
	this->parent->addChild(this->backgroundNext);

	//	and now - stars			
	this->createStarrySky();
	this->createMoon();
	this->createClouds();	
	

	//	TV scan sprite? Not for long!
	CCSize winSize = CCDirector::sharedDirector()->getWinSizeInPixels();
	CCSprite *tv_scan = CCSprite::create("..\\Resources\\tv_scan.png");
	tv_scan->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	this->parent->addChild(tv_scan, 1000);


	//	My first shader lady and gentleman
	//TintShader *shader = TintShader::create();	
	//this->parent->addChild(shader, 100000);
	//shader->start(this->parent);

	return true;
}

void WeatherHelper::createStarrySky()
{
	PROFILE_FUNC();

	char* starPath = STAR_PATH;
	CCTexture2D *tex = CCTextureCache::sharedTextureCache()->addImage(STAR_PATH);	
	CCSize sajz = CCDirector::sharedDirector()->getWinSizeInPixels();

	starrySky = CCSpriteBatchNode::create(STAR_PATH);
	starrySky->setTag(isNight() ? 100 : 0);

	int scale = 2;
	int numberOfMotherfuckers = random(150 * scale, 400 * scale);

	for (int i = 0; i < numberOfMotherfuckers; i++)
	{
		CCSprite *star = CCSprite::createWithTexture(tex);
		CCPoint pos = ccp(random(-sajz.width * scale, sajz.width * scale), random(-sajz.width * scale, sajz.height * scale));
		star->setPosition(pos);
		float scale = random(0.25f, 0.85f);
		star->setScale(scale);
		if (!isNight())
			star->setOpacity(0);

		//	color the small stars occasionally
		if (scale < 0.4)
		{
			int colR = random(0, 20);
			if (colR == 0)
				star->setColor(ccc3(145, 212, 255));
			else if (colR == 5)
				star->setColor(ccc3(226, 181, 160));
			else if (colR == 10)
				star->setColor(ccc3(105, 91, 135));
		}

		//this->parent->addChild(star);
		starrySky->addChild(star);
	}

	this->parent->addChild(starrySky);
}

void WeatherHelper::createMoon()
{
	PROFILE_FUNC();

	CCSize sajz = CCDirector::sharedDirector()->getWinSizeInPixels();

	moon = CCSprite::create(MOON_RESOURCE);
	CCSize moonSize = moon->getContentSize();

	float x = random(moonSize.width, sajz.width - moonSize.width);
	float y = random(moonSize.height, sajz.height - moonSize.height);

	moon->setPosition(ccp(x, y));
	moonPosition = moon->getPosition();

	moon->setScale(random(0.3f, 1.0f));
	moon->setOpacity(isNight() ? 255 : 0);

	this->parent->addChild(moon);
}

void WeatherHelper::createClouds()
{
	PROFILE_FUNC();

	CCSize size = CCDirector::sharedDirector()->getWinSizeInPixels();
	this->clouds = CCLayer::create();
	this->clouds->setPosition(0, size.height - 200);		
	this->parent->addChild(clouds);

	CCTexture2D *cloudBig = CCTextureCache::sharedTextureCache()->addImage(RESOURCE_DIR "cloudBig.png");
	CCTexture2D *cloudMedium = CCTextureCache::sharedTextureCache()->addImage(RESOURCE_DIR "cloudMedium.png");
	CCTexture2D *cloudSmall = CCTextureCache::sharedTextureCache()->addImage(RESOURCE_DIR "cloudSmall.png");

	bigOnes = CCSpriteBatchNode::create(RESOURCE_DIR "cloudBig.png");
	mediumOnes = CCSpriteBatchNode::create(RESOURCE_DIR "cloudMedium.png");
	smallOnes = CCSpriteBatchNode::create(RESOURCE_DIR "cloudSmall.png");
	float scale = 1;

	ccColor3B color = tintColorAtThisTime();
	for (int i = 0; i < 6 * scale; i++)
	{
		CCSprite* s = CCSprite::createWithTexture(cloudBig);
		float x = random(-200 * scale, size.width * scale);
		float y = random(-100 * scale, 100 * scale);
		s->setPosition(ccp(x, y));
		s->setOpacity(random(160, 220));
		s->setTag(s->getOpacity());
		if (isNight())
			s->setOpacity(HIDDEN_CLOUD_ALPHA);
		s->setScale(random(0.7f, 2.0f));
		s->setColor(color);
		bigOnes->addChild(s);
	}

	color = tintColorAtThisTime(1);
	for (int i = 0; i < random(6, 8) * scale; i++)
	{
		CCSprite* s = CCSprite::createWithTexture(cloudMedium);
		float x = random(-size.width * scale, size.width * scale);
		float y = random(-200 * scale, 100 * scale);
		s->setPosition(ccp(x, y));
		s->setOpacity(random(160, 220));
		s->setTag(s->getOpacity());
		if (isNight())
			s->setOpacity(HIDDEN_CLOUD_ALPHA);
		s->setScale(random(0.7f, 2.0f));
		s->setColor(color);
		mediumOnes->addChild(s);
	}

	color = tintColorAtThisTime(2);
	for (int i = 0; i < random(4, 8) * scale; i++)
	{
		CCSprite* s = CCSprite::createWithTexture(cloudSmall);
		float x = random(-size.width * scale, size.width * scale);
		float y = random(-200 * scale, 100 * scale);
		s->setPosition(ccp(x, y));
		s->setOpacity(random(160, 220));		
		s->setTag(s->getOpacity());
		s->setScale(random(0.7f, 1.2f));
		if (isNight())
			s->setOpacity(0);
		s->setColor(color);
		smallOnes->addChild(s);
	}

	this->clouds->addChild(bigOnes);
	this->clouds->addChild(mediumOnes);
	this->clouds->addChild(smallOnes);

	cloudPos[0] = bigOnes->getPosition();
	cloudPos[1] = mediumOnes->getPosition();
	cloudPos[1] = smallOnes->getPosition();
}

void WeatherHelper::colorAtThisTime(ccColor4B &start, ccColor4B &end)
{
	PROFILE_FUNC();
	if (!this->controller)
		return;
	
	start = this->controller->pixelAt(ccp(controllerPosition, 0));	
	end = this->controller->pixelAt(ccp(controllerPosition, controller->getPixelsHigh() - 1));
}

bool WeatherHelper::isNight()
{
	PROFILE_FUNC();
	int index = getColorPercivedBrigthness(lastStart.r, lastStart.g, lastStart.b);
	bool night = index <= 60;
	return night;
}

int WeatherHelper::tintStrengthAtThisTime(ccColor3B c)
{
	return 255;	
}

ccColor3B WeatherHelper::tintColorAtThisTime(unsigned int index)
{	
	PROFILE_FUNC();
	ccColor3B c;
	float y = 0;

	if (index == 0)
		y = 0;
	else if (index == 1)
		y = 92;
	else if (index == 2)
		y = 112;

	ccColor4B pix = this->controller->pixelAt(ccp(controllerPosition, y));	
	c = ccc3(pix.r, pix.g, pix.b);
	return c;
}

int WeatherHelper::getColorPercivedBrigthness(int r, int g, int b)
{
	PROFILE_FUNC();

	float ret = 
		r * r * 0.241f +
		g * g * 0.691f +
		b * b * 0.068f;	
	return (int) sqrtf(ret);
}

void WeatherHelper::update(float delta)
{
	PROFILE_FUNC();

	if (!initOK)
		return;

	updateTimer += delta;
	if (updateTimer >= ACTION_INTERVAL)
	{	
		updateTimer = 0;

		this->starrySkyNaturalRotation.x += STARS_NATURAL_DROP;
		this->starrySkyNaturalRotation.y += STARS_NATURAL_DROP;

		moonPosition.x += STARS_NATURAL_DROP;
		moonPosition.y += STARS_NATURAL_DROP;

		cloudPos[0].x -= 0.02f * MASTER_SPEED;
		cloudPos[0].y -= 0.002f * MASTER_SPEED;

		cloudPos[1].x += 0.02f * MASTER_SPEED;
		cloudPos[1].y += 0.002f * MASTER_SPEED;

		cloudPos[2].x += 0.02f * MASTER_SPEED;
		cloudPos[2].y += 0.002f * MASTER_SPEED;

		if (backgroundChanging) // thats it
			return;

		this->controllerPosition++;
		firstUpdate = false;

		//	reset when came to the end
		if (this->controllerPosition >= this->controller->getPixelsWide())
		{
			this->controllerPosition = 0;
			return;
		}

		ccColor4B start, end;
		colorAtThisTime(start, end);

		if (!ccc4BEqual(lastStart, start) || !ccc4BEqual(lastEnd, end))
		{
			backgroundChanging = true;			

			this->backgroundNext->setStartColor(ccc3(start.r, start.g, start.b));
			this->backgroundNext->setEndColor(ccc3(end.r, end.g, end.b));			

			CCFadeIn *in = CCFadeIn::create(CHANGE_SPEED);
			CCCallFunc *done = CCCallFunc::create(this, callfunc_selector(WeatherHelper::backgroundDoneChanging));

			this->backgroundNext->runAction(CCSequence::createWithTwoActions(in, done));
			
			lastStart = start;
			lastEnd = end;
						
			//	update clouds
			updateCloudColors();
		}
	}

	//	update stars position
	if (isNight())
	{
		//	increase slowly based on world position
		CCPoint pos = this->worldLayer->getPosition();
		float divider = STARS_PARALAX_DIV;
		float factorX = (pos.x / divider) - starrySkyNaturalRotation.x;
		float factorY = (pos.y / divider) - starrySkyNaturalRotation.y;		
		this->starrySky->setPosition(factorX, factorY);

		divider = MOON_PARALAX_DIV;
		factorX = moonPosition.x + pos.x / divider;	
		factorY = moonPosition.y + pos.y / divider;
		this->moon->setPosition(ccp(factorX, factorY));

		if (starrySky->getTag() == 0)
		{
			flipStarVisibility();
			starrySky->setTag(100);
		}
	}
	else if (starrySky->getTag() == 100)
	{		
		flipStarVisibility();
		starrySky->setTag(0);
	}

	//	position clouds
	if (!isNight())
	{
		CCPoint pos = this->worldLayer->getPosition();
		float div = CLOUDS_1_PARALAX;
		float x = cloudPos[0].x - pos.x / div;
		float y = cloudPos[0].y; //- pos.y / div;
		this->bigOnes->setPosition(x, y);
		
		div = CLOUDS_2_PARALAX;
		x = cloudPos[1].x + pos.x / div;
		y = cloudPos[1].y; //+ pos.y / div;
		this->mediumOnes->setPosition(x, y);

		div = CLOUDS_3_PARALAX;
		x = cloudPos[2].x + pos.x / div;
		y = cloudPos[2].y;	// + pos.y / div;
		this->smallOnes->setPosition(x, y);
	}	

}

void WeatherHelper::flipStarVisibility()
{
	PROFILE_FUNC();

	bool show = starrySky->getTag() == 0;

	//	show / hide all items since BatchSprite knows no opacity
	for (unsigned int i = 0; i < starrySky->getChildrenCount(); i++)
	{
		CCSprite* s = (CCSprite*) starrySky->getChildren()->objectAtIndex(i);
		float ran = random(STARS_FADE_SPEED * 0.2f, STARS_FADE_SPEED);
		if (show)
			s->runAction(CCFadeIn::create(ran));
		else
			s->runAction(CCFadeOut::create(ran));
	}

	//	and do the same for moon
	moon->runAction(CCFadeTo::create(MOON_FADE_SPEED, show ? 255 : 0));

}

void WeatherHelper::backgroundDoneChanging()
{
	PROFILE_FUNC();

	this->background->setStartColor(this->backgroundNext->getStartColor());
	this->background->setEndColor(this->backgroundNext->getEndColor());	
	this->backgroundNext->setOpacity(0);

	backgroundChanging = false;	
	
}

void WeatherHelper::updateCloudColors()
{
	PROFILE_FUNC();

	ccColor3B color = tintColorAtThisTime(0);
	CCArray* bigChildren = bigOnes->getChildren();
	for (unsigned int i = 0; i < bigChildren->count(); i++)
	{
		CCSprite* s = (CCSprite*) bigChildren->objectAtIndex(i);		
		s->runAction(CCTintTo::create(CHANGE_SPEED, color.r, color.g, color.b));

		//	also hide small smiley clouds
		bool hidden = s->getOpacity() == HIDDEN_CLOUD_ALPHA;
		if (hidden && !isNight() || !hidden && isNight())
		{		
			s->runAction(CCFadeTo::create(CHANGE_SPEED, hidden ? s->getTag() : HIDDEN_CLOUD_ALPHA));
		}
	}

	color = tintColorAtThisTime(1);
	CCArray* medChildren = mediumOnes->getChildren();
	for (unsigned int i = 0; i < medChildren->count(); i++)
	{
		CCSprite* s = (CCSprite*) medChildren->objectAtIndex(i);
		s->runAction(CCTintTo::create(CHANGE_SPEED, color.r, color.g, color.b));

		//	also hide small smiley clouds
		bool hidden = s->getOpacity() == HIDDEN_CLOUD_ALPHA;
		if (hidden && !isNight() || !hidden && isNight())
		{		
			s->runAction(CCFadeTo::create(CHANGE_SPEED, hidden ? s->getTag() : HIDDEN_CLOUD_ALPHA));
		}
	}

	color = tintColorAtThisTime(2);
	CCArray* smaChildren = smallOnes->getChildren();
	for (unsigned int i = 0; i < smaChildren->count(); i++)
	{
		CCSprite* s = (CCSprite*) smaChildren->objectAtIndex(i);
		s->runAction(CCTintTo::create(CHANGE_SPEED, color.r, color.g, color.b));
		
		//	also hide small smiley clouds
		bool hidden = s->getOpacity() == 0;
		if (hidden && !isNight() || !hidden && isNight())
		{		
			s->runAction(CCFadeTo::create(CHANGE_SPEED, hidden ? s->getTag() : 0));
		}
	}
}