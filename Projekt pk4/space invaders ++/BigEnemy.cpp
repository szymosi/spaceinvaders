#include "stdafx.h"
#include "BigEnemy.h"
#include <iostream>
#include <math.h>


BigEnemy::BigEnemy(MySprite*target):BigEnemy(target,Vector2u(0,0))
{
}

BigEnemy::BigEnemy(MySprite * target, Vector2u position)
{
	this->target = target;
	this->position = position;
	this->bulletspeed = 200;
}


BigEnemy::~BigEnemy()
{
}

void BigEnemy::shoot()
{
	bullets.clear();
	if (Clock.getElapsedTime().asSeconds() > timebetweenshoots)
	{
		float degree = atan2((int)(target->GetPosition().y - this->position.y), (int)(target->GetPosition().x - this->position.x));//atan2(y,x);
		int speedx = cos(degree)*bulletspeed;
		int speedy = sin(degree)*bulletspeed;
		bullets.push_back(new Bullet(this->position, Vector2i(speedx,speedy)));
	}
}

