//
//  GameLogo.h
//  FindIt
//
//  Created by yin yi on 2012/12/15.
//
//

#ifndef __FindIt__GameLogo__
#define __FindIt__GameLogo__

#include "cocos2d.h"

class GameLogo : public cocos2d::CCLayer {
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC(GameLogo);
    
    void changeScene();
};

#endif /* defined(__FindIt__GameLogo__) */
