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
	bool isRectangle=1;//equals 1 if shape is rectangle 0 if circle
	//bool colisionRecRec(MySprite*Rec1,MySprite*Rec2);
	bool colisionCircleCircle(MySprite*Circle1, MySprite*Circle2);
	bool colisionRecCircle(MySprite*Rec, MySprite*Circle);
	public:
	MySprite();
	MySprite(std::string filename);
	MySprite(std::string filename,Vector2u position);
	~MySprite();

	Vector2u GetSize();//returns size of sprite

	void SetTexture(std::string filename);//loads texture from file
	void SetGraphic(std::string filename);//loads sprite from file sets its position in the middle
	Vector2u GetPosition();//returns sprites possition
	bool CheckIfOnScreen(Vector2u WindowSize, Vector2u position);//return true if inside window, fales if outside window
	void draw(RenderWindow*window, Vector2u position);//draws sprite inside window at given possition
	void draw(RenderWindow*window);//draws sprite inside window at sprites possition
	bool colides(MySprite*target);//returns true if this colides with target
};

