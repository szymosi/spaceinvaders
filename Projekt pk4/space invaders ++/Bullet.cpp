#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet():Bullet(Vector2u(0,0))
{
}

Bullet::Bullet(Vector2u position):Bullet(position, Vector2i(0, -1000))
{
}

Bullet::Bullet(Vector2u setposition, Vector2i setspeed) : Bullet(position, setspeed, 5)
{
}

Bullet::Bullet(Vector2u setposition, Vector2i setspeed, int setradius) : MySprite("Bullet.png",setposition)
{
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
void Bullet::move(float frametime)
{
	position.x +=frametime* (float)speed.x;
	position.y +=frametime* (float)speed.y;
}