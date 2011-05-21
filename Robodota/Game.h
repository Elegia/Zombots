//
//  Game.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "RoboScene.h"

class RoboEngine;
class RoboSprite;
class Player;

class Game : public RoboScene {
    
    Player *_player;
    
public:
    Game(RoboEngine *engine);
    void handleInput(const sf::Input &input);
    void update();
    void draw();
};