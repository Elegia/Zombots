//
//  World.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "RoboEngine.h"
#include "RoboEntity.h"
#include "World.h"


World::World()
{
    _entities = new RoboEntity* [2048];
    _lastUsedEntityIndex = -1;
}

World::~World()
{
    delete _entities;
}

void World::update()
{
    for (int i=0; i <= _lastUsedEntityIndex; i++)
    {
        _entities[i]->update();
    }
}

void World::draw(RoboEngine *roboEngine) const
{
    for (int i=0; i <= _lastUsedEntityIndex; i++)
    {
        _entities[i]->draw(roboEngine);
    }
}

void World::addEntity(RoboEntity *entity)
{
    if ((_lastUsedEntityIndex + 1) < 2048)
    {
        _entities[_lastUsedEntityIndex + 1] = entity;
        _lastUsedEntityIndex++;
    }
}

void World::removeEntity(RoboEntity *entity)
{
    for (int i=_lastUsedEntityIndex; i >= 0; i--)
    {
        if (_entities[_lastUsedEntityIndex] == entity)
        {
            for (int j=i+1; j <= _lastUsedEntityIndex; j++) 
            {
                _entities[j - 1] = _entities[j];
            }
            _lastUsedEntityIndex--;
        }
    }
}