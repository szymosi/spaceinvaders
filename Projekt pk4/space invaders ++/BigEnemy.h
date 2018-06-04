#pragma once
#include "Enemy.h"
class BigEnemy :public Enemy
{
private:
	float timebetweenshoots = 1.0;
	MySprite*target;
public:
	BigEnemy(MySprite*target);
	BigEnemy(MySprite*target,Vector2u position);
	~BigEnemy();

	void shoot();
};

