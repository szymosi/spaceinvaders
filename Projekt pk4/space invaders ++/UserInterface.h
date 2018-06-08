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
	// Win screen
	MySprite*Win;
	MySprite*Lose;
public:
	UserInterface();
	UserInterface(std::string background, Vector2u background_pos, std::string HpBar, Vector2u HpBar_pos, std::string HpBackground, Vector2u HpBackground_pos,std::string Win, Vector2u Win_pos,std::string Lose, Vector2u Lose_pos);
	~UserInterface();
	
	MySprite*Getbackground();
	MySprite*GetHpBar();
	MySprite*GetHpBackground();
	MySprite*GetWinScreen();
	MySprite*GetLoseScreen();
};

