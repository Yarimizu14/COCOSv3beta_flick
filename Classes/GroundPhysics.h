//
//  groundPhysics.h
//  cocos_flick
//
//  Created by A13235 on 2014/02/25.
//
//

#ifndef _GROUND_PHYSICS_H_
#define _GROUND_PHYSICS_H_

#include "config.h";

class GroundPhysics
{

public:
    GroundPhysics();
    Sprite* createGround(const Point &p, const Size &s);
    void createRoundGround();
};

#endif /* defined(_GROUND_PHYSICS_H_) */
