//
//  Player.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 13/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "RoboEngine.h"

class Player {
  
    RoboSprite *_sprite;
    float _xVelocity;
    float _yVelocity;
    int _health;
    
    std::vector<RoboSprite> *_bullets;
    
public:
    Player();
    ~Player();
    
    void update();
    
    RoboSprite& getSprite() const;
    void setSprite(RoboSprite &sprite);
    
    const float getxVelocity() const;
    void setxVelocity(float xVelocity);
    
    const float getyVelocity() const;
    void setyVelocity(float yVelocity);
    
    const float getHealth() const;
    void setHealth(float health);
};