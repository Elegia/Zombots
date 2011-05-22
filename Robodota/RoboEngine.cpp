//
//  Robodota.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 03/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include <iostream.h>
#include "RoboEngine.h"
#include "RoboScene.h"
#include "RoboSprite.h"
#include "RoboUtil.h"

RoboEngine* RoboEngine::_instance = NULL;

RoboEngine::RoboEngine()
{
    _imageCache = new std::map<std::string, sf::Image*>();
}

RoboEngine::~RoboEngine()
{
    delete _instance;
}

RoboEngine* RoboEngine::Instance()
{
    if(_instance == NULL)
    {
        _instance = new RoboEngine();
    }
    return _instance;
}


int RoboEngine::init(int screenWidth, int screenHeight, int bpp, RoboScene *RoboScene)
{
    _renderWindow = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight, bpp), "Zombots from Outer Space", sf::Style::Resize | sf::Style::Close, sf::WindowSettings(32, 8, 0));
    
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;
    
    _renderWindow->UseVerticalSync(true);
    _renderWindow->SetFramerateLimit(60);
    
    // Start the main loop
    while (_renderWindow->IsOpened())
    {
        
        sf::Event event;
        while (_renderWindow->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {
                _renderWindow->Close();
            }                
            else if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape)
            {
                _renderWindow->Close();
            }
        }
        
        const sf::Input& input = _renderWindow->GetInput();
        
        RoboScene->handleInput(input);
        
        RoboScene->update();
        
        _renderWindow->Clear(sf::Color::White);
        
        RoboScene->draw();
        
        _renderWindow->Display();
    }
    
    return EXIT_SUCCESS;
}

sf::Image* RoboEngine::getTextureByName(std::string const &name)
{
    RoboEngine *engine = RoboEngine::Instance();
    
    std::map<std::string, sf::Image*>::iterator imageCacheIterator = engine->getImageCache()->find(name);
    
    if (imageCacheIterator != engine->getImageCache()->end())
    {
        // Use the image from the cache
        
        return engine->getImageFromCache(name);
    }
    else
    {
        // Load the image and add it to the cache
        
        sf::Image *image = new sf::Image();
        if (! image->LoadFromFile(name))
        {
            cout << "Could not load image " << name << " in getTextureByName.\n";
        }
        else
        {
            engine->addImageToCache(name, image);
        }
        return image;
    }
}

RoboSprite* RoboEngine::getSpriteWithImage(const sf::Image &image)
{
    RoboSprite *sprite = new RoboSprite();
    
    sprite->SetImage(image);
    sprite->SetX(0);
    sprite->SetY(0);
    
    return sprite;
}

RoboSprite* RoboEngine::getSpriteByName(std::string const &name)
{
    return getSpriteWithImage( *getTextureByName(name) );
}

std::map<std::string, sf::Image*>* RoboEngine::getImageCache() const
{
    return _imageCache;
}

void RoboEngine::addImageToCache(std::string const &name, sf::Image* const image)
{
    _imageCache->insert(std::pair<std::string, sf::Image*>(name, image));
}

sf::Image* RoboEngine::getImageFromCache(std::string const &name)
{
    std::map<std::string, sf::Image*>::iterator imageCacheIterator = _imageCache->find(name);
    
    if (imageCacheIterator != _imageCache->end())
    {
        return imageCacheIterator->second;
    }
    return NULL;
}

void RoboEngine::removeImageFromCache(std::string const &name)
{
    _imageCache->erase(name);
}

void RoboEngine::draw()
{
}

void RoboEngine::draw(RoboSprite const &sprite)
{
    _renderWindow->Draw(sprite);
}

sf::Vector2f RoboEngine::getScreenSize() const
{
    sf::Vector2f screenSize;
    screenSize.x = _screenWidth;
    screenSize.y = _screenHeight;
    
    return screenSize;
}