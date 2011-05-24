//
//  RoboEntity.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include "RoboScene.h"
#include "RoboEngine.h"
#include "RoboSprite.h"
#include "RoboEntity.h"

RoboEntity::RoboEntity(RoboScene *game)
{
    _game = game;
    _layer = 0;
}

RoboEntity::RoboEntity(RoboScene *game, RoboSprite *sprite)
{
    _game = game;
    _sprite = sprite;
}


RoboEntity::~RoboEntity()
{
    delete _sprite;
}

RoboScene* RoboEntity::getGame() const
{
    return _game;
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
        engine->draw(_sprite);
    }
}

const int RoboEntity::getLayer() const 
{
    return _layer;
}

void RoboEntity::setLayer(int const layer)
{
    _layer = layer;
}

RoboSprite* RoboEntity::getSprite() const
{
    return _sprite;
}

void RoboEntity::setSprite(RoboSprite *sprite)
{
    _sprite = sprite;
}

const float RoboEntity::getxVelocity() const
{
    return _xVelocity;
}

void RoboEntity::setxVelocity(float xVelocity)
{
    _xVelocity = xVelocity;
}

const float RoboEntity::getyVelocity() const
{
    return _yVelocity;
}

void RoboEntity::setyVelocity(float yVelocity)
{
    _yVelocity = yVelocity;
}

const float RoboEntity::getSpeed() const
{
    return _speed;
}

void RoboEntity::setSpeed(float speed)
{
    _speed = speed;
}