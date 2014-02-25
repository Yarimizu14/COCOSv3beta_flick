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
    
    // スプライトの生成と追加
    BallPhysics* pSprite = new BallPhysics();
	pSprite->setPosition(p);
    
    return pSprite;
}