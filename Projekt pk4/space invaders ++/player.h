#pragma once

#include "sprite.h"
#include "Bullet.h"

class Player : public MySprite
{
private:
//	Vector2i position;
	int hp;
	Clock Clock;
	float timebetweenbullets = 0.2f;
public:
	Player();
	Player(Vector2u position, int hp);
	~Player();
	void SetPosition(Vector2i newposition,Vector2u windowsize);//changes players position to new position and not litting it outside window
	void SetHP(int newhp);//changes players hp to newhp
	sf::Vector2u GetPosition();//returns players position
	int GetHP();//returns players hp
	void changeHP(int diffrence);//adds diffrence to players hp
	Bullet* Shoot();//makes player shoot if possible
	bool isAlive();//returns true if players hp is more than 0
};

