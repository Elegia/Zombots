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
#include "RoboScene.h"
#include "Enemy.h"
#include "Spawner.h"


Spawner::Spawner(RoboScene *game) : RoboEntity(game)
{
    _elapsedTime = 0.0f;
    _enemies = new Humanoid* [MAX_ENEMIES_PER_SPAWNER];
    _lastUsedEnemyIndex = -1;
}

Spawner::Spawner(RoboScene *game, RoboSprite *sprite) : RoboEntity(game, sprite)
{
    _elapsedTime = 0.0f;
    _enemies = new Humanoid* [MAX_ENEMIES_PER_SPAWNER];
    _lastUsedEnemyIndex = -1;
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
        
        Enemy *enemy = new Enemy(this->getGame());
        enemy->setSprite(*RoboEngine::getSpriteByName("resources/block_yellow.png"));
        enemy->getSprite().SetCenter(enemy->getSprite().GetSize().x / 2, enemy->getSprite().GetSize().y / 2);
        enemy->getSprite().SetPosition(this->getSprite().GetPosition().x, this->getSprite().GetPosition().y);
        
        if ((_lastUsedEnemyIndex + 1) < MAX_ENEMIES_PER_SPAWNER)
        {
            _enemies[_lastUsedEnemyIndex + 1] = enemy;
            this->getGame()->addEntity(enemy);
            _lastUsedEnemyIndex++;
        }
        
        _elapsedTime = 0;
    }
    
    _clock.Reset();
}