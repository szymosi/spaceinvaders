#include "stdafx.h"
#include "SmallEnemy.h"


SmallEnemy::SmallEnemy():SmallEnemy(Vector2u(0,0))
{
}

SmallEnemy::SmallEnemy(Vector2u position) : SmallEnemy(position,200)
{
}

SmallEnemy::SmallEnemy(Vector2u position, unsigned int range): SmallEnemy(position, 200,0)
{
}

SmallEnemy::SmallEnemy(Vector2u position, unsigned int range, float speed): SmallEnemy(position, 100, 50, 0)
{
}

SmallEnemy::SmallEnemy(Vector2u position, unsigned int range, float speed, bool moveleft)
{
	this->moveleft = moveleft;
	this->position = position;
	this->startpoint = position;
	this->range = range;
	this->speed = speed;
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
		newposition = position.x - (frametime * speed);
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
		newposition = position.x + (frametime * speed);
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
		bullets.push_back(new Bullet(Vector2u(this->position.x, this->position.y + (GetSize().y / 2)),Vector2i(0,100)));
	//	bullets.push_back(new Bullet(Vector2u(position.x, position.y + (GetSize().y / 2)), Vector2i(0, 100)));
		Clock.restart();
	}
}
