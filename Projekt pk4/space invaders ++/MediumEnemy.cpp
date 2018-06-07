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
	if (Clock.getElapsedTime().asSeconds() > timebetweenshoots)
	{
		Clock.restart();
		if (Xshootingpatern)
		{
			bullets.push_back(new Bullet("MediumBullet",this->position, Vector2i((int)(0.70710678118*(double)bulletspeed), (int)(0.70710678118*(double)bulletspeed)),150));
			bullets.push_back(new Bullet("MediumBullet",this->position, Vector2i((int)(-0.70710678118*(double)bulletspeed),(int)( 0.70710678118*(double)bulletspeed)),150));
			bullets.push_back(new Bullet("MediumBullet",this->position, Vector2i((int)(0.70710678118*(double)bulletspeed), (int)(-0.70710678118*(double)bulletspeed)),150));
			bullets.push_back(new Bullet("MediumBullet",this->position, Vector2i((int)(-0.70710678118*(double)bulletspeed),(int)( -0.70710678118*(double)bulletspeed)),150));

			Xshootingpatern = 0;
		}
		else
		{
			bullets.push_back(new Bullet("MediumBullet",this->position, Vector2i(0,bulletspeed),150));
			bullets.push_back(new Bullet("MediumBullet",this->position, Vector2i(0,-bulletspeed),150));
			bullets.push_back(new Bullet("MediumBullet",this->position, Vector2i(bulletspeed,0),150));
			bullets.push_back(new Bullet("MediumBullet",this->position, Vector2i(-bulletspeed,0),150));

			Xshootingpatern = 1;
		}
	}
}
