#pragma once
#include "Enemy.h"
class MediumEnemy:public Enemy
{
//	float speed;
	float bulletspeed;
//	Vector2u startpoint;
//	Vector2u routesize; //size of rectangle that enemy moves around
	float timebetweenshoots = 1.0;
	bool Xshootingpatern;//X if 1 + if 0

	float sin45deg = 0.70710678118;

public:
	MediumEnemy();
	MediumEnemy(Vector2u position);
	MediumEnemy(Vector2u position,float bulletspeed);
	MediumEnemy(Vector2u position,bool shootingpatern);
	MediumEnemy(Vector2u position, float bulletspeed, bool shootingpatern);
	~MediumEnemy();

	void move(float frametime);
	void shoot();
};

