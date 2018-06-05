#pragma once
#include "Enemy.h"
class SmallEnemy :public Enemy
{
private:
	bool moveleft;
	Vector2u startpoint;
	unsigned int range;

	float timebetweenshoots = 1.5f;

	const float sin30deg = 0.5f;
	const float cos30deg = 0.86602540378f;
	
public:
	SmallEnemy() :SmallEnemy(Vector2u(0, 0)) {}
	SmallEnemy(Vector2u position) : SmallEnemy(position, 200) {}
	SmallEnemy(Vector2u position, unsigned int range) : SmallEnemy(position, range, 150) {}
	SmallEnemy(Vector2u position, unsigned int range, int speed) : SmallEnemy(position, range, speed, 1.5) {}
	SmallEnemy(Vector2u position, unsigned int range, int speed, float timebetweenshoots) : SmallEnemy(position, range, speed, timebetweenshoots, 200) {}
	SmallEnemy(Vector2u position, unsigned int range, int speed,float timebetweenshoots, int bulletspeed) : SmallEnemy(position, range, speed, timebetweenshoots, bulletspeed,0) {}
	SmallEnemy(Vector2u position, unsigned int range, int speed,float timebetweenshoots, int bulletspeed,bool moveleft);
	~SmallEnemy();

	void move(float frametime);
	void shoot();
};