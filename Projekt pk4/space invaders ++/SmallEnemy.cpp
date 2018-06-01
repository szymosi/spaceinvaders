#include "stdafx.h"
#include "SmallEnemy.h"


SmallEnemy::SmallEnemy():SmallEnemy(Vector2u(0,0))
{
}

SmallEnemy::SmallEnemy(Vector2u position) : SmallEnemy(position,0)
{
}

SmallEnemy::SmallEnemy(Vector2u position,bool moveleft)
{
	this->moveleft = moveleft;
	this->position = position;
}


SmallEnemy::~SmallEnemy()
{
}

void SmallEnemy::move()
{
	this->position.x = position.x + 1;
}

void SmallEnemy::shoot()
{
}
