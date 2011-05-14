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
    _speed = 5.0f;
    
    _lastUsedBulletIndex = -1;
}

Player::~Player()
{
    delete _sprite;
}

void Player::update()
{
    // Update player position
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
            for (int j=i+1; j<sizeof(_bullets)/sizeof(Bullet) - 1; j++)
            {
                _bullets[j - 1] = _bullets[j];
            }
            
            _lastUsedBulletIndex--;
        }
    }

}

void Player::draw(RoboEngine* roboEngine) const
{
    roboEngine->draw(*_sprite);
    for (int i=_lastUsedBulletIndex; i>=0; i--)
    {
        roboEngine->draw(_bullets[i].getSprite());
    }
}

void Player::fire(float const rico)
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

const float Player::getSpeed() const
{
    return _speed;
}

const float Player::getHealth() const
{
    return _health;
}

void Player::setHealth(float health)
{
    _health = health;
}