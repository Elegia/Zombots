//
//  RoboGame.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include <SFML/Graphics.hpp>

class RoboGame {

    
public:
    RoboGame();
    
    virtual void handleInput(const sf::Input &input);
    virtual void update();
    virtual void draw();
    
};



