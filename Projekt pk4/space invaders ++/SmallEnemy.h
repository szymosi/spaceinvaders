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

	float timebetweenshoots = 0.5;
	
public:
	SmallEnemy();
	SmallEnemy(Vector2u position);
	SmallEnemy(Vector2u position, unsigned int range);
	SmallEnemy(Vector2u position, unsigned int range,float speed);
	SmallEnemy(Vector2u position, unsigned int range, float speed,bool moveleft);
	~SmallEnemy();

	void move(float frametime);
	void shoot();
};

