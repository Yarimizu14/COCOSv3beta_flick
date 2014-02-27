//
//  GroundPhysics.cpp
//  cocos_flick
//
//  Created by A13235 on 2014/02/25.
//
//

#include "GroundPhysics.h"

GroundPhysics::GroundPhysics() {
}

// 片面づつ壁を作成する
Sprite* GroundPhysics::createGround(const Point &p, const Size &s) {
    Sprite* gSprite = Sprite::create("ground.png");
    gSprite->setContentSize(Size(s.width, s.height));
    gSprite->setPosition(Point(p.x, p.y));
    
    // *地面は重力の影響を受けない
	//pBody->setDynamic(false);
    
    return gSprite;
}

// 4方を囲む壁を作成する
void GroundPhysics::createRoundGround() {
}