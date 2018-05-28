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

void Player::SetPosition(Vector2i newposition,Vector2u windowsize)
{
	if (newposition.x < 0)
		newposition.x = 0;
	if (newposition.y < 0)
		newposition.y = 0;
	if (newposition.x >= windowsize.x)
		newposition.x = windowsize.x-1;
	if (newposition.y >= windowsize.y)
		newposition.y = windowsize.y-1;

	position =(Vector2u)newposition;

	std::cout << position.x << "/t" << position.y << std::endl;
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
