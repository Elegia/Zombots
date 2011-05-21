//
//  RoboSprite.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

//#import "RoboEngine.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class RoboSprite : public sf::Sprite {
    
    int _layer;
    
public:
    RoboSprite();
    
    void setLayer(int const layer);
    int getLayer() const;
};