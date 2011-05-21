//
//  RoboScene.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 07/05/11.
//  Copyright 2011 Maarten Lauwers. All rights reserved.
//

#include <SFML/Graphics.hpp>

class RoboEngine;
class RoboEntity;

class RoboScene {

    RoboEngine *_roboEngine;
    
    RoboEntity **_entities;
    int _lastUsedEntityIndex;
    
public:
    RoboScene(RoboEngine* engine);
    ~RoboScene();
    
    virtual void handleInput(const sf::Input &input);
    virtual void update();
    virtual void draw();
    
    RoboEngine* getEngine();
    
    void addEntity(RoboEntity* const entity);
    void removeEntity(RoboEntity* const entity);
};



