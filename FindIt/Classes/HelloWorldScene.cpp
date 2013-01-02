#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Util.h"
#include "ResourceManager.h"
#include "ImageInfo.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    setTouchEnabled(true);
    CCDirector::sharedDirector()->setContentScaleFactor(2);
    
    long time1 = Util::millisecondNow();
    ResourceManager* res = ResourceManager::sharedResourceManager();
    for (int i = 0; i < 1000; i++) {
        res->initImgInfo();
    }
    long time2 = Util::millisecondNow();
    CCLOG("%ld",Util::millisecondNow() - time1);
    for (int i = 0; i < 1000; i++) {
        res->loadImgRes();
    }
    CCLOG("%ld",Util::millisecondNow() - time2);

    CCSprite* imgFrame = CCSprite::create("imgFrame.png");
    imgFrame->setPosition(ccp(240, 160));
    this->addChild(imgFrame);
    int imgNo = arc4random()%4 + 1;
    initImg(CCString::createWithFormat("img%d",imgNo)->getCString(), 5);
    
    CCTextureCache::sharedTextureCache()->addImageAsync("img1.png", this, callfuncO_selector(HelloWorld::loadingCallBack));
    
    return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::initImg(const char *str, int pieceNum){
    ResourceManager* res = ResourceManager::sharedResourceManager();
    CCSpriteBatchNode* image = (CCSpriteBatchNode*)res->imgResDictionary->objectForKey(str);
    CCSprite* spritel = CCSprite::create();
    CCSprite* spriter = CCSprite::create();
    this->addChild(image);
    spritel->initWithTexture(image->getTexture(), CCRectMake(0,0,GET(IMG_WIDTH),GET(IMG_HEIGHT)));
    spritel->setPosition( CCDirector::sharedDirector()->convertToGL(ccp(GET((LEFT_IMG_X+IMG_WIDTH/2)), GET((LEFT_IMG_Y+IMG_HEIGHT/2)))) );
    spriter->initWithTexture(image->getTexture(), CCRectMake(0,0,GET(IMG_WIDTH),GET(IMG_HEIGHT)));
    spriter->setPosition( CCDirector::sharedDirector()->convertToGL(ccp(GET((RIGHT_IMG_X+IMG_WIDTH/2)), GET((RIGHT_IMG_Y+IMG_HEIGHT/2)))) );
    image->addChild(spritel, 0);
    image->addChild(spriter, 0);
    int* pieceNo = Util::genRandom(pieceNum, 9);
    for (int i = 0; i < 5; i++) {
        CCSprite* piece = CCSprite::create();
        ImageInfo* imgInfo = (ImageInfo*)res->imgInfoDictionary->objectForKey(str);
        piece->initWithTexture(image->getTexture(), CCRectMake(GET(imgInfo->point[pieceNo[i]].x), GET(imgInfo->point[pieceNo[i]].y), GET(imgInfo->point[pieceNo[i]].width), GET(imgInfo->point[pieceNo[i]].height)));
        piece->setPosition(CCDirector::sharedDirector()->convertToGL(ccp(GET((RIGHT_IMG_X+imgInfo->point[pieceNo[i]].x0)), GET((RIGHT_IMG_Y+imgInfo->point[pieceNo[i]].y0)))));
        image->addChild(piece, 1);
    }
    free(pieceNo);
}

void HelloWorld::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, false);//最后一个参数设为true将会吞下这个事件
    CCLayer::registerWithTouchDispatcher();
}

bool HelloWorld::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCPoint pt = pTouch->getLocationInView();
    CCLOG("x:%f , y:%f",pt.x,pt.y);
    return true;
}

void HelloWorld::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event){
}

void HelloWorld::loadingCallBack(cocos2d::CCObject* obj){
    CCLOG("obj is %@",obj);
}
