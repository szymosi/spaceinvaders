#pragma once
#include "sprite.h"
#include "vector"
#include "Bullet.h"
class Enemy :public MySprite
{
private:
	int hp;
protected:
	int bulletspeed;
	int	bulletdmg;
	Clock Clock;
	std::vector<Bullet*> bullets;
	float timebetweenshoots;
	int speed;
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

