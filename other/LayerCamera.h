/*
 *  LayerCamera.h
 *  NinjaGames
 *
 *  Created by João Caxaria on 4/26/09.
 *  Copyright 2009 Feel Fine Games. All rights reserved.
 *
 */
#import "cocos2d.h"
#import "ICamera.h"

@interface LayerCamera : Layer<ICamera>
{
	CocosNode* targetLayer; 
	CGSize layerSize;
	CGSize viewportSize;
}

-(id) initForLayer:(CocosNode*) target layerSize:(CGSize) mSize cameraLocation:(CGRect) mlocation;
-(id) initForLayer:(CocosNode*) target layerSize:(CGSize) mSize cameraLocation:(CGRect) mlocation :(bool) movable;
-(void) updateLayerPosition:(CGPoint) mPosition;
-(void) updateLayerZoom:(float) width;

@end
