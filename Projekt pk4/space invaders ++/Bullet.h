#pragma once

#include "sprite.h"

class Bullet : public MySprite
{
private:
	Vector2i position;
	Vector2i speed;
	int radius;

public:
	Bullet();
	Bullet(Vector2i position);
	Bullet(Vector2i setposition, Vector2i setspeed, int setradius);
	~Bullet();

	Vector2i getposition();

	void move();
};

