//
//  Player.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 13/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

//#include "Humanoid.h"
#include "Player.h"


Player::Player(RoboGame *game) : Humanoid(game)
{
    this->setxVelocity(0);
    this->setyVelocity(0);
    this->setSpeed(5.0);
}

Player::~Player()
{
}