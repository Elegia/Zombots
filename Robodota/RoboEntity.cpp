//
//  RoboEntity.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "RoboEntity.h"

RoboEntity::RoboEntity()
{
    
}

RoboEntity::RoboEntity(RoboSprite &sprite)
{
    _sprite = &sprite;
}

RoboEntity::~RoboEntity()
{
    delete _sprite;
}

void RoboEntity::update()
{
    
}

void RoboEntity::draw(RoboEngine *engine) const
{
    #warning see below
    // TODO: normally the screensize should've been popped from the stack already, so the
    // returned screensize here should be undefined -> TEST THIS
    sf::Vector2f screenSize = engine->getScreenSize();
    
    if (_sprite->GetPosition().x >= 0 && _sprite->GetPosition().x <= screenSize.x &&
        _sprite->GetPosition().y >= 0 && _sprite->GetPosition().y <= screenSize.y)
    {
        engine->draw(*_sprite);
    }
}

RoboSprite& RoboEntity::getSprite() const
{
    return *_sprite;
}

void RoboEntity::setSprite(RoboSprite &sprite)
{
    _sprite = &sprite;
}