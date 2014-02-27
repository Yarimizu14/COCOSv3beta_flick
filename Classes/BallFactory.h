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
#include "TargetPhysics.h";

class BallFactory
{

public:
    BallFactory();
    virtual BallPhysics* createBall(Point p);
    virtual BallPhysics* createBall(Point p, Point force);
    virtual TargetPhysics* createTarget(Point p);
    
    // 各タグ番号の初期化
    int ballNum = 0;
    int targetNum = 0;
};

#endif /* defined(_BALL_FACTORY_H_) */
