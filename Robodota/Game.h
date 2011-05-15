//
//  Game.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "RoboEngine.h"
#import "RoboSprite.h"
#import "Player.h"

class Game : public RoboGame {
  
    RoboEngine *_roboEngine;
    
    Player *_player;
    
public:
    Game(RoboEngine *engine);
    void handleInput(const sf::Input &input);
    void update();
    void draw();
};