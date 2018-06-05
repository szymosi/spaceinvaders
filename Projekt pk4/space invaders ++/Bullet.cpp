#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet():Bullet(Vector2u(0,0))
{
}

Bullet::Bullet(Vector2u setposition):Bullet(setposition, Vector2i(0, -1000))
{
}

Bullet::Bullet(Vector2u setposition, int setspeed, float degree):Bullet(setposition,Vector2i((int)(cos(degree)*setspeed), (int)(sin(degree)*setspeed)))
{
}

Bullet::Bullet(Vector2u setposition, Vector2i setspeed) : Bullet(setposition, setspeed, 5)
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
	position.x +=(int)(frametime* (float)speed.x);
	position.y +=(int)(frametime* (float)speed.y);
}