#include "cocos2d.h"
#include "CCMenuItemSpriteCustom.h"

CCMenuItemSpriteCustom* CCMenuItemSpriteCustom::create(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target, cocos2d::SEL_MenuHandler selector)
{
	CCMenuItemSpriteCustom* btn = new CCMenuItemSpriteCustom();
	
	if (btn && btn->init(normalSprite, selectedSprite, target, selector))
		btn->autorelease();
	else
		CC_SAFE_DELETE(btn);
	

	return btn;
}

bool CCMenuItemSpriteCustom::init(CCNode* normalSprite, CCNode* selectedSprite, CCObject* target, cocos2d::SEL_MenuHandler selector)
{
	auto result = this->initWithNormalSprite(normalSprite, selectedSprite, 0, target, selector);
	this->originalSize = normalSprite->getScale();
	return result;
}

void CCMenuItemSpriteCustom::selected()
{
	
		this->stopAllActions();
		auto action = CCScaleTo::create(0.3, this->originalSize * 1.26);
		this->runAction(CCEaseBounceOut::create(action));
	
	
}


void CCMenuItemSpriteCustom::unselected()
{

		this->stopAllActions();
		auto action = CCScaleTo::create(0.4, this->originalSize * 1);
		this->runAction(CCEaseBounceOut::create(action));
	
}

void CCMenuItemSpriteCustom::activate()
{
	this->stopAllActions();
	auto action = CCScaleTo::create(0.4, this->originalSize * 1);
	this->runAction(CCEaseBounceOut::create(action));
	CCMenuItem::activate();
}

void CCMenuItemSpriteCustom::setScale(float value)
{
	this->originalSize = value;
	CCMenuItemSprite::setScale(value);
}
