//
//  Game.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//


//#include "Spawner.h"
//#include "World.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "RoboGame.h"

class RoboEngine;
class RoboSprite;
class Player;

class Game : public RoboGame {
  
    RoboEngine *_roboEngine;
    
    //World *_world;
    Player *_player;
    
public:
    Game(RoboEngine *engine);
    void handleInput(const sf::Input &input);
    void update();
    void draw();
};