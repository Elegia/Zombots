//
//  RoboSprite.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include "RoboSprite.h"

RoboSprite::RoboSprite()
{
    _layer = 0;
}

void RoboSprite::setLayer(int const layer)
{
    _layer = layer;
}

int RoboSprite::getLayer() const 
{
    return _layer;
}