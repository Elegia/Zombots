//
//  Humanoid.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#ifndef HUMANOID
#define HUMANOID

class Bullet;

#include "RoboEntity.h"


class Humanoid : public RoboEntity
{
    int _health;
    
    Bullet **_bullets;
    int _lastUsedBulletIndex;
    
public:
    Humanoid(RoboScene *game);
    ~Humanoid();
    
    void update();
    void draw(RoboEngine* roboEngine) const;
    
    void fire(float const rico);
    
    const float getHealth() const;
    void setHealth(float health);
};

#endif