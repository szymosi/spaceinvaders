#include "stdafx.h"
#include "SmallEnemy.h"


SmallEnemy::SmallEnemy():SmallEnemy(Vector2u(0,0))
{
}

SmallEnemy::SmallEnemy(Vector2u position) : SmallEnemy(position,200)
{
}

SmallEnemy::SmallEnemy(Vector2u position, unsigned int range): SmallEnemy(position, range,150)
{
}

SmallEnemy::SmallEnemy(Vector2u position, unsigned int range, float speed): SmallEnemy(position, range, speed, 0)
{
}

SmallEnemy::SmallEnemy(Vector2u position, unsigned int range, float speed, bool moveleft)
{
	this->position = position;
	this->moveleft = moveleft;
	this->startpoint = position;
	this->range = range;
	this->speed = speed;
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
	bullets.clear();
	if (Clock.getElapsedTime().asSeconds() > timebetweenshoots)
	{
		bullets.push_back(new Bullet(Vector2u(this->position.x, this->position.y + (GetSize().y / 2)),Vector2i(0,bulletspeed)));
		bullets.push_back(new Bullet(Vector2u(this->position.x, this->position.y + (GetSize().y / 2)), Vector2i(sin30deg*bulletspeed, cos30deg*bulletspeed)));
		bullets.push_back(new Bullet(Vector2u(this->position.x, this->position.y + (GetSize().y / 2)), Vector2i(-(sin30deg*bulletspeed), cos30deg*bulletspeed)));
		Clock.restart();
	}
}
