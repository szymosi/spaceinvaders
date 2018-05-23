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
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			bullets.push_back(player->Shoot());
		player->SetPosition(Mouse::getPosition(*window));
		draweverything();
		window->display();
	}
}

void Game::draweverything()
{
	player->draw(window, player->GetPosition());
	for (auto i = 0; i < bullets.size(); i++)
	{
		bullets[i]->draw(window, bullets[i]->getposition());
		bullets[i]->move();
	}
}
