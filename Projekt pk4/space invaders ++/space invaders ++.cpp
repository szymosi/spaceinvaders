 // space invaders ++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "game.h"
#include <SFML\Graphics.hpp>

#define height 720
#define width 1280

using namespace sf;
int main()
{
	RenderWindow window{VideoMode{ width, height }, "testy",Style::None};
	window.setFramerateLimit(60);
	Event event;
//	sf::Vector2i cursorPosition;
//	while (window.isOpen())
//	{
//		window.clear(Color::Black);
//		window.pollEvent(event);
//		if (event.type == Event::Closed)
//		{
//			window.close();
//		}
//		cursorPosition = Mouse::getPosition(window);
//		printf("%i:%i",cursorPosition.x,cursorPosition.y);
//		system("cls");
//		window.display();
//	}
    return 0;
}

