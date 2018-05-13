#pragma once

#include <SFML\Graphics.hpp>
using namespace sf;
class sprite:public Drawable
{
private:
	Texture texture;
	Sprite graphic;
	Vector2u size;
public:
	sprite();
	~sprite();
	void SetTexture();
	void SetGraphic();
	bool CheckIfOnScreen(Vector2i WindowSize, Vector2f position);
	void draw(RenderTarget& target, RenderStates states)const override;
};

