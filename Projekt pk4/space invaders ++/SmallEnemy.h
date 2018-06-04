#pragma once
#include "Enemy.h"
class SmallEnemy :public Enemy
{
private:
	bool moveleft;
	Vector2u startpoint;
	unsigned int range;

	float timebetweenshoots = 1.5;

	const float sin30deg = 0.5;
	const float cos30deg = 0.86602540378;
	
public:
	SmallEnemy() :SmallEnemy(Vector2u(0, 0)) {}
	SmallEnemy(Vector2u position) : SmallEnemy(position, 200) {}
	SmallEnemy(Vector2u position, unsigned int range) : SmallEnemy(position, range, 150) {}
	SmallEnemy(Vector2u position, unsigned int range, float speed) : SmallEnemy(position, range, speed, 1.5) {}
	SmallEnemy(Vector2u position, unsigned int range, float speed, float timebetweenshoots) : SmallEnemy(position, range, speed, timebetweenshoots, 200) {}
	SmallEnemy(Vector2u position, unsigned int range, float speed,float timebetweenshoots, float bulletspeed) : SmallEnemy(position, range, speed, timebetweenshoots, bulletspeed,0) {}
	SmallEnemy(Vector2u position, unsigned int range, float speed,float timebetweenshoots, float bulletspeed,bool moveleft);
	~SmallEnemy();

	void move(float frametime);
	void shoot();
};