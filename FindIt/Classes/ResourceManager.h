//
//  ResourceManager.h
//  FindIt
//
//  Created by yin yi on 2012/10/24.
//
//

#ifndef __FindIt__ResourceManager__
#define __FindIt__ResourceManager__

#include "cocos2d.h"

#define IMG_RESOURCE_SIZE 4
#define LEFT_IMG_X 70
#define LEFT_IMG_Y 42
#define RIGHT_IMG_X 489
#define RIGHT_IMG_Y 42
#define IMG_WIDTH 403
#define IMG_HEIGHT 543

class ResourceManager : cocos2d::CCObject
{
public:
    ResourceManager();
    virtual ~ResourceManager();
    static ResourceManager* sharedResourceManager();
    void loadImgRes();
    void initImgInfo();
    
    cocos2d::CCDictionary* imgInfoDictionary;
    cocos2d::CCDictionary* imgResDictionary;
};

#endif /* defined(__FindIt__ResourceManager__) */
