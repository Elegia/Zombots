//
//  Game.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include "RoboEngine.h"
#include "RoboSprite.h"
#include "RoboUtil.h"
#include "Player.h"
#include "Spawner.h"

#include "Game.h"


Game::Game(RoboEngine *engine) : RoboScene(engine)
{
    sf::Image *myImage = engine->getTextureByName("resources/minion_melee_red.png");
    engine->addImageToCache("tower_blue", myImage);
    
    RoboSprite *sprite = engine->getSpriteWithImage(*myImage);
    sprite->SetCenter(sprite->GetSize().x / 2, sprite->GetSize().y / 2);
    sprite->SetPosition(100, 100);
    
    _player = new Player(this);
    _player->setSprite(*sprite);
    _player->setLayer(999);
    this->addEntity(_player);

    
    // Create a spawner
    RoboSprite *spawnSprite = engine->getSpriteByName("resources/block_orange.png");
    Spawner *spawner = new Spawner(this, spawnSprite);
    spawner->getSprite().SetPosition(300, 300);
    this->addEntity(spawner);
    
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
    
    
    // Keyboard
    if (input.IsKeyDown(sf::Key::W))
    {   
        _player->setxVelocity(cosf(rico) * _player->getSpeed());
        _player->setyVelocity(sinf(rico) * _player->getSpeed());
    }
    
    if (input.IsKeyDown(sf::Key::S))
    {
        
        _player->setxVelocity(cosf(rico) * _player->getSpeed() * -1);
        _player->setyVelocity(sinf(rico) * _player->getSpeed() * -1);
    }
    
    if (input.IsKeyDown(sf::Key::A))
    {    
        float deltaX = playerPoint.x - mousePoint.x;
        float deltaY = playerPoint.y - mousePoint.y;
        float cos = cosf(RoboUtil::toRadians(5));
        float sin = sinf(RoboUtil::toRadians(5));
        
        _player->getSprite().SetPosition( (mousePoint.x + deltaX * cos - deltaY * sin), 
                                         (mousePoint.y + deltaY * cos + deltaX * sin));
    }
    
    if (input.IsKeyDown(sf::Key::D))
    {
        float deltaX = playerPoint.x - mousePoint.x;
        float deltaY = playerPoint.y - mousePoint.y;
        float cos = cosf(RoboUtil::toRadians(-5));
        float sin = sinf(RoboUtil::toRadians(-5));
        
        _player->getSprite().SetPosition( (mousePoint.x + deltaX * cos - deltaY * sin), 
                                         (mousePoint.y + deltaY * cos + deltaX * sin));
    }
    
    if (! input.IsKeyDown(sf::Key::W) && ! input.IsKeyDown(sf::Key::S) && 
        ! input.IsKeyDown(sf::Key::A) && ! input.IsKeyDown(sf::Key::D))
    {
        _player->setxVelocity(0);
        _player->setyVelocity(0);
    }
    
    // Mouse buttons
    
    if (input.IsMouseButtonDown(sf::Mouse::Left))
    {
        _player->fire(rico);
    }
}

void Game::update()
{
    _player->update();
}

void Game::draw()
{
    RoboScene::draw();
}