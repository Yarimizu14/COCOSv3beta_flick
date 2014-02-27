//
//  bulletPhysics.cpp
//  cocos_flick
//
//  Created by A13235 on 2014/02/25.
//
//

#include "BallPhysics.h"

BallPhysics::BallPhysics() {
}

BallPhysics::BallPhysics(Point force) {
    
    // Spriteを継承したクラスを派生クラスのコンストラクタで初期化するにはcreateではなくinitを使う
    this->initWithFile("star.png");
    
    auto pBody = PhysicsBody::createBox(this->getContentSize(), NormalMaterial);
    pBody->setDynamic(true);
    
    // 物体に力（force）を加える
    // TODO: 力の強さの調整
    pBody->applyImpulse(Vect(force.x * 500.0f, force.y * 500.0f));
    
    // *第２引数は力を加える位置のオフセット（設定しないと物体の角に力が加わるため回転してしまう）
    //pBody->applyImpulse(Vect(force.x * 500.0f, force.y * 500.0f), this->getPosition());
    
    // *forceをそのまま速度にする場合
    //pBody->setVelocity(force);
    
	this->setPhysicsBody(pBody);
    
    // １本指でのタップを検出する場合
    auto touchListener = EventListenerTouchOneByOne::create();
    
    // *2本指でのタップを検出する場合
    //auto touchListener = EventListenerTouchAllAtOnce::create();
    
    
    // =========イベントの設置=========
    // CC_CALLBACK_2の2はいくつ引数をとるか
    touchListener->onTouchBegan = CC_CALLBACK_2(BallPhysics::touchBegan, this);
    
    // *ラムダ式を使ったイベントの設定の仕方（CC_CALLBACK_2と同じ！？）
    /*
    touchListener->onTouchBegan = [](Touch* touch, Event* event) {
        log("test");
        return true;
    };
     */
    
    // trueに設定するとこのイベントリスナーが通知を受け取った時点で、下位のリスナーに通知がいかなくなる
    //touchListener->setSwallowTouches(true);
    
    getEventDispatcher()->addEventListenerWithFixedPriority(touchListener, 100);
}

bool BallPhysics::touchBegan(Touch* touch, Event* event) {
    
    Node* t = event->getCurrentTarget();
    if (t == 0) {
        log("test:%d", t);
    } else {
        log("tag : %d", event->getCurrentTarget()->getTag());
    }
    return true;
    
}

void BallPhysics::touchMoved(Touch *touch, Event* event) {
}

void BallPhysics::touchEnded(Touch* touch, Event* event) {
}

void BallPhysics::touchCancelled(Touch* touch, Event* event) {
}