//
//  Bullet.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 14/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Bullet.h"

Bullet::Bullet()
{
    _speed = 10.0f;
}

Bullet::~Bullet()
{
    
}

void Bullet::update()
{
    sf::Vector2f position = _sprite->GetPosition();
    position.x += _xVelocity;
    position.y += _yVelocity;
    _sprite->SetPosition(position.x, position.y);
}

RoboSprite& Bullet::getSprite() const
{
    return *_sprite;
}

void Bullet::setSprite(RoboSprite &sprite)
{
    _sprite = &sprite;
}

const float Bullet::getxVelocity() const
{
    return _xVelocity;
}

void Bullet::setxVelocity(float xVelocity)
{
    _xVelocity = xVelocity;
}

const float Bullet::getyVelocity() const
{
    return _yVelocity;
}


void Bullet::setyVelocity(float yVelocity)
{
    _yVelocity = yVelocity;
}

const float Bullet::getSpeed() const
{
    return _speed;
}