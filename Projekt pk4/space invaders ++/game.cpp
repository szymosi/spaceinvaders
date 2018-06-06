#include "stdafx.h"
#include "game.h"


Game::Game() :Game(0, 1)
{
}

Game::Game(int setscore, int setlevel)
{
	score = setscore;
	player = new Player();
	level = new Level(player, setlevel);
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
	//moving enemies bullets
	for (auto i = 0; i < level->getenemies().size(); i++)
	{
		for (auto a = 0; a < level->getenemies()[i]->getbullets().size(); a++)
		{
			Bullet*tmpbullet = level->getenemies()[i]->getbullets()[a];
			tmpbullet->move(frametime);
			if (!tmpbullet->CheckIfOnScreen(window->getSize(), tmpbullet->getposition()))
			{
				level->getenemies()[i]->removebullet(a);
			}
		}
	}
}

void Game::loop()
{
	level->loadlevel();
	Clock.restart();
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
		enemiesaction();
		movebullets();
		draweverything();
		window->display();
		//std::cout << frametime << std::endl;
	}
}



void Game::draweverything()
{
	// draw players bullets
	for (auto i = 0; i < bullets.size(); i++)
	{
		bullets[i]->draw(window);
	}
	//draw enemies bullets
	for (auto i = 0; i < level->getenemies().size(); i++)
	{
		for (auto a = 0; a < level->getenemies()[i]->getbullets().size(); a++)
		{
			level->getenemies()[i]->getbullets()[a]->draw(window);
			if (player->colides(level->getenemies()[i]->getbullets()[a]))
				getchar();
		}
		level->getenemies()[i]->draw(window);//draw enemies
		
	}
	player->draw(window);//draw player
	changelevel();
}

void Game::changelevel()
{
	if (level->checkiflevelpassed())
	{
		level++;
		level->loadlevel();
	}
}

void Game::enemiesaction()
{
	for (auto i = 0; i < level->getenemies().size(); i++)
	{
		level->getenemies()[i]->move(frametime);
		level->getenemies()[i]->shoot();
	}
}
