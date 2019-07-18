//
//  HueSatSpriteNode.hpp
//
//  Created by Thibaut De Bock on 7/18/19.
//

#ifndef HueSatSpriteNode_hpp
#define HueSatSpriteNode_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class HueSatSpriteNode: public Sprite {
private:
    HueSatSpriteNode();
    ~HueSatSpriteNode();
    void setup(Vec3 hsv);
    void setShaderOpacity(float opacity);
    
public:
    static HueSatSpriteNode* create(const std::string& filename, Vec3 hsv = Vec3(0.0f, 1.0f, 1.0f));
    static HueSatSpriteNode* createWithSpriteFrameName(const std::string& filename, Vec3 hsv = Vec3(0.0f, 1.0f, 1.0f));
    void setShaderHSV(Vec3 hsv);
    virtual void setOpacity(GLubyte opacity);
};

#endif /* HueSatSpriteNode_hpp */
