//
//  Util.cpp
//  FindIt
//
//  Created by yin yi on 2012/10/20.
//
//

#include "Util.h"

using namespace cocos2d;

static CCDictionary *plist = NULL;

int* Util::genRandom(int dst , int src){
    int* random;
    random = (int*)malloc(sizeof(int) * dst);
    int* num;
    num = (int*)malloc(sizeof(int) * src);
    for(int i = 0;i < src;i++){
        num[i] = i+1;
    }
    int j;
    for(int i = 0;i < dst;i++){
        j = arc4random()%(src-i);
        random[i] = num[j];
        for(int k = j;k < src-1;k++){
            num[k] = num[k+1];
        }
    }
    return random;
}

cocos2d::CCDictionary* Util::getPlist(){
    if (plist == NULL) {
        plist = new CCDictionary();
        plist = CCDictionary::createWithContentsOfFile("imgsInfo.plist");
    }
    return plist;
}

long Util::millisecondNow(){
    struct cc_timeval now;
    CCTime::gettimeofdayCocos2d(&now, NULL);
    
    return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

cocos2d::CCPoint Util::LocalPoint(cocos2d::CCPoint p){
    return CCDirector::sharedDirector()->convertToGL(ccp(p.x/2, p.y/2));
}