//
//  RoboEntity.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class RoboEngine;
class RoboSprite;

class RoboEntity
{
    RoboSprite *_sprite;
    
public:
    RoboEntity();
    RoboEntity(RoboSprite &sprite);
    ~RoboEntity();
    
    virtual void update();
    void draw(RoboEngine *engine) const;
    
    RoboSprite& getSprite() const;
    void setSprite(RoboSprite &sprite);
};