//
//  BallFactory.cpp
//  cocos_flick
//
//  Created by A13235 on 2014/02/24.
//
//

#include "BallFactory.h"

BallFactory::BallFactory() {
};

/* TODO: BallPhysicsクラスのインスタンスを返すように変更（BallPhysicsクラスのメソッドからゲーム中のパワーアップやフィーバータイムの処理などを行う） */
/* TODO: 敵もこのファクトリーから生成出来るように？ */
BallPhysics* BallFactory::createBall(Point p) {
    
    this->ballNum++;
    // スプライトの生成と追加
    BallPhysics* pSprite = new BallPhysics();
    pSprite->setTag(this->ballNum);
	pSprite->setPosition(p);
    
    return pSprite;
}

BallPhysics* BallFactory::createBall(Point p, Point force) {
    
    // タグの番号を更新
    this->ballNum++;
    
    // スプライトの生成と追加
    BallPhysics* pSprite = new BallPhysics(force);
    pSprite->setTag(100 + this->ballNum);
	pSprite->setPosition(p);
    
    return pSprite;
}

TargetPhysics* BallFactory::createTarget(Point p) {
    
    // タグの番号を更新
    this->targetNum++;
    
    // スプライトの生成と追加
    TargetPhysics* pSprite = new TargetPhysics();
    pSprite->setTag(200 + this->targetNum);
	pSprite->setPosition(p);
    
    return pSprite;
}