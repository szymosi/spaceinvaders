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
	texture.loadFromFile(filename);
	size = texture.getSize();
	graphic.setTexture(texture);
	graphic.setOrigin(Vector2f((float)size.x / 2, (float)size.y / 2));
	graphic.setTextureRect(IntRect(0,0,size.x,size.y));
}

Vector2u MySprite::GetPosition()
{
	return this->position;
}

bool MySprite::CheckIfOnScreen(Vector2u WindowSize,Vector2u position)
{
	if (position.x >= 0 && position.y > 0)
		if (position.x < WindowSize.x && position.y < WindowSize.y)
			return true;
	return false;
}

void MySprite::draw(RenderWindow*window, Vector2u position)
{
	graphic.setPosition((Vector2f)position);
	window->draw(graphic);
}

void MySprite::draw(RenderWindow * window)
{
	graphic.setPosition((Vector2f)position);
	window->draw(graphic);
}

bool MySprite::colides(MySprite * target)
{
	if (this->isRectangle == 1 && target->isRectangle == 1)
		return this->graphic.getGlobalBounds().intersects(target->graphic.getGlobalBounds());
	if (this->isRectangle == 0 && target->isRectangle == 0)
		return colisionCircleCircle(this,target);
//	if (this->isRectangle == 1 && target->isRectangle == 0)		//not yet implemented
//		return colisionRecCircle(this,target);
//	if (this->isRectangle == 0 && target->isRectangle == 1)
//		return colisionRecCircle(target,this);
	return false;
}


bool MySprite::colisionCircleCircle(MySprite * Circle1, MySprite * Circle2)
{
	double distance = sqrt(pow(Circle1->position.x - Circle2->position.x, 2)+ pow(Circle1->position.y - Circle2->position.y, 2));
	if (distance < Circle1->size.x + Circle2->size.x)
		return true;
	return false;
}

bool MySprite::colisionRecCircle(MySprite * Rec, MySprite * Circle)
{
	//not yet implemented
	return false;
}