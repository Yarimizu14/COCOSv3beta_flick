//
//  config.h
//  cocos_flick
//
//  Created by A13235 on 2014/02/24.
//
//

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "cocos2d.h";
#include "cocos-ext.h";
#include "Box2d/Box2d.h";

USING_NS_CC;
USING_NS_CC_EXT;

// 1メートルを32ピクセルとして定義
#define PTM_RATIO 32
// Box2D空間をピクセル単位に変換
#define WORLD_TO_SCREEN(n) ((n) * PTM_RATIO)

// 各オブジェクトのタグを定義
#define TAG_GROUND 100

// 密度、反発係数、摩擦係数の種類を定義
// *密度を1.0fなどにするとapplyForceなどにしたときに重くて殆ど影響を受けない
const struct PhysicsMaterial NormalMaterial = { 0.1f, 0.9f, 0.0f };
const struct PhysicsMaterial FeverMaterial  = { 0.1f, 0.9f, 0.0f };

const struct PhysicsMaterial GroundMaterial  = { 0.1f, 1.0f, 0.0f };

// ZOrderの定数定義（同階層だったぱ場合、ZOrderが大きい順にイベントが呼ばれる！？）
enum kZOrder {
    kZOrderMainLayer = 2,
    kZOrderBaseLayer = 1,
    
    kZOrderBall   = 100,
    kZOrderTarget = 200
};

// タグの定数定義
enum kTag {
    kTagMainLayer = 2,
    kTagBaseLayer = 1,
    
    // 100番台のタグはBallPhysics
    kTagBall   = 100,
    // 200番台のタグはTargetPhysics
    kTagTarget = 200
};

#endif
