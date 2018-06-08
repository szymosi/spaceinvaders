#include "stdafx.h"
#include "UserInterface.h"


UserInterface::UserInterface()
{
	this->background=new MySprite("Background.png",Vector2u(640,360));
	this->HpBackground = new MySprite("HpBackground.png", Vector2u(150, 43));
	this->HpBar = new MySprite("HpBar.png", HpBackground->GetPosition());
}

UserInterface::UserInterface(std::string background, Vector2u background_pos, std::string HpBar, Vector2u HpBar_pos, std::string HpBackground, Vector2u HpBackground_pos)
{
	this->background = new MySprite(background, background_pos);
	this->HpBackground = new MySprite(HpBackground, HpBackground_pos);
	this->HpBar = new MySprite(HpBar, HpBar_pos);
}


UserInterface::~UserInterface()
{
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
