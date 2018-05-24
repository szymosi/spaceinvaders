#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet():Bullet(Vector2u(0,0))
{
}

Bullet::Bullet(Vector2u position):Bullet(position, Vector2i(0, -10),5)
{
}

Bullet::Bullet(Vector2u setposition, Vector2i setspeed, int setradius) : MySprite("Bullet.png",setposition)
{
//	position = setposition;
	speed = setspeed;
	radius = setradius;
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