//
//  GameMenu.cpp
//  FindIt
//
//  Created by yin yi on 2012/12/15.
//
//

#include "GameMenu.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"
#include "Util.h"

#define WHALE 0
#define STAGEMODE 1
#define RELAXMODE 2
#define MULTIMODE 3
#define HELP 4
#define RANK 5
#define SETTING 6
#define BOAT 7
#define CLOUD1 8
#define CLOUD2 9
#define SHARE 10
#define SHAREPOP 11
#define TITLE 12
#define LIGHT 13
#define HALOS 14
#define SEAWAVE1 15
#define SEAWAVE2 16
#define SEAWAVE3 17
#define MENUBG 18
#define FAN11 19
#define FAN12 20
#define FAN21 21
#define FAN22 22

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* GameMenu::scene(){
    CCScene* scene = CCScene::create();
    CCLayer* layer = GameMenu::create();
    scene->addChild(layer);
    return scene;
}

bool GameMenu::init(){
    if (!CCLayer::init()) {
        return false;
    }
    setTouchEnabled(true);
    CCDirector::sharedDirector()->setContentScaleFactor(2.0);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainMenu.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainMenuBg.plist");
    CCSprite* seaWave1 = CCSprite::createWithSpriteFrameName("seaWave1.png");
    CCSprite* seaWave2 = CCSprite::createWithSpriteFrameName("seaWave2.png");
    CCSprite* seaWave3 = CCSprite::createWithSpriteFrameName("seaWave3.png");
    CCSprite* menuBg = CCSprite::createWithSpriteFrameName("bg.png");
    CCSprite* whale = CCSprite::createWithSpriteFrameName("whale.png");
    CCSprite* stageMode = CCSprite::createWithSpriteFrameName("stageMode.png");
    CCSprite* stageModed = CCSprite::createWithSpriteFrameName("stageMode.png");
    CCSprite* relaxMode = CCSprite::createWithSpriteFrameName("relaxMode.png");
    CCSprite* relaxModed = CCSprite::createWithSpriteFrameName("relaxMode.png");
    CCSprite* multiMode = CCSprite::createWithSpriteFrameName("multiMode.png");
    CCSprite* multiModed = CCSprite::createWithSpriteFrameName("multiMode.png");
    CCSprite* help = CCSprite::createWithSpriteFrameName("help.png");
    CCSprite* helped = CCSprite::createWithSpriteFrameName("help.png");
    CCSprite* rank = CCSprite::createWithSpriteFrameName("rank.png");
    CCSprite* ranked = CCSprite::createWithSpriteFrameName("rank.png");
    CCSprite* setting = CCSprite::createWithSpriteFrameName("setting.png");
    CCSprite* settinged = CCSprite::createWithSpriteFrameName("setting.png");
    CCSprite* boat = CCSprite::createWithSpriteFrameName("boat.png");
    CCSprite* cloud1 = CCSprite::createWithSpriteFrameName("cloud1.png");
    CCSprite* cloud2 = CCSprite::createWithSpriteFrameName("cloud2.png");
    CCSprite* share = CCSprite::createWithSpriteFrameName("share.png");
    CCSprite* sharePop = CCSprite::create("sharePop.png");
    CCSprite* title = CCSprite::createWithSpriteFrameName("title.png");
    CCSprite* light = CCSprite::create("light.png");
    CCSprite* halos = CCSprite::createWithSpriteFrameName("halos.png");
    CCSprite* fan11 = CCSprite::createWithSpriteFrameName("fan1-1.png");
    CCSprite* fan12 = CCSprite::createWithSpriteFrameName("fan1-2.png");
    CCSprite* fan21 = CCSprite::createWithSpriteFrameName("fan2-1.png");
    CCSprite* fan22 = CCSprite::createWithSpriteFrameName("fan2-2.png");
    
    CCRotateBy* lightRotate = CCRotateBy::create(20, 180);
    CCRepeatForever* lightRepeat = CCRepeatForever::create(lightRotate);
    light->runAction(lightRepeat);
    
    stageModed->setScale(1.1);
    relaxModed->setScale(1.1);
    multiModed->setScale(1.1);
    helped->setScale(1.1);
    ranked->setScale(1.1);
    settinged->setScale(1.1);
    CCMenuItemSprite* stageSprite = CCMenuItemSprite::create(stageMode, stageModed, this, menu_selector(GameMenu::changeChuangGuanLayer));
    CCMenuItemSprite* relaxSprite = CCMenuItemSprite::create(relaxMode, relaxModed, this, menu_selector(GameMenu::changeChuangGuanLayer));
    CCMenuItemSprite* multiSprite = CCMenuItemSprite::create(multiMode, multiModed, this, menu_selector(GameMenu::changeChuangGuanLayer));
    CCMenuItemSprite* helpSprite = CCMenuItemSprite::create(help, helped, this, menu_selector(GameMenu::changeChuangGuanLayer));
    CCMenuItemSprite* rankSprite = CCMenuItemSprite::create(rank, ranked, this, menu_selector(GameMenu::changeChuangGuanLayer));
    CCMenuItemSprite* settingSprite = CCMenuItemSprite::create(setting, settinged, this, menu_selector(GameMenu::changeChuangGuanLayer));
    CCMenu* stage = CCMenu::create(stageSprite,NULL);
    CCMenu* relax = CCMenu::create(relaxSprite,NULL);
    CCMenu* multi = CCMenu::create(multiSprite,NULL);
    CCMenu* helpMenu = CCMenu::create(helpSprite,NULL);
    CCMenu* rankMenu = CCMenu::create(rankSprite,NULL);
    CCMenu* settingMenu = CCMenu::create(settingSprite,NULL);
    
    whale->setPosition(Util::LocalPoint(ccp(482.5, 517)));
    stage->setPosition(Util::LocalPoint(ccp(512.5, 457.5)));
    relax->setPosition(Util::LocalPoint(ccp(694.5, 521.5)));
    multi->setPosition(Util::LocalPoint(ccp(868.5, 438.5)));
    helpMenu->setPosition(Util::LocalPoint(ccp(752.5, 50.5)));
    rankMenu->setPosition(Util::LocalPoint(ccp(832.5, 50.5)));
    settingMenu->setPosition(Util::LocalPoint(ccp(912.5, 50.5)));
    boat->setPosition(Util::LocalPoint(ccp(461, 293)));
    cloud1->setPosition(Util::LocalPoint(ccp(101.5, 183.5)));
    cloud2->setPosition(Util::LocalPoint(ccp(864.5, 127)));
    share->setPosition(Util::LocalPoint(ccp(40.5, 520.5)));
    sharePop->setPosition(Util::LocalPoint(ccp(40.5, 530.5)));
    title->setPosition(Util::LocalPoint(ccp(481.5, 139.5)));
    light->setPosition(Util::LocalPoint(ccp(484.5, 320)));
    halos->setPosition(Util::LocalPoint(ccp(477.5, 241.5)));
    seaWave1->setPosition(Util::LocalPoint(ccp(480, 492.5)));
    seaWave2->setPosition(Util::LocalPoint(ccp(480, 477.5)));
    seaWave3->setPosition(Util::LocalPoint(ccp(480, 463)));
    menuBg->setPosition(Util::LocalPoint(ccp(480, 320)));
    fan11->setPosition(Util::LocalPoint(ccp(616, 226.5)));
    fan12->setPosition(Util::LocalPoint(ccp(614, 237)));
    fan21->setPosition(Util::LocalPoint(ccp(369.5, 197)));
    fan22->setPosition(Util::LocalPoint(ccp(362, 220.5)));
    
    CCMoveTo* cloud1Move = CCMoveTo::create(3, Util::LocalPoint(ccp(140, 190)));
    CCMoveTo* cloud1Moved = CCMoveTo::create(3, Util::LocalPoint(ccp(100, 180)));
    CCRepeatForever* cloudRp = CCRepeatForever::create((CCActionInterval*)CCSequence::create(cloud1Move,cloud1Moved,NULL));
    cloud1->runAction(cloudRp);
    
    CCMoveTo* cloud2Move = CCMoveTo::create(3, Util::LocalPoint(ccp(845, 130)));
    CCMoveTo* cloud2Moved = CCMoveTo::create(3, Util::LocalPoint(ccp(875, 120)));
    CCRepeatForever* cloudRp2 = CCRepeatForever::create((CCActionInterval*)CCSequence::create(cloud2Move,cloud2Moved,NULL));
    cloud2->runAction(cloudRp2);
    
    CCMoveTo* seaMove = CCMoveTo::create(3, Util::LocalPoint(ccp(520, 492.5)));
    CCMoveTo* seaMoved = CCMoveTo::create(3, Util::LocalPoint(ccp(440, 492.5)));
    CCRepeatForever* seaMoveRp = CCRepeatForever::create((CCActionInterval*)CCSequence::create(seaMove,seaMoved,NULL));
    seaWave1->runAction(seaMoveRp);
    
    CCMoveTo* seaMove2 = CCMoveTo::create(3, Util::LocalPoint(ccp(435, 477.5)));
    CCMoveTo* seaMoved2 = CCMoveTo::create(3, Util::LocalPoint(ccp(525, 477.5)));
    CCRepeatForever* seaMove2Rp = CCRepeatForever::create((CCActionInterval*)CCSequence::create(seaMove2,seaMoved2,NULL));
    seaWave2->runAction(seaMove2Rp);
    
    CCMoveTo* seaMove3 = CCMoveTo::create(3, Util::LocalPoint(ccp(523, 463)));
    CCMoveTo* seaMoved3 = CCMoveTo::create(3, Util::LocalPoint(ccp(443, 463)));
    CCRepeatForever* seaMove3Rp = CCRepeatForever::create((CCActionInterval*)CCSequence::create(seaMove3,seaMoved3,NULL));
    seaWave3->runAction(seaMove3Rp);
    
    CCMoveTo* titleMove = CCMoveTo::create(1, Util::LocalPoint(ccp(481.5, 142)));
    CCMoveTo* titleMoved = CCMoveTo::create(1, Util::LocalPoint(ccp(481.5, 139)));
    CCRepeatForever* titleMoveRp = CCRepeatForever::create((CCActionInterval*)CCSequence::create(titleMove,titleMoved,NULL));
    title->runAction(titleMoveRp);
    
    CCRotateBy* fan1rotate = CCRotateBy::create(1, 270);
    CCRepeatForever* fan1repeat = CCRepeatForever::create(fan1rotate);
    fan11->runAction(fan1repeat);
    
    CCRotateBy* fan2rotate = CCRotateBy::create(1, 180);
    CCRepeatForever* fan2repeat = CCRepeatForever::create(fan2rotate);
    fan21->runAction(fan2repeat);
    
    addChild(whale, 8, WHALE);
    addChild(stage, 9, STAGEMODE);
    addChild(relax, 9, RELAXMODE);
    addChild(multi, 9, MULTIMODE);
    addChild(helpMenu, 9, HELP);
    addChild(rankMenu, 9, RANK);
    addChild(settingMenu, 9, SETTING);
    addChild(boat, 6, BOAT);
    addChild(cloud1, 9, CLOUD1);
    addChild(cloud2, 9, CLOUD2);
    addChild(share, 9, SHARE);
    addChild(sharePop, 8, SHAREPOP);
    addChild(title, 9, TITLE);
    addChild(light, 2, LIGHT);
    addChild(halos, 3, HALOS);
    addChild(seaWave1, 7, SEAWAVE1);
    addChild(seaWave2, 5, SEAWAVE2);
    addChild(seaWave3, 4, SEAWAVE3);
    addChild(menuBg, 1, MENUBG);
    addChild(fan11, 9, FAN11);
    addChild(fan12, 8, FAN12);
    addChild(fan21, 9, FAN21);
    addChild(fan22, 8, FAN22);
    
    this->scheduleUpdate();
    
    popStep = -1;
    popState = -1;

    return true;
}

