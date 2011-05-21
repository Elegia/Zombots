//
//  Player.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 13/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include "Humanoid.h"

class Player : public Humanoid 
{
    
public:
    Player(RoboScene *game);
    ~Player();
};