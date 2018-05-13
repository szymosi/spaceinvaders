#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}

void player::SetPosition(Vector2f newposition)
{
	position = newposition;
}

void player::SetHP(int newhp)
{
	hp = newhp;
}

sf::Vector2f player::GetPosition()
{
	return position;
}

int player::GetHP()
{
	return hp;
}

void player::Shoot()
{
}
