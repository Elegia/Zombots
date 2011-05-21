//
//  Humanoid.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//


#include "Bullet.h"
#include "RoboEngine.h"
#include "RoboSprite.h"
#include "RoboGame.h"
#include "Humanoid.h"


Humanoid::Humanoid(RoboGame *game) : RoboEntity(game)
{
    _bullets = new Bullet* [MAX_BULLETS];
    this->setxVelocity(0);
    this->setyVelocity(0);
    _lastUsedBulletIndex = -1;
}

Humanoid::~Humanoid()
{
    delete _bullets;
}

void Humanoid::update()
{
    // Update humanoid position
    sf::Vector2f position = this->getSprite().GetPosition();
    position.x += this->getxVelocity();
    position.y += this->getyVelocity();
    this->getSprite().SetPosition(position.x, position.y);
    
    // Update bullet positions
    for (int i=_lastUsedBulletIndex; i>=0; i--)
    {
        Bullet *bullet = _bullets[i];
        
        bullet->update();
        
        if (bullet->getSprite().GetPosition().x <= 0 || bullet->getSprite().GetPosition().x >= 800 ||
            bullet->getSprite().GetPosition().y <= 0 || bullet->getSprite().GetPosition().y >= 600)
        {               
            for (int j=i+1; j <= _lastUsedBulletIndex; j++)
            {
                _bullets[j - 1] = _bullets[j];
            }
            
            this->getGame()->removeEntity(bullet);
            _lastUsedBulletIndex--;
        }
    } 
}

void Humanoid::draw(RoboEngine* roboEngine) const
{
    roboEngine->draw(this->getSprite());
    for (int i=_lastUsedBulletIndex; i>=0; i--)
    {
        roboEngine->draw(_bullets[i]->getSprite());
    }
}

void Humanoid::fire(float const rico)
{
    Bullet *bullet = new Bullet(this->getGame());
    bullet->setSprite(*RoboEngine::getSpriteByName("resources/bullet_red.png"));
    bullet->getSprite().SetCenter(bullet->getSprite().GetSize().x / 2, bullet->getSprite().GetSize().y / 2);
    bullet->getSprite().SetPosition(this->getSprite().GetPosition());
    
    bullet->setxVelocity(cosf(rico) * bullet->getSpeed());
    bullet->setyVelocity(sinf(rico) * bullet->getSpeed());
    
    if ((_lastUsedBulletIndex + 1) < MAX_BULLETS)
    {   
        _bullets[_lastUsedBulletIndex + 1] = bullet;    
        this->getGame()->addEntity(bullet);
        
        _lastUsedBulletIndex++;
    }
}

const float Humanoid::getHealth() const
{
    return _health;
}

void Humanoid::setHealth(float health)
{
    _health = health;
}