//
//  Player.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 13/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import "RoboEngine.h"
#import "Bullet.h"

class Player {
  
    RoboSprite *_sprite;
    float _xVelocity;
    float _yVelocity;
    float _speed;
    int _health;
    
    //std::vector<Bullet*> *_bullets;
    Bullet _bullets[512];
    int _lastUsedBulletIndex;
    
public:
    Player();
    ~Player();
    
    void update();
    void draw(RoboEngine* roboEngine) const;
    
    void fire(float const rico);
    
    RoboSprite& getSprite() const;
    void setSprite(RoboSprite &sprite);
    
    const float getxVelocity() const;
    void setxVelocity(float xVelocity);
    
    const float getyVelocity() const;
    void setyVelocity(float yVelocity);
    
    const float getSpeed() const;
    
    const float getHealth() const;
    void setHealth(float health);
};