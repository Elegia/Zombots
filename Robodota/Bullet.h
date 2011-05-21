//
//  Bullet.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 14/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

class RoboSprite;

class Bullet
{
    RoboSprite *_sprite;
    float _xVelocity;
    float _yVelocity;
    float _speed;
    
public:
    
    Bullet();
    ~Bullet();
    
    void update();
    
    RoboSprite& getSprite() const;
    void setSprite(RoboSprite &sprite);
    
    const float getxVelocity() const;
    void setxVelocity(float xVelocity);
    
    const float getyVelocity() const;
    void setyVelocity(float yVelocity);
    
    const float getSpeed() const;
    
    
};