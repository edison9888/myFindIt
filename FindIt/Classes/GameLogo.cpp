//
//  GameLogo.cpp
//  FindIt
//
//  Created by yin yi on 2012/12/15.
//
//

#include "GameLogo.h"
#include "GameMenu.h"

using namespace cocos2d;

bool GameLogo::init(){
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    setTouchEnabled(true);
    CCDirector::sharedDirector()->setContentScaleFactor(2.0);
    CCSprite* logo = CCSprite::create("logo.png");
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    logo->setPosition(ccp(size.width/2, size.height/2));
    CCSprite* heart = CCSprite::create("heart.png");
    heart->setPosition(ccp(size.width/2, size.height/2));
    addChild(logo);
    addChild(heart);
    CCScaleTo* scaleHeart1 = CCScaleTo::create(0.5, 1.2);
    CCScaleTo* scaleHeart2 = CCScaleTo::create(0.5, 1.0);
    CCEaseExponentialIn* ease1 = CCEaseExponentialIn::create(scaleHeart1);
    CCEaseExponentialOut* ease2 = CCEaseExponentialOut::create(scaleHeart2);
    CCCallFunc* func = CCCallFunc::create(this, callfunc_selector(GameLogo::changeScene));
    CCFiniteTimeAction* sequence = CCSequence::create(ease1,ease2,ease1,ease2,func,NULL);
    heart->runAction(sequence);
    CCLabelTTF *myLabel = CCLabelTTF::create("Copyright (C) 2002", "Helvetica-Oblique", 10);
    myLabel->setPosition(CCDirector::sharedDirector()->convertToGL(ccp(size.width/2, size.height - 20)));
    myLabel->setColor(ccc3(0, 0, 0));
    addChild(myLabel);
    return true;
}

CCScene* GameLogo::scene(){
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLogo *layer = GameLogo::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

void GameLogo::changeScene(){
    CCScene* nextScene = GameMenu::scene();
    CCTransitionFade* trans = CCTransitionFade::create(1, nextScene);
    CCDirector::sharedDirector()->replaceScene(trans);
}