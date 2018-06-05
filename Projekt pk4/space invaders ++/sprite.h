#pragma once

#include <SFML\Graphics.hpp>
#include <string.h>
#include <math.h>
using namespace sf;
class MySprite:public Drawable
{
protected:
	Vector2u position;
private:
	Texture texture;
	Sprite graphic;
	Vector2u size;
	bool isRectangle=1;
//	Vector2u position;
	//bool colisionRecRec(MySprite*Rec1,MySprite*Rec2);
	bool colisionCircleCircle(MySprite*Circle1, MySprite*Circle2);
	bool colisionRecCircle(MySprite*Rec, MySprite*Circle);
	public:
	MySprite();
	MySprite(std::string filename);
	MySprite(std::string filename,Vector2u position);
	~MySprite();

	Vector2u GetSize();

	void SetTexture(std::string filename);
	void SetGraphic(std::string filename);
	Vector2u GetPosition();
	bool CheckIfOnScreen(Vector2u WindowSize, Vector2u position);
	void draw(RenderTarget& target, RenderStates states)const override;
	void draw(RenderWindow*window, Vector2u position);
	void draw(RenderWindow*window);
	bool colides(MySprite*target);
};

