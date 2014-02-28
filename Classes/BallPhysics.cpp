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
    
    // =========物理演算設定=========
    // 物体に力（force）を加える
    // TODO: 力の強さの調整
    pBody->applyImpulse(Vect(force.x * 500.0f, force.y * 500.0f));
    
    // *第２引数は力を加える位置のオフセット（設定しないと物体の角に力が加わるため回転してしまう）
    //pBody->applyImpulse(Vect(force.x * 500.0f, force.y * 500.0f), this->getPosition());
    
    // *forceをそのまま速度にする場合
    //pBody->setVelocity(force);
    
	this->setPhysicsBody(pBody);
    
    // =========指の本数を設定=========
    // タッチリスナーの生成（１本指でのタップを検出する場合）
    auto touchListener = EventListenerTouchOneByOne::create();
    
    // タッチリスナーの生成（*2本指でのタップを検出する場合）
    //auto touchListener = EventListenerTouchAllAtOnce::create();
    
    
    // =========イベントの設置=========
    // TODO: 方法１と方法2の違いを調べる
    // 【方法1】CC_CALLBACK_2の2はいくつ引数をとるか
    touchListener->onTouchBegan = CC_CALLBACK_2(BallPhysics::touchBegan, this);
    
    // *【方法2】ラムダ式を使ったイベントの設定の仕方（CC_CALLBACK_2と同じ！？）
    /*
    touchListener->onTouchBegan = [](Touch* touch, Event* event) {
        log("test");
        return true;
    };
     */
    
    // =========イベント発火の優先順位の変更=========
    // 【方法1】イベントの優先度合い数値を第2引数に指定（０が最も優先度が高く大きくなるほど優先順位が下がる）
    //this->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener, 100);
    
    // 【方法2】第2引数で指定したオブジェクトのZIndexでイベント発火の優先度を指定
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    // =========イベント伝播の設定=========
    // trueに設定するとこのイベントリスナーが通知を受け取った時点で、下位（このオブジェクトにaddChildされているオブジェクトなど）のリスナーに通知がいかなくなる
    //touchListener->setSwallowTouches(true);

}

bool BallPhysics::touchBegan(Touch* touch, Event* event) {
    log("BallPhysics is touched : Tag    = %d", this->getTag());
    log("BallPhysics is touched : Zindex = %d", this->getZOrder());
    
    // addEventListenerWithSceneGraphPriorityの第2引数で指定されたオブジェクトを取得する！？
    // *event->getCurrentTarget() returns the *listener's* sceneGraphPriority node.
    Sprite* t = (Sprite*) event->getCurrentTarget();
    
    if (t == 0) {   // オブジェクトがない場合、getCurrentTargetは0を返す
        log("BallPhysics is touched : Target = %d", t);
    } else {
        log("BallPhysics is touched : Target = %d", event->getCurrentTarget()->getTag());
    }

    return true;
    
}

void BallPhysics::touchMoved(Touch *touch, Event* event) {
}

void BallPhysics::touchEnded(Touch* touch, Event* event) {
}

void BallPhysics::touchCancelled(Touch* touch, Event* event) {
}