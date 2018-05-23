#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet():Bullet(Vector2i(0,0))
{
}

Bullet::Bullet(Vector2i position):Bullet(position, Vector2i(1, 1),5)
{
}

Bullet::Bullet(Vector2i setposition, Vector2i setspeed, int setradius)
{
	position = setposition;
	speed = setspeed;
	radius = setradius;
}


Bullet::~Bullet()
{
}

void Bullet::move()
{
	position += speed;
}


void Bullet::draw(RenderWindow*window)
{
	MySprite::draw(window, position);
}