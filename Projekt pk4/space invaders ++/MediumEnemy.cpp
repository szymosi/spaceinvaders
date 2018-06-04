#include "stdafx.h"
#include "MediumEnemy.h"


MediumEnemy::MediumEnemy():MediumEnemy(Vector2u(0, 0))
{
}

MediumEnemy::MediumEnemy(Vector2u position) : MediumEnemy(position,150,1)
{
}

MediumEnemy::MediumEnemy(Vector2u position, float bulletspeed):MediumEnemy(position,bulletspeed,1)
{
}

MediumEnemy::MediumEnemy(Vector2u position, bool shootingpatern):MediumEnemy(position,150,shootingpatern)
{
}

MediumEnemy::MediumEnemy(Vector2u position, float bulletspeed, bool shootingpatern)
{
	this->startpoint = position;
	this->bulletspeed = bulletspeed;
	this->Xshootingpatern = shootingpatern;
	this->position.x = cos(degree*Pi / 180.0)+startpoint.x;
	this->position.y = sin(degree*Pi / 180.0)+startpoint.y;
}


MediumEnemy::~MediumEnemy()
{
}

void MediumEnemy::move(float frametime)
{
	degree += frametime*speed;
	this->position.x = cos(degree*Pi / 180.0)*radius+startpoint.x;
	this->position.y = sin(degree*Pi / 180.0)*radius+startpoint.y;
}

void MediumEnemy::shoot()
{
	bullets.clear();
	if (Clock.getElapsedTime().asSeconds() > timebetweenshoots)
	{
		Clock.restart();
		if (Xshootingpatern)
		{
			bullets.push_back(new Bullet(this->position, Vector2i(0.70710678118*bulletspeed, 0.70710678118*bulletspeed)));
			bullets.push_back(new Bullet(this->position, Vector2i(-0.70710678118*bulletspeed, 0.70710678118*bulletspeed)));
			bullets.push_back(new Bullet(this->position, Vector2i(0.70710678118*bulletspeed, -0.70710678118*bulletspeed)));
			bullets.push_back(new Bullet(this->position, Vector2i(-0.70710678118*bulletspeed, -0.70710678118*bulletspeed)));
			Xshootingpatern = 0;
		}
		else
		{
			bullets.push_back(new Bullet(this->position, Vector2i(0,bulletspeed)));
			bullets.push_back(new Bullet(this->position, Vector2i(0,-bulletspeed)));
			bullets.push_back(new Bullet(this->position, Vector2i(bulletspeed,0)));
			bullets.push_back(new Bullet(this->position, Vector2i(-bulletspeed,0)));
			Xshootingpatern = 1;
		}
	}
}
