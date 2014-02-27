//
//  TargetPhysics.h
//  cocos_flick
//
//  Created by A13235 on 2014/02/26.
//
//

#ifndef _TARGET_PHYSICS_H_
#define _TARGET_PHYSICS_H_

#include "config.h";

class TargetPhysics: public Sprite
{
public:
    TargetPhysics();
    
    bool touchBegan(Touch *touch, Event* event);
    void touchEnded(Touch* touch, Event* event);
    void touchMoved(Touch *touch, Event* event);
    void touchCancelled(Touch* touch, Event* event);
};

#endif /* defined(__cocos_flick__TargetPhysics__) */
