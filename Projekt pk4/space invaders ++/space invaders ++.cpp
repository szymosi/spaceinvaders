 // space invaders ++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <SFML\Graphics.hpp>



int main()
{
//	RenderWindow window{VideoMode{ width, height }, "testy",Style::None};
//	window.setFramerateLimit(60);
//	Event event;

	Game*game = new Game();
	game->loop();

//	sf::Vector2i cursorPosition;
//	while (window.isOpen())
//	{
//		window.clear(Color::Black);
//		window.pollEvent(event);
//		if (event.type == Event::Closed)
//		{
//			window.close();
//		}
//		game->getplayer()->SetPosition(Mouse::getPosition(window));
//		cursorPosition = Mouse::getPosition(window);
//		printf("%i:%i",cursorPosition.x,cursorPosition.y);
//		system("cls");
//		window.display();
//	}
	delete game;
    return 0;
}

