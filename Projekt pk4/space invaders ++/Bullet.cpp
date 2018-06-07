#include "stdafx.h"
#include "Bullet.h"


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

int Bullet::getdmg()
{
	return this->damage;
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