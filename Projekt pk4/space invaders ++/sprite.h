#pragma once

#include <SFML\Graphics.hpp>
#include <string.h>
using namespace sf;
class MySprite:public Drawable
{
protected:
	Vector2u position;
private:
	Texture texture;
	Sprite graphic;
	Vector2u size;
//	Vector2u position;
	public:
	MySprite();
	MySprite(std::string filename);
	MySprite(std::string filename,Vector2u position);
	~MySprite();

	Vector2u GetSize();

	void SetTexture(std::string filename);
	void SetGraphic(std::string filename);
	bool CheckIfOnScreen(Vector2u WindowSize, Vector2u position);
	void draw(RenderTarget& target, RenderStates states)const override;
	void draw(RenderWindow*window, Vector2u position);
};

