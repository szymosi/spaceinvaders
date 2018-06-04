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
	window->setMouseCursorVisible(false);
}


Game::~Game()
{
	delete player;
	delete window;
	for (auto i = 0; i < bullets.size(); i++)
		delete bullets[i];
}


Player * Game::getplayer()
{
	return player;
}

float Game::getframetime()
{
	return frametime;
}

void Game::movebullets()
{
	for (auto i = 0; i < bullets.size(); i++)
	{
		bullets[i]->move(frametime);
		if (!bullets[i]->CheckIfOnScreen(window->getSize(), bullets[i]->getposition()))
		{
			delete bullets[i];
			bullets.erase(bullets.begin()+i);
		}
	}
}

void Game::loop()
{
	Clock.restart();
	enemy = new BigEnemy(player,Vector2u(500,300));
	while (window->isOpen())
	{
		frametime = Clock.getElapsedTime().asSeconds();
		Clock.restart();
		window->clear(Color::Black);
		window->pollEvent(event);
		if (event.type == Event::Closed)
		{
			window->close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			Bullet*tmp = player->Shoot();
			if (tmp != NULL)
				bullets.push_back(tmp);
		}
		player->SetPosition(Mouse::getPosition(*window),window->getSize());

		//
		enemy->move(frametime);
		enemy->shoot();
		if (enemy->getbullets().size() > 0)
			bullets.insert(this->bullets.end(), enemy->getbullets().begin(), enemy->getbullets().end());
		enemy->draw(window);
		//

		movebullets();
		draweverything();
		window->display();
		//std::cout << frametime << std::endl;
	}
}



void Game::draweverything()
{
	player->draw(window);
	for (auto i = 0; i < bullets.size(); i++)
	{
		bullets[i]->draw(window);
//		bullets[i]->move();
	}
}
