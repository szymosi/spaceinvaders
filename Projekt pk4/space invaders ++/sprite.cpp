#include "stdafx.h"
#include "sprite.h"


sprite::sprite()
{
}


sprite::~sprite()
{
}

void sprite::SetTexture()
{
	texture.loadFromFile("image.png");
	size = texture.getSize();
}


void sprite::SetGraphic()
{
	SetTexture();
	graphic.setTexture(texture);
	graphic.setOrigin(Vector2f(size.x / 2, size.y / 2));
}

bool sprite::CheckIfOnScreen(Vector2i WindowSize,Vector2f position)
{
	if (position.x >= 0 && position.y > 0)
		if (position.x < WindowSize.x && position.y < WindowSize.y)
			return true;
	return false;
}

void sprite::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(graphic, states);
}
