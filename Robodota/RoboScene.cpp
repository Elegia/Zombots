//
//  RoboGame.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include "RoboEngine.h"
#include "RoboEntity.h"
#include "RoboGame.h"

RoboGame::RoboGame(RoboEngine* engine)
{
    _roboEngine = engine;
    
    _entities = new RoboEntity* [2048];
    _lastUsedEntityIndex = -1;
}

RoboGame::~RoboGame()
{
    delete _entities;
}

void RoboGame::handleInput(const sf::Input &input)
{
    
}

void RoboGame::update()
{
    
}

void RoboGame::draw()
{
    for (int i = 0; i <= _lastUsedEntityIndex; i++)
    {
        _roboEngine->draw(_entities[i]->getSprite());
    }
}

RoboEngine* RoboGame::getEngine()
{
    return _roboEngine;
}

void RoboGame::addEntity(RoboEntity* const entity)
{
    if ((_lastUsedEntityIndex + 1) < 2048)
    {
        _entities[_lastUsedEntityIndex + 1] = entity;
        _lastUsedEntityIndex++;
    }
}

void RoboGame::removeEntity(RoboEntity* const entity)
{
    for (int i = 0; i <= _lastUsedEntityIndex; i++)
    {
        if (_entities[i] == entity)
        {
            delete entity;
            
            for (int j=i+1; j <= _lastUsedEntityIndex; j++)
            {
                _entities[j - 1] = _entities[j];
            }
            
            _lastUsedEntityIndex--;            
        }
    }
}