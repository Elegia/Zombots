//
//  World.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

class RoboEngine;
class RoboEntity;

class World {
    
    RoboEntity **_entities;
    int _lastUsedEntityIndex;
    
public:
    World();
    ~World();
    
    void update();
    void draw(RoboEngine *roboEngine) const;
    
    void addEntity(RoboEntity *entity);
    void removeEntity(RoboEntity *entity);
};