#pragma once

#include "sprite.h"

class Player : public MySprite
{
private:
	Vector2i position;
	int hp;
public:
	Player();
	Player(Vector2i position, int hp);
	~Player();
	void SetPosition(Vector2i position);
	void SetPosition(Vector2f newposition);
	void SetHP(int newhp);
	sf::Vector2i GetPosition();
	int GetHP();
	void Shoot();
	void drawplayer(RenderWindow*window);
};

