//
//  Robodota.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 03/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream.h>
#include "RoboGame.h"
#include "RoboSprite.h"
#include "RoboUtil.h"

class RoboEngine {
    
    sf::RenderWindow *renderWindow;
    
    RoboGame *roboGame;
    
    std::map<std::string, sf::Image> imageCache;
    
    int _screenWidth;
    int _screenHeight;
    
public:
    RoboEngine();
    
    int init(int screenWidth, int screenHeight, int bpp, RoboGame *roboGame);
    
    static sf::Image* getTextureByName(std::string const &name);
    static RoboSprite* getSpriteWithImage(const sf::Image &image);
    static RoboSprite* getSpriteByName(std::string const &name);
    
    void addImageToCache(std::string const &name, sf::Image const &image);
    void removeImageFromCache(std::string const &name);
    
    void draw(RoboSprite const &sprite);
    
    sf::Vector2f getScreenSize() const;
    
};
    
    