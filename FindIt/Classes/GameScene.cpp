//
//  GameScene.cpp
//  FindIt
//
//  Created by yin yi on 2012/12/15.
//
//

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Util.h"
#include "ResourceManager.h"
#include "ImageInfo.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();
    
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
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    setTouchEnabled(true);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCDirector::sharedDirector()->setContentScaleFactor(2);
    
    ResourceManager* res = ResourceManager::sharedResourceManager();
    res->initImgInfo();
    res->loadImgRes();
    
    CCSprite* imgFrame = CCSprite::create("imgFrame.png");
    imgFrame->setPosition(ccp(240, 160));
    this->addChild(imgFrame);
    int imgNo = arc4random()%4 + 1;
    this->initImg(CCString::createWithFormat("img%d",imgNo)->getCString(), 5);
    this->scheduleUpdate();
    
    
    //    CCTextureCache::sharedTextureCache()->addImageAsync("img1.png", this, callfuncO_selector(GameScene::loadingCallBack));//CCTextureCache用于缓存纹理的cache，用这种方式添加的图片都将缓存到一个cache中，addImageAsync是一个异步的加载方式，可以用于较大的资源加载。
    
    return true;
}

void GameScene::update(float dt){
    
}

void GameScene::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameScene::initImg(const char *str, int pieceNum){
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

void GameScene::registerWithTouchDispatcher(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, false);//最后一个参数设为true将会吞下这个事件
    CCLayer::registerWithTouchDispatcher();
}

bool GameScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCPoint pt = pTouch->getLocationInView();
    CCRect rect = CCRectMake(0, 0, 480, 320);
    if (rect.containsPoint(pt)) {
        CCLOG("in RECT!");
    }
    CCLOG("x:%f , y:%f",pt.x,pt.y);
    return true;
}

void GameScene::ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event){
    
}

bool GameScene::findRect(){
    
}