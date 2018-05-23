#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;
class MySprite:public Drawable
{
private:
	Texture texture;
	Sprite graphic;
	Vector2u size;
public:
	MySprite();
	~MySprite();
	void SetTexture();
	void SetGraphic();
	bool CheckIfOnScreen(Vector2i WindowSize, Vector2f position);
	void draw(RenderTarget& target, RenderStates states)const override;
	void draw(RenderWindow*window, Vector2f position);
};

