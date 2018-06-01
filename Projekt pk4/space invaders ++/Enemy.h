#pragma once
#include "sprite.h"
class Enemy :public MySprite
{
private:
	int hp;
protected:
	Clock Clock;
public:
	Enemy();
	~Enemy();
	Vector2u getposition();
	int gethp();

	virtual void move() {};
	virtual void shoot() {};
};

