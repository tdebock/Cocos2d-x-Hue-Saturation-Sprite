# Cocos2d-x-Hue-Saturation-Sprite

## A simple C++ Cocos2d-x Sprite subclass using a custom shader to allow for full HSV control while maintaining node opacity even with premultiplied alpha.

---

Example usage:
```
#include "HueSatSpriteNode.hpp"

...

HueSatSpriteNode *sprite = HueSatSpriteNode::create("spriteFile.png", Vec3(180.0f, 1.0f, 1.0f));
this->addChild(sprite);
sprite->setOpacity(200);

HueSatSpriteNode *spriteFrame = HueSatSpriteNode::createWithSpriteFrameName("spriteFrame.png", Vec3(180.0f, 1.0f, 1.0f));
this->addChild(spriteFrame);
```



To modify the HSV values at anytime, use the public function 

```
void setShaderHSV(Vec3 hsv);
```

---

vHSV uniform in the shader is used in the following scale:
```
H: 0 to 360 (modulo)
S: 0 to 1 (can over saturate with values > 1.0)
V: 0 to 1 (clamped)
```
Use a cocos2d Vec3 as input for the class' HSV control.

```
If using hue from Adobe Photoshop, or any other image editing software that uses hue scale of -180 to 180, negative values will need to be corrected.

Ex: hue of -170 = (360 - 170) = 190
Ex: hue of 180 = 180
Ex: hue of 90 = 90
Ex: hue of -10 = (360 - 10) = 350
```
