#include "stdafx.h"
#include "player.h"



Player::Player():Player(Vector2f(640,360),100)
{
}

Player::Player(Vector2f setposition, int sethp)
{
	position = setposition;
	hp = sethp;
}


Player::~Player()
{
}

void Player::SetPosition(Vector2f newposition)
{
	position = newposition;
}

void Player::SetPosition(Vector2i newposition)
{
	position =(Vector2f)newposition;
}

void Player::SetHP(int newhp)
{
	hp = newhp;
}

sf::Vector2f Player::GetPosition()
{
	return position;
}

int Player::GetHP()
{
	return hp;
}

void Player::Shoot()
{
}

void Player::drawplayer(RenderWindow*window)
{
	MySprite::draw(window, position);
}
