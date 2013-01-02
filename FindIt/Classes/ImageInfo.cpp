//
//  ImageInfo.cpp
//  FindIt
//
//  Created by yin yi on 2012/10/24.
//
//

#include "ImageInfo.h"

using namespace cocos2d;

ImageInfo::ImageInfo(){
    
}

ImageInfo::~ImageInfo(){
    imgName = new cocos2d::CCString();
}

void ImageInfo::setImgName(cocos2d::CCString str){
    
}

void ImageInfo::setPoint(PointInfo *p){
    for (int i = 0; i < POINTSIZE; i++) {
        point[i] = p[i];
    }
}
