#pragma once
#include "sprite.h"
#include "vector"
#include "Bullet.h"
class Enemy :public MySprite
{
protected:
	int hp;
	int speed;
	int bulletspeed;//speed of bullet independent of degree
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
	void chengehp(int diffrence);//adds the diffrence to hp
	const std::vector<Bullet*> & getbullets(); //returns vector of bullets not allewing changes
	bool isAlive(); //returns true if enemy is alive, false if anemy is dead
	void removebullet(int i); //removes bullet at given possition

	virtual void move(float frametime) {};//chenges enemys possition according to time from last movement
	virtual void shoot() {};//enemy shoots if timebetweenshoots passed since last shoot
};

