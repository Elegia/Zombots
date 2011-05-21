//
//  RoboEntity.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#ifndef ROBOENTITY
#define ROBOENTITY

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class RoboGame;
class RoboSprite;
class RoboEngine;

class RoboEntity
{
    RoboGame *_game;
    RoboSprite *_sprite;
    
    float _xVelocity;
    float _yVelocity;
    float _speed;
    
public:
    RoboEntity(RoboGame *game);
    RoboEntity(RoboGame *game, RoboSprite *sprite);
    ~RoboEntity();
    
    RoboGame* getGame() const;
    
    virtual void update();
    void draw(RoboEngine *engine) const;
    
    const float getxVelocity() const;
    void setxVelocity(float xVelocity);
    
    const float getyVelocity() const;
    void setyVelocity(float yVelocity);
    
    const float getSpeed() const;
    void setSpeed(float speed);
    
    RoboSprite& getSprite() const;
    void setSprite(RoboSprite &sprite);
};

#endif