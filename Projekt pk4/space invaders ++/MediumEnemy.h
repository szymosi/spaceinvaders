#pragma once
#include "Enemy.h"
class MediumEnemy:public Enemy
{
	Vector2u startpoint;
	float radius=200.0; //radius of circle that enemy moves around
	int degree=0;	//etap of makeing of circle
	float speed=100;//speed in deg/sec
	float timebetweenshoots = 1.0;
	bool Xshootingpatern;//X if 1 + if 0

	const float sin45deg = 0.70710678118;
	const float Pi = 3.14159265359;

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

