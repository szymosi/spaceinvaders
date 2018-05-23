#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet():Bullet(Vector2i(0,0))
{
}

Bullet::Bullet(Vector2i position):Bullet(position, Vector2i(0, -10),5)
{
}

Bullet::Bullet(Vector2i setposition, Vector2i setspeed, int setradius) : MySprite("Bullet.png")
{
	position = setposition;
	speed = setspeed;
	radius = setradius;
}


Bullet::~Bullet()
{
}

Vector2i Bullet::getposition()
{
	return position;
}

void Bullet::move()
{
	position += speed;
}