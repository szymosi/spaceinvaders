#include "stdafx.h"
#include "BigEnemy.h"
#include <math.h>


BigEnemy::BigEnemy(MySprite*target, Vector2u position, int hp, int bulletdamage, float timebetweenshoots, int bulletspeed)
{
	this->target = target;
	this->position = position;
	this->hp = hp;
	this->bulletdamage = bulletdamage;
	this->timebetweenshoots = timebetweenshoots;
	this->bulletspeed = bulletspeed;
	this->speed = 0;
	this->SetGraphic("BigEnemy.png");
	Clock.restart();
}

BigEnemy::~BigEnemy()
{
}

void BigEnemy::shoot()
{
	if (this->Clock.getElapsedTime().asSeconds() > timebetweenshoots)
	{
		Clock.restart();
		double degree = atan2((int)(target->GetPosition().y - this->position.y), (int)(target->GetPosition().x - this->position.x));//atan2(y,x);
		int speedx = (int)(cos(degree)*bulletspeed);
		int speedy = (int)(sin(degree)*bulletspeed);
		bullets.push_back(new Bullet("BigBullet",this->position, Vector2i(speedx,speedy),200));
	}
}

