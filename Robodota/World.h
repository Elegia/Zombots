//
//  World.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "RoboEngine.h"

class World {
  
    std::vector<RoboSprite> *elements;
    
public:
    World();
    void createWorld();
    
};