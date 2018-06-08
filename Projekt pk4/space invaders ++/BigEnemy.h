#pragma once
#include "Enemy.h"
class BigEnemy :public Enemy
{
private:
	MySprite*target;
public:
	BigEnemy(MySprite*target) :BigEnemy(target, Vector2u(0, 0)) {}
	BigEnemy(MySprite*target,Vector2u position) :BigEnemy(target, position, 1500, 200) {}
	BigEnemy(MySprite*target, Vector2u position, int hp, int bulletdamage) :BigEnemy(target, position, hp, bulletdamage, 0.5) {}
	BigEnemy(MySprite*target, Vector2u position, int hp, int bulletdamage, float timebetweenshoots) :BigEnemy(target, position, hp, bulletdamage, timebetweenshoots,200) {}
	BigEnemy(MySprite*target, Vector2u position, int hp, int bulletdamage, float timebetweenshoots, int bulletspeed);
	~BigEnemy();

	void shoot();
};

/*Enemy does not move
Shoots in targets (usually players) direction using big bullets*/