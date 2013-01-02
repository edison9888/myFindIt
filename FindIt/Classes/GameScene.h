//
//  GameScene.h
//  FindIt
//
//  Created by yin yi on 2012/12/15.
//
//

#ifndef __FindIt__GameScene__
#define __FindIt__GameScene__

#include "cocos2d.h"

class GameScene : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(GameScene);
    
    void initImg(const char *str,int pieceNum);
    
    virtual void registerWithTouchDispatcher();
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    virtual void update(float dt);
    
    bool findRect();
    
    //    void loadingCallBack(cocos2d::CCObject* obj);//addImageAsync的回调函数，其中的obj既是创建好的图片纹理
    
};

#endif /* defined(__FindIt__GameScene__) */
