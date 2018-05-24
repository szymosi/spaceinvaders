#include "stdafx.h"
#include "player.h"



Player::Player():Player(Vector2u(640,360),100)
{
}

//Player::Player(Vector2i setposition, int sethp):MySprite("Player.png")
//{
//	position = setposition;
//	hp = sethp;
//}

Player::Player(Vector2u setposition, int sethp) :MySprite("Player.png",setposition)
{
	hp = sethp;
}

Player::~Player()
{
}

void Player::SetPosition(Vector2u newposition)
{
	position = newposition;
}

void Player::SetPosition(Vector2i newposition)
{
	position =(Vector2u)newposition;
}

void Player::SetHP(int newhp)
{
	hp = newhp;
}

sf::Vector2u Player::GetPosition()
{
	return position;
}

int Player::GetHP()
{
	return hp;
}

Bullet* Player::Shoot()
{
	Bullet*bullet = new Bullet(Vector2u(position.x, position.y - (GetSize().y / 2)));
	return bullet;
}

/*void Player::drawplayer(RenderWindow*window)
{
	MySprite::draw(window, position);
}*/
