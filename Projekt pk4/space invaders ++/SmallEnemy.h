#pragma once
#include "Enemy.h"
#include "Bullet.h"
class SmallEnemy :public Enemy
{
private:
	bool moveleft;
	float speed;
	Vector2u startpoint;
	unsigned int range;
	float bulletspeed=150;

	float timebetweenshoots = 1.0;

	float sin30deg = 0.5;
	float cos30deg = 0.86602540378;
	
public:
	SmallEnemy();
	SmallEnemy(Vector2u position);
	SmallEnemy(Vector2u position, unsigned int range);
	SmallEnemy(Vector2u position, unsigned int range,float speed);
	SmallEnemy(Vector2u position, unsigned int range, float speed,float bulletspeed);
	SmallEnemy(Vector2u position, unsigned int range, float speed, float bulletspeed,bool moveleft);
	~SmallEnemy();

	void move(float frametime);
	void shoot();
};

