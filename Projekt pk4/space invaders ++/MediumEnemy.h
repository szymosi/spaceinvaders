#pragma once
#include "Enemy.h"
class MediumEnemy:public Enemy
{
	Vector2u startpoint;
	float radius; //radius of circle that enemy moves around
	int degree=0;	//etap of makeing of circle
	bool Xshootingpatern;//X if 1 + if 0

//	const float sin45deg = 0.70710678118;
	const float Pi = 3.14159265359f;

public:
	MediumEnemy() :MediumEnemy(Vector2u(640, 360)) {}
	MediumEnemy(Vector2u position) :MediumEnemy(position, 750,150) {}
	MediumEnemy(Vector2u position, int hp, int bulletdamage) :MediumEnemy(position, hp, bulletdamage, 150) {}
	MediumEnemy(Vector2u position, int hp, int bulletdamage, int bulletspeed) :MediumEnemy(position, hp, bulletdamage, bulletspeed,175) {}
	MediumEnemy(Vector2u position, int hp, int bulletdamage, int bulletspeed, float radius) :MediumEnemy(position, hp, bulletdamage, bulletspeed,radius,100) {}
	MediumEnemy(Vector2u position, int hp, int bulletdamage, int bulletspeed, float radius,int speed) :MediumEnemy(position, hp, bulletdamage, bulletspeed, radius, speed,1.5) {}
	MediumEnemy(Vector2u position, int hp, int bulletdamage, int bulletspeed, float radius,int speed, float timebetweenshoots) :MediumEnemy(position, hp, bulletdamage, bulletspeed, radius, speed,timebetweenshoots,0) {}
	MediumEnemy(Vector2u position, int hp, int bulletdamage, int bulletspeed, float radius,int speed, float timebetweenshoots, bool shootingpatern);
	~MediumEnemy();

	void move(float frametime);
	void shoot();
};

/*Enemy goes arround piont defined as starting point
shoots X and + patterns alternately using medium bullets*/