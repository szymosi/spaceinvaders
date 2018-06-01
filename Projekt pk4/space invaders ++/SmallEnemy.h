#pragma once
#include "Enemy.h"
#include "Bullet.h"
class SmallEnemy :public Enemy
{
private:
	bool moveleft;
	float timebetweenshoots=0.5;
public:
	SmallEnemy();
	SmallEnemy(Vector2u position);
	SmallEnemy(Vector2u position,bool moveleft);
	~SmallEnemy();

	void move();
	void shoot();
};

