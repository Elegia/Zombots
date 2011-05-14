//
//  Game.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Game.h"

Game::Game(RoboEngine *engine)
{
    // Test sprites
    _roboEngine = engine;
    
    sf::Image *myImage = _roboEngine->getTextureByName("resources/minion_melee_red.png");
    _roboEngine->addImageToCache("tower_blue", *myImage);
    
    RoboSprite *sprite = _roboEngine->getSpriteWithImage(*myImage);
    sprite->SetCenter(sprite->GetSize().x / 2, sprite->GetSize().y / 2);
    sprite->SetPosition(100, 100);
    
    _player = new Player();
    _player->setSprite(*sprite);

}

void Game::handleInput(const sf::Input &input)
{
    // Mouse
    sf::Vector2f mousePoint;
    mousePoint.x = input.GetMouseX();
    mousePoint.y = input.GetMouseY();
    
    // Rotate the player to face our mouse cursor
    sf::Vector2f playerPoint = _player->getSprite().GetPosition();
    float angle = RoboUtil::getAngle(playerPoint, mousePoint);
    _player->getSprite().SetRotation(-angle);
    
    // Calculate the direction vector
    float rico = atan2(mousePoint.y - playerPoint.y, mousePoint.x - playerPoint.x);
    
    
    //sf::Vector2f directionVector;
    //directionVector.x = (mousePoint.x - playerPoint.x);
    //directionVector.y = (mousePoint.y - playerPoint.y);
    //float m = directionVector.y / directionVector.x;
    
    
    // Keyboard
    if (input.IsKeyDown(sf::Key::W))
    {
        // North
        //_player->setyVelocity(-1.0);
        
        _player->setxVelocity(cosf(rico) * 1.5);
        _player->setyVelocity(sinf(rico) * 1.5);
    }
    /*
    else if (input.IsKeyDown(sf::Key::S))
    {
        // South
        _player->setyVelocity(1.0);
    }
    else if (input.IsKeyDown(sf::Key::A))
    {
        // West
        _player->setxVelocity(-1.0);
    }
    else if (input.IsKeyDown(sf::Key::D))
    {
        // East
        _player->setxVelocity(1.0);   
    }
    else
    {
        _player->setyVelocity(0);
    }

    
    if (input.IsKeyDown(sf::Key::A))
    {
        // West
        _player->setxVelocity(-1.0);
    }
    else if (input.IsKeyDown(sf::Key::D))
    {
        // East
        _player->setxVelocity(1.0);   
    }
    else
    {
        _player->setxVelocity(0);
    }
    */
}

void Game::update()
{
    _player->update();
}

void Game::draw()
{
    _roboEngine->draw( _player->getSprite() );
}