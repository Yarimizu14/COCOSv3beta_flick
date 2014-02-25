//
//  bulletPhysics.cpp
//  cocos_flick
//
//  Created by A13235 on 2014/02/25.
//
//

#include "BallPhysics.h"

BallPhysics::BallPhysics() {
    // Spriteを継承したクラスを初期化するにはcreateではなくinitを使う
    this->initWithFile("star.png");
    
    auto pBody = PhysicsBody::createBox(this->getContentSize(), NormalMaterial);
    pBody->setVelocity(Vect(0.0f, -WORLD_TO_SCREEN(9.8f)));
	//pBody->setDynamic(false); // 地面は重力の影響を受けない
    
	this->setPhysicsBody(pBody);
}