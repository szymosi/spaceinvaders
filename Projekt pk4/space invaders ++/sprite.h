#pragma once

#include <SFML\Graphics.hpp>
#include <string.h>
using namespace sf;
class MySprite:public Drawable
{
private:
	Texture texture;
	Sprite graphic;
	Vector2u size;
	public:
	MySprite();
	MySprite(std::string filename);
	~MySprite();

	Vector2u GetSize();

	void SetTexture(std::string filename);
	void SetGraphic(std::string filename);
	bool CheckIfOnScreen(Vector2i WindowSize, Vector2i position);
	void draw(RenderTarget& target, RenderStates states)const override;
	void draw(RenderWindow*window, Vector2i position);
};

