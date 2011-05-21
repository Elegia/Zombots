//
//  Spawner.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream.h>
#include "Spawner.h"

Spawner::Spawner()
{
    _elapsedTime = 0.0f;
}

Spawner::Spawner(RoboSprite &sprite)// : RoboEntity(sprite)
{
    this->setSprite(sprite);
}

void Spawner::update()
{
    _elapsedTime += _clock.GetElapsedTime();
    
    if (_elapsedTime > 2.0)
    {
        // Spawn a zombot
        
        cout << "Spawning zombot\n";
        
        _elapsedTime = 0;
    }
    
    _clock.Reset();
}