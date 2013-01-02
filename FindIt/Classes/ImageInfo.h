//
//  ImageInfo.h
//  FindIt
//
//  Created by yin yi on 2012/10/24.
//
//

#ifndef __FindIt__ImageInfo__
#define __FindIt__ImageInfo__

#include "cocos2d.h"

#define POINTSIZE 9

typedef struct PointInfo{
    float x0;
    float y0;
    float x;
    float y;
    float width;
    float height;
}PointInfo;

class ImageInfo : public cocos2d::CCObject {
public:
    ImageInfo();
    virtual ~ImageInfo();
    
    void setImgName(cocos2d::CCString str);

    void setPoint(PointInfo* p);
    
    cocos2d::CCString* imgName;
    PointInfo point[POINTSIZE];
};

#endif /* defined(__FindIt__ImageInfo__) */
