#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

Vector2u Enemy::getposition()
{
	return this->position;
}

int Enemy::gethp()
{
	return hp;
}
