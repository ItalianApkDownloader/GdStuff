#pragma once
#include "cocos2d.h"


class CCMenuItemSpriteCustomVars {
public:
	float originalSize = 0;
};


class CCMenuItemSpriteCustom : public CCMenuItemSprite , CCMenuItemSpriteCustomVars {
public:
	static CCMenuItemSpriteCustom* create(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target, cocos2d::SEL_MenuHandler selector);
	bool init(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target, cocos2d::SEL_MenuHandler selector);
	void selected();
	void unselected();
	void activate();
	void setScale(float);
};

