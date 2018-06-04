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
	this->bulletspeed = 150;
}


BigEnemy::~BigEnemy()
{
}

void BigEnemy::shoot()
{
	bullets.clear();
	if (Clock.getElapsedTime().asSeconds() > timebetweenshoots)
	{
		float degree = atan2f((double)(target->GetPosition().y - this->position.y), (double)(target->GetPosition().x - this->position.x));
		std::cout << degree*180/3.1415 << std::endl;
		bullets.push_back(new Bullet(this->position, Vector2i(cos(degree)*bulletspeed, sin(degree)*bulletspeed)));
	}
}

