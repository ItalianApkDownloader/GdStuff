#include "../../../Cpp/GDAPI/cocos2d.h"


class advancedOptionsLayer : public CCLayerColor {
	public:




		void show();

		bool init();

		static advancedOptionsLayer* create();

		virtual void keyBackClicked();
		void close();
};