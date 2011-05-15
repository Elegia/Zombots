//
//  Player.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 13/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Player.h"

Player::Player()
{
    this->setxVelocity(0);
    this->setyVelocity(0);
    this->setSpeed(5.0);
}

Player::~Player()
{
}