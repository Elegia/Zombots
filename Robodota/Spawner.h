//
//  Spawner.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include "RoboEntity.h"

class Humanoid;

class Spawner : public RoboEntity
{
    sf::Clock _clock;
    float _elapsedTime;
    
    Humanoid **_enemies;
    int _lastUsedEnemyIndex;
    
public:
    Spawner(RoboGame *game);
    Spawner(RoboGame *game, RoboSprite *sprite);
    ~Spawner();
    
    void update();
};