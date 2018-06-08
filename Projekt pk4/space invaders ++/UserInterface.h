#pragma once

#include "sprite.h"
class UserInterface
{
private:
	//Background
	MySprite*background;
	//HP bar
	MySprite*HpBar;
	MySprite*HpBackground;
public:
	UserInterface();
	UserInterface(std::string background, Vector2u background_pos, std::string HpBar, Vector2u HpBar_pos, std::string HpBackground, Vector2u HpBackground_pos);
	~UserInterface();
	
	MySprite*Getbackground();
	MySprite*GetHpBar();
	MySprite*GetHpBackground();
};

