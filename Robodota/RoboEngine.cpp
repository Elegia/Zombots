//
//  Robodota.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 03/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "RoboEngine.h"

RoboEngine::RoboEngine()
{
    
}

int RoboEngine::init(int screenWidth, int screenHeight, int bpp, RoboGame *roboGame)
{
    renderWindow = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight, bpp), "Zombots from Outer Space", sf::Style::Resize | sf::Style::Close, sf::WindowSettings(32, 8, 0));
    
    renderWindow->UseVerticalSync(true);
    renderWindow->SetFramerateLimit(60);
    
    // Start the main loop
    while (renderWindow->IsOpened())
    {
        
        sf::Event event;
        while (renderWindow->GetEvent(event))
        {
            if (event.Type == sf::Event::Closed)
            {
                renderWindow->Close();
            }                
            else if (event.Type == sf::Event::KeyPressed && event.Key.Code == sf::Key::Escape)
            {
                renderWindow->Close();
            }
        }
        
        const sf::Input& input = renderWindow->GetInput();
        
        roboGame->handleInput(input);
        
        roboGame->update();
        
        renderWindow->Clear(sf::Color::White);
        
        roboGame->draw();
        
        renderWindow->Display();
    }
    
    return EXIT_SUCCESS;
}

sf::Image* RoboEngine::getTextureByName(std::string const &name)
{
    sf::Image *image = new sf::Image();
    if (! image->LoadFromFile(name))
    {
        
    }
    return image;
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

void RoboEngine::addImageToCache(std::string const &name, sf::Image const &image)
{
    imageCache.insert(std::pair<std::string, sf::Image>(name, image));
}

void RoboEngine::removeImageFromCache(std::string const &name)
{
    imageCache.erase(name);
}

void RoboEngine::draw(RoboSprite const &sprite)
{
    renderWindow->Draw(sprite);
}