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

struct _physics {
    cocos2d::extension::PhysicsSprite *phSprite;
    b2BodyDef     phBodyDef;
    b2FixtureDef  phFixtureDef;
};

#endif
