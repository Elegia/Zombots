//
//  Humanoid.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


#include "Bullet.h"
#include "RoboEngine.h"
#include "RoboSprite.h"

#include "Humanoid.h"


Humanoid::Humanoid()
{
    _bullets = new Bullet[512];
    _xVelocity = 0;
    _yVelocity = 0;
    _lastUsedBulletIndex = -1;
}

Humanoid::~Humanoid()
{
    delete _bullets;
    #warning where does sprite come from?
    delete _sprite; 
}

void Humanoid::update()
{
    // Update humanoid position
    sf::Vector2f position = _sprite->GetPosition();
    position.x += _xVelocity;
    position.y += _yVelocity;
    _sprite->SetPosition(position.x, position.y);
    
    // Update bullet positions
    for (int i=_lastUsedBulletIndex; i>=0; i--)
    {
        Bullet bullet = _bullets[i];
        
        bullet.update();
        
        if (bullet.getSprite().GetPosition().x <= 0 || bullet.getSprite().GetPosition().x >= 800 ||
            bullet.getSprite().GetPosition().y <= 0 || bullet.getSprite().GetPosition().y >= 600)
        {
            for (int j=i+1; j <= _lastUsedBulletIndex; j++)
            {
                _bullets[j - 1] = _bullets[j];
            }
            
            _lastUsedBulletIndex--;
        }
    } 
}

void Humanoid::draw(RoboEngine* roboEngine) const
{
    roboEngine->draw(*_sprite);
    for (int i=_lastUsedBulletIndex; i>=0; i--)
    {
        roboEngine->draw(_bullets[i].getSprite());
    }
}

void Humanoid::fire(float const rico)
{
    Bullet bullet;
    bullet.setSprite(*RoboEngine::getSpriteByName("resources/bullet_red.png"));
    bullet.getSprite().SetCenter(bullet.getSprite().GetSize().x / 2, bullet.getSprite().GetSize().y / 2);
    bullet.getSprite().SetPosition(_sprite->GetPosition());
    
    bullet.setxVelocity(cosf(rico) * bullet.getSpeed());
    bullet.setyVelocity(sinf(rico) * bullet.getSpeed());
    
    if ((_lastUsedBulletIndex + 1) < 512)
    {   
        _bullets[_lastUsedBulletIndex + 1] = bullet;    
        _lastUsedBulletIndex++;
    }
}

RoboSprite& Humanoid::getSprite() const
{
    return *_sprite;
}

void Humanoid::setSprite(RoboSprite &sprite)
{
    _sprite = &sprite;
}

const float Humanoid::getxVelocity() const
{
    return _xVelocity;
}

void Humanoid::setxVelocity(float xVelocity)
{
    _xVelocity = xVelocity;
}

const float Humanoid::getyVelocity() const
{
    return _yVelocity;
}


void Humanoid::setyVelocity(float yVelocity)
{
    _yVelocity = yVelocity;
}

const float Humanoid::getSpeed() const
{
    return _speed;
}

void Humanoid::setSpeed(float speed)
{
    _speed = speed;
}

const float Humanoid::getHealth() const
{
    return _health;
}

void Humanoid::setHealth(float health)
{
    _health = health;
}