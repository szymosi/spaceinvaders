#pragma once

#include "sprite.h"
#include <math.h>

class Bullet : public MySprite
{
private:
//	Vector2i position;
	Vector2i speed;
	int damage;
	

public:
	Bullet() :Bullet(Vector2u(0, 0)) {}
	Bullet(Vector2u position) :Bullet(position, 1000, 10) {}
	Bullet(Vector2u setposition, int setspeed, int damage) :Bullet(setposition, setspeed, -90.0*3.1415/180.0, damage) {}
	Bullet(Vector2u setposition, int setspeed, float degree, int damage) :Bullet(setposition, Vector2i((int)(cos(degree)*setspeed), (int)(sin(degree)*setspeed)), damage) {}
//	Bullet(std::string bullettype, Vector2u position, float degree);
	Bullet(Vector2u setposition, Vector2i setspeed, int damage) :Bullet("Bullet", setposition, setspeed, damage) {}
	Bullet(std::string bullettype, Vector2u setposition, Vector2i setspeed, int damage);
	~Bullet();

	Vector2u getposition();
	int getdmg();

	void move();
	void move(float frametime);
};

