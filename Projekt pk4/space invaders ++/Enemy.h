#pragma once
#include "sprite.h"
#include "vector"
#include "Bullet.h"
class Enemy :public MySprite
{
protected:
	int hp;
	int speed;
	int bulletspeed;
	int	bulletdamage;
	Clock Clock;
	std::vector<Bullet*> bullets;
	float timebetweenshoots;
public:
	Enemy();
	~Enemy();
	Vector2u getposition();
	int gethp();
	void sethp(int hp);
	void chengehp(int diffrence);
	const std::vector<Bullet*> & getbullets();
	bool isAlive();
	void removebullet(int i);

	virtual void move(float frametime) {};
	virtual void shoot() {};
};

