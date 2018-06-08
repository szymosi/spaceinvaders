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
	void SetPosition(Vector2i newposition,Vector2u windowsize);
	void SetHP(int newhp);
	sf::Vector2u GetPosition();
	int GetHP();
	void changeHP(int diffrence);
	Bullet* Shoot();
	bool isAlive();
};

