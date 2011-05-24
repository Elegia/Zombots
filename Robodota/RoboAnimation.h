//
//  RoboAnimation.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 24/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "RoboEntity.h"

class RoboSprite;
class RoboScene;

class RoboAnimation : public RoboEntity
{
    
    RoboSprite** _frames;
    int _lastUsedFrameIndex;
    
    sf::Clock _clock;
    float _elapsedTime;
    
    int _currentFrame;
    int _framerate;
    bool _playing;

public:
    RoboAnimation(RoboScene *game);
    ~RoboAnimation();
    
    void play();
    void update();
    void pauze();
    void reset();
    
    void setFramerate(int const framerate);
    int getFramerate() const;
    
    void addFrame(RoboSprite* const frame);
    void removeFrame(RoboSprite* const frame);
    void removeFrameAtIndex(const int index);
    
    void setPosition(float x, float y);
};