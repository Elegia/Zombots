//
//  Robodota.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 03/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//



#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream.h>
#include "Configuration.h"

class RoboScene;
class RoboSprite;
class RoboUtil;

class RoboEngine {
    
    static RoboEngine* _instance;
    
    sf::RenderWindow *_renderWindow;
    
    RoboScene *_RoboScene;
    
    std::map<std::string, sf::Image*> *_imageCache;
    
    int _screenWidth;
    int _screenHeight;
    
protected:
    RoboEngine();
    
public:
    ~RoboEngine();
    
    static RoboEngine* Instance();
    
    int init(int screenWidth, int screenHeight, int bpp, RoboScene *RoboScene);
    
    static sf::Image* getTextureByName(std::string const &name);
    static RoboSprite* getSpriteWithImage(const sf::Image &image);
    static RoboSprite* getSpriteByName(std::string const &name);
    
    std::map<std::string, sf::Image*>* getImageCache() const; 
    void addImageToCache(std::string const &name, sf::Image* const image);
    sf::Image* getImageFromCache(std::string const &name);
    void removeImageFromCache(std::string const &name);
    
    void draw();
    void draw(RoboSprite const &sprite);
    
    sf::Vector2f getScreenSize() const;
    
};
    
    