//
//  Bullet.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 14/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include "Bullet.h"
#include "RoboSprite.h"

Bullet::Bullet()
{
    this->setSpeed(10.0f);
}

Bullet::~Bullet()
{
    
}

void Bullet::update()
{
    sf::Vector2f position = this->getSprite().GetPosition();
    position.x += this->getxVelocity();
    position.y += this->getyVelocity();
    this->getSprite().SetPosition(position.x, position.y);
}