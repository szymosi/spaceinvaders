#pragma once
#include "Enemy.h"
class MediumEnemy:public Enemy
{
	float speed;
	float bulletspeed;
	Vector2u startpoint;
	Vector2u routesize; //size of rectangle that enemy moves around
	float timebetweenshoots = 1.0;

public:
	MediumEnemy();
	~MediumEnemy();

	void move(float frametime);
	void shoot();
};