void GameMenu::update(float dt){
    //弹框相关
    if (popState == 0 && popStep >= 0 && popStep < 122.5) {
        popStep = popStep + 16;
        CCSprite* sharePop = (CCSprite*)getChildByTag(SHAREPOP);
        sharePop->setTextureRect(CCRectMake(0, 0, 27.5, popStep));
        sharePop->setPosition(ccp(sharePop->getPositionX(), sharePop->getPositionY()+8));
    }else if(popState == -1){
        CCSprite* sharePop = (CCSprite*)getChildByTag(SHAREPOP);
        sharePop->setTextureRect(CCRectMake(0, 0, 0, 0));
        sharePop->setPosition(Util::LocalPoint(ccp(40.5, 530.5)));
    }else if (popState == 1){
        popStep = popStep - 16;
        CCSprite* sharePop = (CCSprite*)getChildByTag(SHAREPOP);
        if (popStep < 0) {
            popStep = -1;
            popState = -1;
        }else{
            sharePop->setTextureRect(CCRectMake(0, 0, 27.5, popStep));
            sharePop->setPosition(ccp(sharePop->getPositionX(), sharePop->getPositionY()-8));
        }
    }
}

void GameMenu::changeChuangGuanLayer(){
    /*
    CCScene* nextScene = GameScene::scene();
    CCTransitionCrossFade* trans = CCTransitionCrossFade::create(1, nextScene);
    CCDirector::sharedDirector()->replaceScene(trans);
     */
}

void GameMenu::changeDuoRenLayer(){
    
}

void GameMenu::changeXiuXianLayer(){
    
}

void GameMenu::menuCallBack(){
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void GameMenu::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
//    CCSetIterator it = pTouches->begin();
//    CCTouch* touch = (CCTouch*)(*it);
//    CCPoint touchPoint = touch->getLocation();
//    CCParticleSystem *bingo = CCParticleSystemQuad::create("bingo.plist");
//    bingo->setPosition(touchPoint);
//    addChild(bingo,10);
}

void GameMenu::ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    
}

void GameMenu::ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent){
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();
    CCRect rect = CCRectMake(5, 40, 35, 35);
//弹框相关
    if (rect.containsPoint(touchPoint)) {
        if (popState == -1) {
            popStep = 0;
            popState = 0;
        }else if (popStep > 122){
            popStep = 127;
            popState = 1;
        }
    }
}