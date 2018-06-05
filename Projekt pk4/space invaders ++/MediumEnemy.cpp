#include "stdafx.h"
#include "MediumEnemy.h"





MediumEnemy::MediumEnemy(Vector2u position, int bulletspeed, float radius, int speed, float timebetweenshoots, bool shootingpatern)
{
	this->startpoint = position;
	this->bulletspeed = bulletspeed;
	this->radius = radius;
	this->speed = speed;
	this->Xshootingpatern = shootingpatern;
	this->timebetweenshoots = timebetweenshoots;
	this->position.x = (int)cos(degree*Pi / 180.0) + startpoint.x;
	this->position.y = (int)sin(degree*Pi / 180.0) + startpoint.y;
	this->SetGraphic("MediumEnemy.png");
	Clock.restart();
}

MediumEnemy::~MediumEnemy()
{
}

void MediumEnemy::move(float frametime)
{
	degree += (int)(frametime*speed);
	this->position.x = (int)(cos(degree*Pi / 180.0)*radius + startpoint.x);
	this->position.y = (int)(sin(degree*Pi / 180.0)*radius+startpoint.y);
}

void MediumEnemy::shoot()
{
	bullets.clear();
	if (Clock.getElapsedTime().asSeconds() > timebetweenshoots)
	{
		Clock.restart();
		if (Xshootingpatern)
		{
//			bullets.push_back(new Bullet(this->position, Vector2i(0.70710678118*bulletspeed, 0.70710678118*bulletspeed)));
//			bullets.push_back(new Bullet(this->position, Vector2i(-0.70710678118*bulletspeed, 0.70710678118*bulletspeed)));
//			bullets.push_back(new Bullet(this->position, Vector2i(0.70710678118*bulletspeed, -0.70710678118*bulletspeed)));
//			bullets.push_back(new Bullet(this->position, Vector2i(-0.70710678118*bulletspeed, -0.70710678118*bulletspeed)));
			bullets.push_back(new Bullet(this->position, bulletspeed, 0.25f*Pi));
			bullets.push_back(new Bullet(this->position, bulletspeed, 0.75f*Pi));
			bullets.push_back(new Bullet(this->position, bulletspeed, 1.25f*Pi));
			bullets.push_back(new Bullet(this->position, bulletspeed, 1.75f*Pi));
			Xshootingpatern = 0;
		}
		else
		{
		//	bullets.push_back(new Bullet(this->position, Vector2i(0,bulletspeed)));
		//	bullets.push_back(new Bullet(this->position, Vector2i(0,-bulletspeed)));
		//	bullets.push_back(new Bullet(this->position, Vector2i(bulletspeed,0)));
		//	bullets.push_back(new Bullet(this->position, Vector2i(-bulletspeed,0)));
			bullets.push_back(new Bullet(this->position, bulletspeed, 0));
			bullets.push_back(new Bullet(this->position, bulletspeed, 0.5f*Pi));
			bullets.push_back(new Bullet(this->position, bulletspeed, Pi));
			bullets.push_back(new Bullet(this->position, bulletspeed, 1.5f*Pi));
			Xshootingpatern = 1;
		}
	}
}
