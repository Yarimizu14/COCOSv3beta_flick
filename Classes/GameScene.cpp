#include "GameScene.h"

USING_NS_CC;

BallFactory* bFactory = new BallFactory();

// 弾いた強さを測定するための変数
Point startPoint, userForce;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Point(0,0));
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer, 0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(GameScene::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    
    this->setTag(1000);
    
    // =========イベントの設置=========
    auto touchListener = EventListenerTouchOneByOne::create();
    
    // CC_CALLBACK_2の2はいくつ引数をとるか
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::touchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::touchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameScene::touchEnded, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(GameScene::touchCancelled, this);
    
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    // *これをtrueにするとBallPhysicsやTargetPhysicsなどこのSceneにaddChildしたオブジェクトのtouchイベントは発火しない
    //touchListener->setSwallowTouches(true);
    
    // =========壁の設置=========
    // 画面と同じサイズで物理境界（Physics Boundary）を生成
    auto body = PhysicsBody::createEdgeBox(visibleSize, GroundMaterial, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);
    
    // ４方向に壁を作るクラス
    GroundPhysics* gp = new GroundPhysics();
    
    Sprite* g_bottom = gp->createGround(Point(visibleSize.width/2,0), Size(visibleSize.width, 10));
    this->addChild(g_bottom);
    
    Sprite* g_top = gp->createGround(Point(visibleSize.width/2,visibleSize.height), Size(visibleSize.width, 10));
    this->addChild(g_top);
   
    Sprite* g_left = gp->createGround(Point(0, visibleSize.height/2), Size(visibleSize.width, 10));
    g_left->setRotation(90);
    this->addChild(g_left);
    
    Sprite* g_right = gp->createGround(Point(visibleSize.width, visibleSize.height/2), Size(visibleSize.width, 10));
    g_right->setRotation(-90);
    this->addChild(g_right);
    
    return true;
}

// タッチが始まったときの処理
// * return falseにするとmoved, endedなどの処理は行われない
bool GameScene::touchBegan(Touch* touch, Event* event) {
    
    // タッチ開始点
    startPoint = touch->getLocation();
    
    // 加える力の初期化
    userForce = Point(0.0f, 0.0f);
    
    //event->stopPropagation();
    
    return true;
}

// タッチする指を動かしたときの処理
void GameScene::touchMoved(Touch *touch, Event* event) {
    
    userForce = touch->getLocation().operator-(startPoint);
    
}

// タッチが終わったときの処理
void GameScene::touchEnded(Touch* touch, Event* event) {
    
    // 動かした距離を測定
    float distance = userForce.getLengthSq();
    
    // 動かした距離が小さい場合はターゲットを設置する
    if (distance < 100) {
        // ファクトリーからターゲットを作成
        TargetPhysics* tret = bFactory->createTarget(touch->getLocation());
        this->addChild(tret, 2);
    } else {
        // ファクトリーからボールを生成
        BallPhysics* ret = bFactory->createBall(touch->getLocation(), userForce);
        this->addChild(ret, 1);
    }
    
}

void GameScene::touchCancelled(Touch* touch, Event* event) {
}

void GameScene::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
