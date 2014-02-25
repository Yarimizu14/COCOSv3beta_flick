#include "GameScene.h"
#include "ballFactory.h"

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
