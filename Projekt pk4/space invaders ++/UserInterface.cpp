#include "stdafx.h"
#include "UserInterface.h"


UserInterface::UserInterface()
{
	this->background=new MySprite("Background.png",Vector2u(640,360));
	this->HpBackground = new MySprite("HpBackground.png", Vector2u(150, 43));
	this->HpBar = new MySprite("HpBar.png", Vector2u(40, 20));
	HpBar->GetGraphic()->setOrigin(0, 0);
	this->Win = new MySprite("you win.png", Vector2u(640, 360));
	this->Lose = new MySprite("game over.png", Vector2u(640, 360));
	this->Pause= new MySprite("pause.png", Vector2u(640, 360));
	this->Resume = new MySprite("resume.png", Vector2u(640, 450));
	this->Restart = new MySprite("restart.png", Vector2u(640, 550));
	this->Quit = new MySprite("quit.png", Vector2u(640, 650));
}

UserInterface::UserInterface(std::string background, Vector2u background_pos, std::string HpBar, Vector2u HpBar_pos, std::string HpBackground, Vector2u HpBackground_pos, std::string Win, Vector2u Win_pos, std::string Lose, Vector2u Lose_pos, std::string Pause, Vector2u Pause_pos, std::string Resume, Vector2u Resume_pos, std::string Restart, Vector2u Restart_pos, std::string Quit, Vector2u Quit_pos)
{
	this->background = new MySprite(background, background_pos);
	this->HpBackground = new MySprite(HpBackground, HpBackground_pos);
	this->HpBar = new MySprite(HpBar, HpBar_pos);
	this->HpBar->GetGraphic()->setOrigin(0, 0);
	this->Win = new MySprite(Win, Win_pos);
	this->Lose = new MySprite(Lose, Lose_pos);
	this->Pause = new MySprite(Pause, Pause_pos);
	this->Resume= new MySprite(Resume, Resume_pos);
	this->Restart = new MySprite(Restart, Restart_pos);
	this->Quit = new MySprite(Quit, Quit_pos);
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

MySprite * UserInterface::GetPauseScreen()
{
	return this->Pause;
}

MySprite * UserInterface::GetResumeButton()
{
	return this->Resume;
}

MySprite * UserInterface::GetRestartButton()
{
	return this->Restart;
}

MySprite * UserInterface::GetQuitButton()
{
	return this->Quit;
}

void UserInterface::ScaleHpBar(float scale)
{
	HpBar->GetGraphic()->setScale(scale, 1);
}

