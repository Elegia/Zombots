//
//  Player.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 13/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Player.h"

Player::Player()
{
    _xVelocity = 0;
    _yVelocity = 0;
}

Player::~Player()
{
    delete _sprite;
    delete _bullets;
}

void Player::update()
{
    sf::Vector2f position = _sprite->GetPosition();
    position.x += _xVelocity;
    position.y += _yVelocity;
    
    _sprite->SetPosition(position.x, position.y);
}


RoboSprite& Player::getSprite() const
{
    return *_sprite;
}

void Player::setSprite(RoboSprite &sprite)
{
    _sprite = &sprite;
}

const float Player::getxVelocity() const
{
    return _xVelocity;
}

void Player::setxVelocity(float xVelocity)
{
    _xVelocity = xVelocity;
}

const float Player::getyVelocity() const
{
    return _yVelocity;
}


void Player::setyVelocity(float yVelocity)
{
    _yVelocity = yVelocity;
}

const float Player::getHealth() const
{
    return _health;
}

void Player::setHealth(float health)
{
    _health = health;
}