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
	// Win/Lose/Pause screen
	MySprite*Win;
	MySprite*Lose;
	MySprite*Pause;
	//Menu buttons
	MySprite*Resume;
	MySprite*Restart;
	MySprite*Quit;
public:
	UserInterface();
	UserInterface(std::string background, Vector2u background_pos, std::string HpBar, Vector2u HpBar_pos, std::string HpBackground, Vector2u HpBackground_pos,std::string Win, Vector2u Win_pos,std::string Lose, Vector2u Lose_pos,std::string Pause,Vector2u Pause_pos, std::string Resume, Vector2u Resume_pos, std::string Restart, Vector2u Restart_pos, std::string Quit, Vector2u Quit_pos);
	~UserInterface();
	
	MySprite*Getbackground();
	MySprite*GetHpBar();
	MySprite*GetHpBackground();
	MySprite*GetWinScreen();
	MySprite*GetLoseScreen();
	MySprite*GetPauseScreen();
	MySprite*GetResumeButton();
	MySprite*GetRestartButton();
	MySprite*GetQuitButton();

	void ScaleHpBar(float scale);

};

