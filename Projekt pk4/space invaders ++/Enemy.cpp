#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	for (auto i = 0; i < this->bullets.size(); i++)
		delete bullets[i];
}

Vector2u Enemy::getposition()
{
	return this->position;
}

int Enemy::gethp()
{
	return hp;
}

const std::vector<Bullet*> & Enemy::getbullets()
{
	return bullets;
}
