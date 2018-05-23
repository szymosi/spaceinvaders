#include "stdafx.h"
#include "sprite.h"


MySprite::MySprite()
{
	SetGraphic();
}


MySprite::~MySprite()
{
}

void MySprite::SetTexture()
{
	texture.loadFromFile("Image.png");
	size = texture.getSize();
}


void MySprite::SetGraphic()
{
	SetTexture();
	graphic.setTexture(texture);
	graphic.setOrigin(Vector2f(size.x / 2, size.y / 2));
}

bool MySprite::CheckIfOnScreen(Vector2i WindowSize,Vector2f position)
{
	if (position.x >= 0 && position.y > 0)
		if (position.x < WindowSize.x && position.y < WindowSize.y)
			return true;
	return false;
}

void MySprite::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(graphic, states);
}

void MySprite::draw(RenderWindow*window, Vector2f position)
{
	graphic.setPosition(position);
	window->draw(graphic);
}
