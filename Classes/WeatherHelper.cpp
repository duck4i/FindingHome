#include "WeatherHelper.h"
#include "Settings.h"

bool WeatherHelper::init()
{
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

	//CCLayerColor *l = CCLayerColor::create(ccc4(255, 255, 255, 255));
	//this->parent->addChild(l);
	///this->parent(

	//	now set position of controller		
	//this->controllerPosition = controller->getPixelsWide() / 2;
	this->background->setCompressedInterpolation(true);	
	colorAtThisTime(lastStart, lastEnd);	
			
	this->background->setStartColor(ccc3(lastStart.r, lastStart.b, lastStart.g));
	this->background->setEndColor(ccc3(lastEnd.r, lastEnd.g, lastEnd.b));

	this->parent->addChild(this->background);
	this->parent->addChild(this->backgroundNext);

	//	tinting layer
	ccColor3B col = tintColorAtThisTime();
	this->topTintLayer = CCLayerColor::create(ccc4(col.r, col.g, col.b,	tintStrengthAtThisTime(col)));

	//ccBlendFunc blend;
	//blend.src = GL_SRC_COLOR;
	//blend.dst = GL_SRC_COLOR;	
	//this->topTintLayer->setBlendFunc(blend);

	this->worldLayer->addChild(this->topTintLayer, 10000);


	//	and now - stars
	this->createStarrySky();

	return true;
}

