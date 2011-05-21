//
//  Spawner.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "RoboEntity.h"

class Spawner : public RoboEntity
{
    sf::Clock _clock;
    float _elapsedTime;
    
public:
    Spawner();
    Spawner(RoboSprite &sprite);
    ~Spawner();
    
    void update();
};