#include "stdafx.h"
#include "SmallEnemy.h"


SmallEnemy::SmallEnemy(Vector2u position, unsigned int range, int speed, float timebetweenshoots, int bulletspeed, bool moveleft)
{
	this->position = position;
	this->moveleft = moveleft;
	this->range = range;
	this->speed = speed;
	this->bulletspeed = bulletspeed;
	this->startpoint = position;
	this->timebetweenshoots = timebetweenshoots;
	this->SetGraphic("SmallEnemy.png");
	Clock.restart();
}

SmallEnemy::~SmallEnemy()
{
}

void SmallEnemy::move(float frametime)
{
	unsigned int newposition;
	if (moveleft)
	{
		newposition = position.x - (int)(frametime * speed);
		if (newposition > startpoint.x - range)
		{
			position.x = newposition;
		}
		else
		{
			newposition = startpoint.x - range;
			moveleft = 0;
		}
	}
	else 
	{
		newposition = position.x + (int)(frametime * speed);
		if (newposition < startpoint.x + range)
		{
			position.x = newposition;
		}
		else
		{
			newposition = startpoint.x + range;
			moveleft = 1;
		}
	}
}

void SmallEnemy::shoot()
{
	if (Clock.getElapsedTime().asSeconds() > timebetweenshoots)
	{
		Clock.restart();
		bullets.push_back(new Bullet("SmallBullet",Vector2u(this->position.x, this->position.y + (GetSize().y / 2)),0));
		bullets.push_back(new Bullet("SmallBullet",Vector2u(this->position.x, this->position.y + (GetSize().y / 2)), 30));
		bullets.push_back(new Bullet("SmallBullet",Vector2u(this->position.x, this->position.y + (GetSize().y / 2)), -30));
	}
}
