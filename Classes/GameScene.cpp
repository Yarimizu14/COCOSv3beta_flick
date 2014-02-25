#include "GameScene.h"

USING_NS_CC;

BallFactory* bFactory = new BallFactory();

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

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
    
    auto touchListener = EventListenerTouchOneByOne::create();
    // CC_CALLBACK_2の2はいくつ引数をとるか
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::touchBegan, this);
    getEventDispatcher()->addEventListenerWithFixedPriority(touchListener, 100);
    
    // 画面と同じサイズで物理境界（Physics Boundary）を生 成
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

bool GameScene::touchBegan(Touch* touch, Event* event) {
    
    // ファクトリーからボールを生成
    Sprite* ret = bFactory->createBall(touch->getLocation());
    this->addChild((Sprite*)ret);

    
    return true;
}

void GameScene::menuCloseCallback(Object* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
