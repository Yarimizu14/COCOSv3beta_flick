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

Sprite* BallFactory::createBall(Point p) {
    // スプライトの生成と追加
	auto pSprite = Sprite::create("star.png");
	pSprite->setPosition(p);
    
	// 剛体の生成
	auto material = PHYSICSBODY_MATERIAL_DEFAULT;
	material.density     = 1.0f; // 密度
	material.restitution = 0.9f; // 反発係数
	material.friction    = 0.5f; // 摩擦係数
	auto pBody = PhysicsBody::createBox(pSprite->getContentSize(), material);
    pBody->setVelocity(Vect(0.0f, -WORLD_TO_SCREEN(9.8f)));
	//pBody->setDynamic(false); // 地面は重力の影響を受けない
   
	// スプライトに剛体を関連付ける
	pSprite->setPhysicsBody(pBody);
    
    return pSprite;
}