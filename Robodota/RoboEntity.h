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

class RoboScene;
class RoboSprite;
class RoboEngine;

class RoboEntity
{
    RoboScene *_game;
    RoboSprite *_sprite;
    
    float _xVelocity;
    float _yVelocity;
    float _speed;
    
    int _layer;
    
public:
    RoboEntity(RoboScene *game);
    RoboEntity(RoboScene *game, RoboSprite *sprite);
    ~RoboEntity();
    
    RoboScene* getGame() const;
    
    virtual void update();
    void draw(RoboEngine *engine) const;

    const int getLayer() const;
    void setLayer(int const layer);
    
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