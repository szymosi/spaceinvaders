#pragma once

#include "sprite.h"

class Bullet : public MySprite
{
private:
//	Vector2i position;
	Vector2i speed;
	int radius;

public:
	Bullet();
	Bullet(Vector2u position);
	Bullet(Vector2u setposition, Vector2i setspeed, int setradius);
	~Bullet();

	Vector2u getposition();

	void move();
	void move(float frametime);
};

