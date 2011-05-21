//
//  main.cpp
//  Robodota
//
//  Created by Maarten Lauwers on 03/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include <iostream>
#include "RoboEngine.h"
#include "Game.h"

int main (int argc, const char * argv[])
{

    RoboEngine engine = RoboEngine();
    Game *game = new Game(&engine);
    
    engine.init(800, 600, 32, game);
    
    delete(game);
    
    return EXIT_SUCCESS;
}


