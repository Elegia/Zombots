//
//  RoboAnimation.cpp
//  SFMLTest
//
//  Created by Maarten Lauwers on 24/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "RoboAnimation.h"
#include "RoboSprite.h"
#include "RoboScene.h"

RoboAnimation::RoboAnimation(RoboScene *game) : RoboEntity(game)
{
    _frames = new RoboSprite*[512];
    _lastUsedFrameIndex = -1;
    
    _elapsedTime = 0.0f;
    
    _currentFrame = 0;
    _framerate = 30;
    _playing = false;
}

RoboAnimation::~RoboAnimation()
{
    delete _frames;
    
    RoboEntity::~RoboEntity();
}

void RoboAnimation::play()
{
    this->setSprite(_frames[_currentFrame]);
    
    _playing = true;
}

void RoboAnimation::update()
{
    RoboEntity::update();
    
    if (_playing == true)
    {
        _elapsedTime += _clock.GetElapsedTime();
        
        if (_elapsedTime >= 1.0f / _framerate)
        {
            _currentFrame++;
            
            if (_currentFrame > _lastUsedFrameIndex)
            {
                _currentFrame = 0;
            }
            
            this->setSprite(_frames[_currentFrame]);
            
            _elapsedTime = 0.0f;
        }
        
        _clock.Reset();  
    }
}

void RoboAnimation::pauze()
{
    _playing = false;
}

void RoboAnimation::reset()
{
    _currentFrame = -1;
}

void RoboAnimation::setFramerate(int const framerate)
{
    if (framerate >= 0)
    {
        _framerate = framerate;    
    }
    
}

int RoboAnimation::getFramerate() const
{
    return _framerate;
}

void RoboAnimation::addFrame(RoboSprite* const frame)
{
    if ((_lastUsedFrameIndex + 1) < 512)
    {
        _frames[_lastUsedFrameIndex + 1] = frame;
        _lastUsedFrameIndex++;
    }
}

void RoboAnimation::removeFrame(RoboSprite* const frame)
{
    for (int i = 0; i <= _lastUsedFrameIndex; i++)
    {
        if (_frames[i] == frame)
        {
            delete frame;
            
            for (int j = i; j < _lastUsedFrameIndex; j++)
            {
                _frames[j] = _frames[j + 1];
            }
            
            _lastUsedFrameIndex--;
            break;
        }
    }
}

void RoboAnimation::removeFrameAtIndex(const int index)
{
    if (index >= 0 && index <= _lastUsedFrameIndex)
    {
        this->removeFrame(_frames[index]);    
    }
}

void RoboAnimation::setPosition(float x, float y)
{
    for (int i = 0; i <= _lastUsedFrameIndex; i++)
    {
        _frames[i]->SetPosition(x, y);
    }
}