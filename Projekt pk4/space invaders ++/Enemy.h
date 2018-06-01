#pragma once
#include "sprite.h"
#include "vector"
#include "Bullet.h"
class Enemy :public MySprite
{
private:
	int hp;
protected:
	Clock Clock;
	std::vector<Bullet*> bullets;
public:
	Enemy();
	~Enemy();
	Vector2u getposition();
	int gethp();
	const std::vector<Bullet*> & getbullets();

	virtual void move(float frametime) {};
	virtual void shoot() {};
};

