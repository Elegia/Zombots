//
//  Humanoid.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 15/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//



class RoboEngine;
class RoboSprite;
class Bullet;

class Humanoid
{
    RoboSprite *_sprite;
    float _xVelocity;
    float _yVelocity;
    float _speed;
    int _health;
    
    Bullet *_bullets;
    int _lastUsedBulletIndex;
    
public:
    Humanoid();
    ~Humanoid();
    
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
    void setSpeed(float speed);
    
    const float getHealth() const;
    void setHealth(float health);
};