void WeatherHelper::createStarrySky()
{
	char* starPath = STAR_PATH;
	CCTexture2D *tex = CCTextureCache::sharedTextureCache()->addImage(STAR_PATH);	
	CCSize sajz = CCDirector::sharedDirector()->getWinSizeInPixels();

	starrySky = CCSpriteBatchNode::create(STAR_PATH);

	int numberOfMotherfuckers = random(100, 400);

	for (int i = 0; i < numberOfMotherfuckers; i++)
	{
		CCSprite *star = CCSprite::createWithTexture(tex);
		CCPoint pos = ccp(random(-sajz.width, sajz.width), random(-sajz.width, sajz.height));
		star->setPosition(pos);
		float scale = random(0.25, 0.85);
		star->setScale(scale);

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

	this->parent->addChild(starrySky, 0);
}

void WeatherHelper::colorAtThisTime(ccColor4B &start, ccColor4B &end)
{
	if (!this->controller)
		return;
	
	start = this->controller->pixelAt(ccp(controllerPosition, 0));	
	end = this->controller->pixelAt(ccp(controllerPosition, controller->getPixelsHigh() - 1));
}

bool WeatherHelper::isNight()
{
	return this->controllerPosition < 66 || this->controllerPosition > (unsigned int) (this->controllerImage->getWidth() - 66) ;
}

int WeatherHelper::tintStrengthAtThisTime(ccColor3B c)
{	
	if (isNight())
		return 160;	//	fix for nights

	int colorBrightness = getColorPercivedBrigthness(c.r, c.g, c.b);
	
	//	min 20, max 130
	int ret = min(80, max(255 - colorBrightness, 20));
	return ret;
}

ccColor3B WeatherHelper::tintColorAtThisTime()
{	
	if (isNight())
		return ccc3(lastStart.r, lastStart.g, lastStart.b);

	ccColor3B c;
	//if (controllerPosition > (unsigned int)(controllerImage->getWidth() / 2) )
	//	c = ccc3(lastStart.r, lastStart.g, lastStart.b);
	//else
		c = ccc3(lastEnd.r, lastEnd.g, lastEnd.b);
	return c;
}

int WeatherHelper::getColorPercivedBrigthness(int r, int g, int b)
{
	float ret = 
		r * r * 0.241f +
		g * g * 0.691f +
		b * b * 0.068f;	
	return (int) sqrtf(ret);
}

void WeatherHelper::update(float delta)
{
	if (!initOK)
		return;

	updateTimer += delta;

	float actionInterval = 0.30f; // each seconds 1 pixel move. That means (for 380 width) complete cycle each ~6 minutes.	

	if ( !backgroundChanging && (updateTimer >= actionInterval) )
	{
		updateTimer = 0;
		this->controllerPosition++;
		firstUpdate = false;

		//	reset when came to the end
		if (this->controllerPosition >= this->controller->getPixelsWide())
		{
			this->controllerPosition = 0;
			this->updateTimer = 0;
			return;
		}

		ccColor4B start, end;
		colorAtThisTime(start, end);

		if (!ccc4BEqual(lastStart, start) || !ccc4BEqual(lastEnd, end))
		{
			backgroundChanging = true;

			float changeTime = 10.0f;
			this->backgroundNext->setOpacity(0);
			this->backgroundNext->setStartColor(ccc3(start.r, start.b, start.g));
			this->backgroundNext->setEndColor(ccc3(end.r, end.g, end.b));

			CCFadeTo *in = CCFadeTo::create(changeTime, 255);
			CCFadeTo *out = CCFadeTo::create(changeTime, 0);			
			CCCallFunc *done = CCCallFunc::create(this, callfunc_selector(WeatherHelper::backgroundDoneChanging));

			this->backgroundNext->runAction(CCSequence::createWithTwoActions(in, done));
			this->background->runAction(out);
			
			//	tint the world
			ccColor3B tintCol = tintColorAtThisTime();						
			int ts = tintStrengthAtThisTime(tintCol);

			CCTintTo *tint = CCTintTo::create(changeTime, tintCol.r, tintCol.g, tintCol.b);
			CCFadeTo *tintStrength = CCFadeTo::create(changeTime, ts);

			//	does not work good if we do it above all layers
			//this->worldLayer->runAction(tint);
			//this->worldLayer->runAction(tintStrength);
			this->topTintLayer->runAction(tint);
			this->topTintLayer->runAction(tintStrength);
			//Color colorTint = Blend(			
			/*
			CCArray* children = this->worldLayer->getChildren();
			int count = children->count();
			for (int i = 0; i < children->count(); i++)
			{
				CCObject* o = children->objectAtIndex(i);
				CCNode* c = (CCNode*) o;

				if (c->getChildrenCount() > 0)
				{
					CCArray *subs = c->getChildren();
					for (int j = 0; j < subs->count(); j++)
					{
						CCNode *o2 =  (CCNode*) subs->objectAtIndex(j);

						CCSprite* s = dynamic_cast<CCSprite*>(o2);
						CCLayerColor* l = dynamic_cast<CCLayerColor*>(o2);

						ccBlendFunc blend;
						blend.src = GL_SRC_ALPHA;
						blend.dst = GL_ONE;
						if (s)
							s->setBlendFunc(blend);
						if (l)
							l->setBlendFunc(blend);
						//if (s)
						//	s->runAction(CCTintTo::create(changeTime, tintCol.r, tintCol.g, tintCol.b));
						//else if (l)
						//	l->runAction(CCTintTo::create(changeTime, tintCol.r, tintCol.g, tintCol.b));						
						
					}
				}
				else
				{
					c->runAction(tint);
					c->runAction(tintStrength);
				}
			}
			*/
			

			lastStart = start;
			lastEnd = end;			
		}
	}

	//	update stars position
	CCPoint pos = this->worldLayer->getPosition();
	float divider = 50;
	float factorX = pos.x / divider;
	float factorY = pos.y / divider;
	//bool ok = true;
	this->starrySky->setPosition(factorX, factorY);
}

void WeatherHelper::backgroundDoneChanging()
{	
	this->background->stopAllActions();
	this->background->setStartColor(this->backgroundNext->getStartColor());
	this->background->setEndColor(this->backgroundNext->getEndColor());
	this->background->setOpacity(255);
	//this->backgroundNext->setOpacity(0);

	backgroundChanging = false;	
}