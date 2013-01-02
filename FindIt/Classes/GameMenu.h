//
//  GameMenu.h
//  FindIt
//
//  Created by yin yi on 2012/12/15.
//
//

#ifndef __FindIt__GameMenu__
#define __FindIt__GameMenu__

#include "cocos2d.h"

class GameMenu : public cocos2d::CCLayer {
    
    int popStep;
    int popState;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(GameMenu);
    
    void changeChuangGuanLayer();
    void changeXiuXianLayer();
    void changeDuoRenLayer();
    void menuCallBack();
    
    virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesMoved(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    virtual void ccTouchesEnded(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
    
    virtual void update(float dt);
};

#endif /* defined(__FindIt__GameMenu__) */
