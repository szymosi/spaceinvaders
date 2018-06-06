#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	for (auto i = 0; i < this->bullets.size(); i++)
		delete bullets[i];
	bullets.clear();
}

Vector2u Enemy::getposition()
{
	return this->position;
}

int Enemy::gethp()
{
	return hp;
}

void Enemy::sethp(int hp)
{
	this->hp = hp;
}

const std::vector<Bullet*> & Enemy::getbullets()
{
	return bullets;
}

bool Enemy::isAlive()
{
	if (this->hp <= 0)
		return false;
	else
		return true;
}
