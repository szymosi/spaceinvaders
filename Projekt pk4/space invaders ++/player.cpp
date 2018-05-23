#include "stdafx.h"
#include "player.h"



Player::Player():Player(Vector2i(640,360),100)
{
}

Player::Player(Vector2i setposition, int sethp)
{
	position = setposition;
	hp = sethp;
}


Player::~Player()
{
}

void Player::SetPosition(Vector2i newposition)
{
	position = newposition;
}

void Player::SetPosition(Vector2f newposition)
{
	position =(Vector2i)newposition;
}

void Player::SetHP(int newhp)
{
	hp = newhp;
}

sf::Vector2i Player::GetPosition()
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
