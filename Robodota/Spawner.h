//
//  Spawner.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

class RoboEntity;

class Spawner : public RoboEntity
{
  
public:
    Spawner();
    Spawner(RoboSprite &sprite);
    ~Spawner();
    
    void spawnEnemy();
};