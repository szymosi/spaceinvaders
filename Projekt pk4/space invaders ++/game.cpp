#include "stdafx.h"
#include "game.h"


Game::Game() :Game(0, 0)
{
}

Game::Game(int setscore, int setlevel)
{
	score = setscore;
	level = setlevel;
	player = new Player();
	window = new RenderWindow(VideoMode{ width, height }, "testy", Style::Default);
	window->setFramerateLimit(60);
}


Game::~Game()
{
}


Player * Game::getplayer()
{
	return player;
}

void Game::loop()
{
	while (window->isOpen())
	{
		window->clear(Color::Black);
		window->pollEvent(event);
		if (event.type == Event::Closed)
		{
			window->close();
		}
		player->SetPosition(Mouse::getPosition(*window));
		player->drawplayer(window);
		window->display();
	}
}
