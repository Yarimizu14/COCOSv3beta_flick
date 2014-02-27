//
//  bulletPhysics.h
//  cocos_flick
//
//  Created by A13235 on 2014/02/25.
//
//

#ifndef _BALL_PHYSICS_H_
#define _BALL_PHYSICS_H_

#include "config.h";

class BallPhysics: public Sprite
{

public:
    BallPhysics();
    BallPhysics(Point force);
    
    bool touchBegan(Touch *touch, Event* event);
    void touchMoved(Touch *touch, Event* event);
    void touchEnded(Touch* touch, Event* event);
    void touchCancelled(Touch* touch, Event* event);
};

#endif /* defined(_BALL_PHYSICS_H_) */
