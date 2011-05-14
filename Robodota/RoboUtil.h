//
//  RoboUtil.h
//  SFMLTest
//
//  Created by Maarten Lauwers on 14/05/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <SFML/Graphics.hpp>

/*
void toRadians(float const degrees)
{
    
}

void toDegrees(float const radians)
{
    
}
*/

class RoboUtil
{
public:
    static float getAngle(sf::Vector2f const point1, sf::Vector2f const point2)
    {
        sf::Vector2f supportVector;
        supportVector.x = 0;
        supportVector.y = -1;
        
        sf::Vector2f normalizedVector;
        normalizedVector.x = point2.x - point1.x;
        normalizedVector.y = point2.y - point1.y;
        
        float dotProduct = (supportVector.x * normalizedVector.x) + (supportVector.y * normalizedVector.y);
        float normU = sqrt(supportVector.x * supportVector.x + supportVector.y * supportVector.y);
        float normV = sqrt(normalizedVector.x * normalizedVector.x + normalizedVector.y * normalizedVector.y);
        float normUV = normU * normV;
        float resultRadians = acos(dotProduct / normUV);
        float resultDegrees = resultRadians * (180/M_PI);
        
        if (point2.x < point1.x)
        {
            resultDegrees = 360 - resultDegrees;
        }
        
        return resultDegrees;
    }
};
