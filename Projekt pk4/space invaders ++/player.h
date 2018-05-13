#pragma once

#include "sprite.h"
class player : public sprite
{
private:
	Vector2f position;
	int hp;
public:
	player();
	player(Vector2f position, int hp);
	~player();
	void SetPosition(Vector2f position);
	void SetHP(int newhp);
	sf::Vector2f GetPosition();
	int GetHP();
	void Shoot();
};

