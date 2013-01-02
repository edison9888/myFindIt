//
//  ResourceManager.cpp
//  FindIt
//
//  Created by yin yi on 2012/10/24.
//
//

#include "ResourceManager.h"
#include "Util.h"
#include "ImageInfo.h"

using namespace cocos2d;

static ResourceManager* instance = NULL;

ResourceManager* ResourceManager::sharedResourceManager(){
    if (instance == NULL) {
        instance = new ResourceManager();
    }
    return instance;
}

ResourceManager::ResourceManager(){
    imgInfoDictionary = new CCDictionary();
    imgResDictionary = new CCDictionary();
}

ResourceManager::~ResourceManager(){
    imgInfoDictionary->release();
    imgResDictionary = NULL;
    imgInfoDictionary->release();
    imgInfoDictionary = NULL;
}

void ResourceManager::initImgInfo(){
    for (int i = 0; i < IMG_RESOURCE_SIZE; i++) {
        CCDictionary* img;
        img = GET_DICTIONARY(Util::getPlist(), CCString::createWithFormat("img%d",i+1)->getCString());
        ImageInfo* imginfo = new ImageInfo();

        imginfo->imgName = GET_STRING(img, "name");
        PointInfo pinfo[9];
        for (int j = 0; j < 9; j++) {
            CCDictionary* point;
            point = GET_DICTIONARY(img, CCString::createWithFormat("point%d",j+1)->getCString());
            CCString* str_x0 = GET_STRING(point, "x0");
            CCString* str_y0 = GET_STRING(point, "y0");
            CCString* str_x = GET_STRING(point, "x");
            CCString* str_y = GET_STRING(point, "y");
            CCString* str_width = GET_STRING(point, "width");
            CCString* str_height = GET_STRING(point, "height");
            pinfo[j].x0 = atof(str_x0->getCString());
            pinfo[j].y0 = atof(str_y0->getCString());
            pinfo[j].x = atof(str_x->getCString());
            pinfo[j].y = atof(str_y->getCString());
            pinfo[j].width = atof(str_width->getCString());
            pinfo[j].height = atof(str_height->getCString());
        }
        imginfo->setPoint(pinfo);
        
        imgInfoDictionary->setObject(imginfo, CCString::createWithFormat("img%d",i+1)->getCString());
        imginfo->release();
    }
}

void ResourceManager::loadImgRes(){
    for (int i = 0; i < IMG_RESOURCE_SIZE; i++) {
        CCSpriteBatchNode* image = CCSpriteBatchNode::create(CCString::createWithFormat("img%d.png",(i+1))->getCString());
        imgResDictionary->setObject(image, CCString::createWithFormat("img%d",i+1)->getCString());
    }
}