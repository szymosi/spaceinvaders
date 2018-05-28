#include "stdafx.h"
#include "sprite.h"


MySprite::MySprite()
{
	SetGraphic("image.png");
}

MySprite::MySprite(std::string filename):MySprite(filename,Vector2u(0,0))
{
}

MySprite::MySprite(std::string filename, Vector2u position)
{
	this->position = position;
	SetGraphic(filename);
}


MySprite::~MySprite()
{
}

Vector2u MySprite::GetSize()
{
	return size;
}

void MySprite::SetTexture(std::string filename)
{
	texture.loadFromFile(filename);
	size = texture.getSize();
}


void MySprite::SetGraphic(std::string filename)
{
	SetTexture(filename);
	graphic.setTexture(texture);
	graphic.setOrigin(Vector2f(size.x / 2, size.y / 2));
}

bool MySprite::CheckIfOnScreen(Vector2u WindowSize,Vector2u position)
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

void MySprite::draw(RenderWindow*window, Vector2u position)
{
	graphic.setPosition((Vector2f)position);
	window->draw(graphic);
}
