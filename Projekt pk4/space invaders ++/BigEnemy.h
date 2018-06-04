#pragma once
#include "Enemy.h"
class BigEnemy :public Enemy
{
private:
	MySprite*target;
public:
	BigEnemy(MySprite*target) :BigEnemy(target, Vector2u(0, 0)) {}
	BigEnemy(MySprite*target,Vector2u position) :BigEnemy(target, position, 0.5) {}
	BigEnemy(MySprite*target, Vector2u position,float timebetweenshoots) :BigEnemy(target, position, timebetweenshoots,200) {}
	BigEnemy(MySprite*target, Vector2u position, float timebetweenshoots, float bulletspeed);
	~BigEnemy();

	void shoot();
};

