#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet(std::string bullettype, Vector2u position, float degree)
{
	int setspeed;
	int damage;
	if (bullettype == "SmallBullet")
	{
		setspeed = 200;
		damage = 50;
	}
	else
		if (bullettype == "MediumBullet")
		{
			setspeed = 150;
			damage = 100;
		}
		else
			if (bullettype == "BigBullet")
			{
				setspeed = 200;
				damage = 150;
			}
			else
			{
				bullettype == "Bullet";
				setspeed = 1000;
				damage = 50;
			}
	Bullet(bullettype, position, Vector2i((int)(cos(degree)*setspeed), (int)(sin(degree)*setspeed)), damage);
}

Bullet::Bullet(std::string bullettype, Vector2u setposition, Vector2i setspeed, int damage):MySprite(bullettype+".png",setposition)
{
	this->speed = setspeed;
	this->damage = damage;
}

Bullet::~Bullet()
{
}

Vector2u Bullet::getposition()
{
	return position;
}

void Bullet::move()
{
	position.x += speed.x;
	position.y += speed.y;
}
void Bullet::move(float frametime)
{
	position.x +=(int)(frametime* (float)speed.x);
	position.y +=(int)(frametime* (float)speed.y);
}