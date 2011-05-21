//
//  Spawner.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include <iostream.h>
#include "RoboEngine.h"
#include "RoboSprite.h"
#include "Enemy.h"
#include "Spawner.h"


Spawner::Spawner()
{
    _elapsedTime = 0.0f;
    _enemies = new Humanoid* [MAX_ENEMIES_PER_SPAWNER];
    _lastUsedEnemyIndex = -1;
}

Spawner::Spawner(RoboSprite &sprite)// : RoboEntity(sprite)
{
    _elapsedTime = 0.0f;
    _enemies = new Humanoid* [MAX_ENEMIES_PER_SPAWNER];
    _lastUsedEnemyIndex = -1;
    
    this->setSprite(sprite);
}

Spawner::~Spawner()
{
    delete _enemies;
}

void Spawner::update()
{
    _elapsedTime += _clock.GetElapsedTime();
    
    if (_elapsedTime > 2.0)
    {
        // Spawn a zombot
        
        cout << "Spawning zombot\n";
        
        Enemy *enemy = new Enemy();
        enemy->setSprite(*RoboEngine::getSpriteByName("resources/block_yellow.png"));
        enemy->getSprite().SetCenter(enemy->getSprite().GetSize().x / 2, enemy->getSprite().GetSize().y / 2);
        enemy->getSprite().SetPosition(this->getSprite().GetPosition().x, this->getSprite().GetPosition().y);
        
        if ((_lastUsedEnemyIndex + 1) < MAX_ENEMIES_PER_SPAWNER)
        {
            _enemies[_lastUsedEnemyIndex + 1] = enemy;
            _lastUsedEnemyIndex++;
        }
        _enemies[_lastUsedEnemyIndex + 1] = enemy;
        
        _elapsedTime = 0;
    }
    
    _clock.Reset();
}