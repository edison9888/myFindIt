//
//  Util.h
//  FindIt
//
//  Created by yin yi on 2012/10/20.
//
//

#ifndef __FindIt__Util__
#define __FindIt__Util__

#include "cocos2d.h"

class Util : cocos2d::CCObject
{
public:
    static int* genRandom(int dst , int src);
    static cocos2d::CCDictionary* getPlist();
    static long millisecondNow();
    static cocos2d::CCPoint LocalPoint(cocos2d::CCPoint p);
};

#endif /* defined(__FindIt__Util__) */
