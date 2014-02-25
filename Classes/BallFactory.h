//
//  BallFactory.h
//  cocos_flick
//
//  Created by A13235 on 2014/02/24.
//
//

#ifndef _BALL_FACTORY_H_
#define _BALL_FACTORY_H_

#include "config.h";
#include "BallPhysics.h";

class BallFactory
{

public:
    BallFactory();
    virtual BallPhysics* createBall(Point p);
};

#endif /* defined(_BALL_FACTORY_H_) */
