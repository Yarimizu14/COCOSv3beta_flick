//
//  TargetPhysics.cpp
//  cocos_flick
//
//  Created by A13235 on 2014/02/26.
//
//

#include "TargetPhysics.h"

TargetPhysics::TargetPhysics() {
    // Spriteを継承したクラスを初期化するにはcreateではなくinitを使う
    this->initWithFile("target_normal_small.png");
    
    auto pBody = PhysicsBody::createBox(this->getContentSize(), NormalMaterial);
    
    // 動かないオブジェクトにする
    pBody->setDynamic(false);
    
	this->setPhysicsBody(pBody);
    
    auto touchListener = EventListenerTouchOneByOne::create();
    
    // CC_CALLBACK_2の2はいくつ引数をとるか
    touchListener->onTouchBegan = CC_CALLBACK_2(TargetPhysics::touchBegan, this);
    
    getEventDispatcher()->addEventListenerWithFixedPriority(touchListener, 100);
}

bool TargetPhysics::touchBegan(Touch *touch, Event* event) {
}

void TargetPhysics::touchEnded(Touch* touch, Event* event) {
}

void TargetPhysics::touchMoved(Touch *touch, Event* event) {
}

void TargetPhysics::touchCancelled(Touch* touch, Event* event) {
}