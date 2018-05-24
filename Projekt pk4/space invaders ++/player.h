#pragma once

#include "sprite.h"
#include "Bullet.h"

class Player : public MySprite
{
private:
//	Vector2i position;
	int hp;
public:
	Player();
	Player(Vector2u position, int hp);
	~Player();
	void SetPosition(Vector2u position);
	void SetPosition(Vector2i newposition);
	void SetHP(int newhp);
	sf::Vector2u GetPosition();
	int GetHP();
	Bullet* Shoot();
//	void drawplayer(RenderWindow*window);
};

