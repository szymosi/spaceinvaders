#include "stdafx.h"
#include "SmallEnemy.h"


SmallEnemy::SmallEnemy(Vector2u position, int hp, int bulletdamage, unsigned int range, int speed, float timebetweenshoots, int bulletspeed, bool moveleft)
{
	this->position = position;
	this->startpoint = position;
	this->hp = hp;
	this->bulletdamage = bulletdamage;
	this->range = range;
	this->speed = speed;
	this->timebetweenshoots = timebetweenshoots;
	this->bulletspeed = bulletspeed;
	this->moveleft = moveleft;
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
		bullets.push_back(new Bullet("SmallBullet",Vector2u(this->position.x, this->position.y + (GetSize().y / 2)),Vector2i(0, bulletspeed),100));
		bullets.push_back(new Bullet("SmallBullet",Vector2u(this->position.x, this->position.y + (GetSize().y / 2)), Vector2i((int)(bulletspeed*sin30deg),(int)(bulletspeed*cos30deg)),100));
		bullets.push_back(new Bullet("SmallBullet",Vector2u(this->position.x, this->position.y + (GetSize().y / 2)), Vector2i((int)(bulletspeed*-sin30deg), (int)(bulletspeed*cos30deg)), 100));
	}
}
