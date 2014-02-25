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
Sprite* BallFactory::createBall(Point p) {
    // スプライトの生成と追加
	auto pSprite = Sprite::create("star.png");
	pSprite->setPosition(p);
    
	// 剛体の生成
	auto pBody = PhysicsBody::createBox(pSprite->getContentSize(), NormalMaterial);
    pBody->setVelocity(Vect(0.0f, -WORLD_TO_SCREEN(9.8f)));
	//pBody->setDynamic(false); // 地面は重力の影響を受けない
   
	// スプライトに剛体を関連付ける
	pSprite->setPhysicsBody(pBody);
    
    return pSprite;
}