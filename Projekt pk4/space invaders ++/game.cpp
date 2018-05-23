#include "stdafx.h"
#include "game.h"


Game::Game() :Game(0, 0)
{
}

Game::Game(int setscore, int setlevel): window{ VideoMode{ width, height }, "testy",Style::None }
{
	score = setscore;
	level = setlevel;
	player = new Player();

}


Game::~Game()
{
}

void Game::initialize()
{
	window.setFramerateLimit(60);
}

Player * Game::getplayer()
{
	return player;
}

void Game::loop()
{
	while (window.isOpen())
	{
		window.clear(Color::Black);
		window.pollEvent(event);
		if (event.type == Event::Closed)
		{
			window.close();
		}
		player->SetPosition(Mouse::getPosition(window));
		player->drawplayer(&window);
		window.display();
	}
}
