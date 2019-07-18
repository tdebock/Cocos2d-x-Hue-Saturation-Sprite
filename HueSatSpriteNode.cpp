//
//  HueSatSpriteNode.cpp
//
//  Created by Thibaut De Bock on 7/18/19.
//

#include "HueSatSpriteNode.hpp"

HueSatSpriteNode::HueSatSpriteNode() {}
HueSatSpriteNode::~HueSatSpriteNode() {}

HueSatSpriteNode* HueSatSpriteNode::create(const std::string& filename, Vec3 hsv) {
    HueSatSpriteNode* sprite = new HueSatSpriteNode();
    if (sprite->initWithFile(filename)) {
        sprite->autorelease();
        sprite->setup(hsv);
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}

HueSatSpriteNode* HueSatSpriteNode::createWithSpriteFrameName(const std::string& filename, Vec3 hsv) {
    HueSatSpriteNode* sprite = new HueSatSpriteNode();
    if (sprite->initWithSpriteFrameName(filename)) {
        sprite->autorelease();
        sprite->setup(hsv);
        return sprite;
    }
    CC_SAFE_DELETE(sprite);
    return NULL;
}

void HueSatSpriteNode::setup(Vec3 hsv) {
    std::string shaderPath = FileUtils::getInstance()->fullPathForFilename("HueSatOpacityShader.fsh");
    const GLchar* frag = String::createWithContentsOfFile(shaderPath.c_str())->getCString();
    GLProgram *hueGLProgram = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, frag);
    hueGLProgram->use();
    
    this->setGLProgram(hueGLProgram);
    this->setShaderHSV(hsv);
    this->setShaderOpacity(1.0f);
}

void HueSatSpriteNode::setShaderHSV(Vec3 hsv) {
    this->getGLProgramState()->setUniformVec3("vHSV", hsv);
}

void HueSatSpriteNode::setShaderOpacity(float opacity) {
    this->getGLProgramState()->setUniformFloat("vOpacity", opacity);
}

void HueSatSpriteNode::setOpacity(GLubyte opacity) {
    Node::setOpacity(opacity);
    this->setShaderOpacity(((float)opacity)/255.0f);
}