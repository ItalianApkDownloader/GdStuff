#include "include\advancedOptionsLayer.h"

void advancedOptionsLayer::show() {
	auto scene = CCDirector::sharedDirector()->getRunningScene();
	scene->addChild(this);
	auto fadeto = CCFadeTo::create(0.14,100);
	this->runAction(fadeto);
	

}




bool advancedOptionsLayer::init() {

	bool result = this->initWithColor(ccc4(0, 0, 0, 0));
	if (result) {
		auto dir = CCDirector::sharedDirector();
		dir->getTouchDispatcher()->incrementForcePrio(2);
		this->setTouchEnabled(true);
		this->setKeypadEnabled(true);
		this->setKeyboardEnabled(true);


		auto layer = CCLayer::create();
		layer->setContentSize(dir->getWinSize());
		this->addChild(layer);
		auto d = dir->getTouchDispatcher();
		d->addTargetedDelegate(this, -500, true);
	}
	return result;
}


void advancedOptionsLayer::keyBackClicked() {
	
	this->close();
}

void advancedOptionsLayer::close() {
	this->removeFromParentAndCleanup(true);

}


advancedOptionsLayer* advancedOptionsLayer::create() {
	auto v12 = new advancedOptionsLayer();
	if (v12) {
		if (v12->init()) {
			v12->autorelease();
		}
		else {
			CC_SAFE_DELETE(v12);
		}
	}
	return v12;


}
