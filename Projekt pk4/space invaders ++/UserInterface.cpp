#include "stdafx.h"
#include "UserInterface.h"


UserInterface::UserInterface()
{
	this->background=new MySprite("Background.png",Vector2u(640,360));
	this->HpBackground = new MySprite("HpBackground.png", Vector2u(150, 43));
	this->HpBar = new MySprite("HpBar.png", HpBackground->GetPosition());
	this->Win = new MySprite("you win.png", Vector2u(640, 360));
	this->Lose = new MySprite("game over.png", Vector2u(640, 360));
}

UserInterface::UserInterface(std::string background, Vector2u background_pos, std::string HpBar, Vector2u HpBar_pos, std::string HpBackground, Vector2u HpBackground_pos, std::string Win, Vector2u Win_pos, std::string Lose, Vector2u Lose_pos)
{
	this->background = new MySprite(background, background_pos);
	this->HpBackground = new MySprite(HpBackground, HpBackground_pos);
	this->HpBar = new MySprite(HpBar, HpBar_pos);
	this->Win = new MySprite(Win, Win_pos);
	this->Lose = new MySprite(Lose, Lose_pos);
}


UserInterface::~UserInterface()
{
	delete this->background;
	delete this->HpBackground;
	delete this->HpBar;
	delete this->Win;
	delete this->Lose;
}

MySprite * UserInterface::Getbackground()
{
	return background;
}

MySprite * UserInterface::GetHpBar()
{
	return HpBar;
}

MySprite * UserInterface::GetHpBackground()
{
	return HpBackground;
}

MySprite * UserInterface::GetWinScreen()
{
	return this->Win;
}

MySprite * UserInterface::GetLoseScreen()
{
	return this->Lose;
}
