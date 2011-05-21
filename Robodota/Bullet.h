//
//  Bullet.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 14/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#ifndef BULLET
#define BULLET

#include "RoboEntity.h"

class Bullet : public RoboEntity
{
    
public:
    
    Bullet(RoboGame *game);
    ~Bullet();
    
    void update();
};

#endif