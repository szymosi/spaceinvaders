#pragma once

#include "sprite.h"

class Player : public MySprite
{
private:
	Vector2f position;
	int hp;
public:
	Player();
	Player(Vector2f position, int hp);
	~Player();
	void SetPosition(Vector2f position);
	void Player::SetPosition(Vector2i newposition);
	void SetHP(int newhp);
	sf::Vector2f GetPosition();
	int GetHP();
	void Shoot();
	void drawplayer(RenderWindow*window);
};

