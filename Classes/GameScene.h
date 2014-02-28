#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "config.h"
#include "BallFactory.h"
#include "GroundPhysics.h"

using namespace cocos2d;

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual void initEvent();
    virtual void initGround();
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    
    bool touchBegan(Touch *touch, Event* event);
    void touchEnded(Touch* touch, Event* event);
    void touchMoved(Touch *touch, Event* event);
    void touchCancelled(Touch* touch, Event* event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
};

#endif // __HELLOWORLD_SCENE_H__
