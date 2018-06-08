#include "stdafx.h"
#include "game.h"


Game::Game() :Game(0, 1, 2)
{
}

Game::Game(int setscore, int setlevel, unsigned int numberoflevels)
{
	score = setscore;
	player = new Player();
	this->numberoflevels = numberoflevels;
	level = new Level(player, setlevel);
	window = new RenderWindow(VideoMode{ width, height }, "testy", Style::Default);
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(false);
	UI = new UserInterface();
	gamepassed = 0;
}


Game::~Game()
{
	delete player;
	delete window;
	delete level;
	delete UI;
	for (unsigned int i = 0; i < bullets.size(); i++)
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
	//moving players bullets
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->move(frametime);
		if (!bullets[i]->CheckIfOnScreen(window->getSize(), bullets[i]->getposition()))
		{
			delete bullets[i];
			bullets.erase(bullets.begin()+i);
		}
	}
	//moving enemies bullets
	for (unsigned int i = 0; i < level->getenemies().size(); i++)
	{
		for (unsigned int a = 0; a < level->getenemies()[i]->getbullets().size(); a++)
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
	try
	{
		level->loadlevel();
	}
	catch (std::string exception)
	{
		std::cout << exception << std::endl;
		error = 1;
	}
	Clock.restart();
	while (window->isOpen() && error==0 && player->isAlive() && !gamepassed)
	{
		std::cout << player->GetHP() << std::endl;
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
		colliesions();
		levelhandling();
		window->display();
	}
	if(error==1)
		messagebox();
	if (gamepassed)
		you_won();
	if (!player->isAlive())
		gameover();
}



void Game::draweverything()
{
	//draw UI
	UI->Getbackground()->draw(window);
	UI->GetHpBar()->draw(window);
	UI->GetHpBackground()->draw(window);
	// draw players bullets
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->draw(window);
	}
	//draw enemies bullets
	for (unsigned int i = 0; i < level->getenemies().size(); i++)
	{
		for (unsigned int a = 0; a < level->getenemies()[i]->getbullets().size(); a++)
		{
			level->getenemies()[i]->getbullets()[a]->draw(window);
		}
		level->getenemies()[i]->draw(window);//draw enemies
		
	}
	player->draw(window);//draw player
}

void Game::levelhandling()
{
	for (unsigned int i = 0; i < level->getenemies().size(); i++)
	{
		if (level->getenemies()[i]->gethp() <= 0)
		{
			level->removeenemy(i);
		}
	}
	if (level->checkiflevelpassed())
	{
		if ((unsigned)level->getlevelid() < numberoflevels)
		{
			try
			{
				level->nextlevel();
			}
			catch (std::string exception)
			{
				std::cout << exception << std::endl;
				error = 1;
			}
		}
		else
			gamepassed = 1;
	}
}

void Game::enemiesaction()
{
	for (unsigned int i = 0; i < level->getenemies().size(); i++)
	{
		level->getenemies()[i]->move(frametime);
		level->getenemies()[i]->shoot();
	}
}

void Game::colliesions()
{
	for (unsigned int i = 0; i < level->getenemies().size(); i++)
	{
		for (unsigned int a = 0; a < level->getenemies()[i]->getbullets().size(); a++)
		{
			if (player->colides(level->getenemies()[i]->getbullets()[a]))
			{
				player->changeHP(-(level->getenemies()[i]->getbullets()[a]->getdmg()));//colisions of player and enemies bullets
				level->getenemies()[i]->removebullet(a);
			}
		}
		if (player->colides(level->getenemies()[i]))
		{
			player->changeHP(-(player->GetHP() / 2));//collisions of player with enemies
		}
		for (unsigned int a = 0; a < bullets.size(); a++)
		{
			if (level->getenemies()[i]->colides(bullets[a]))
			{
				level->getenemies()[i]->chengehp(-bullets[a]->getdmg());
				delete bullets[a];
				bullets.erase(bullets.begin() + a);
			}
		}
	}
}

void Game::messagebox()
{
	int msgboxID = MessageBox(
		NULL,
		(LPCWSTR)L"Fatal Error occured\nCheck console window for more info",
		(LPCWSTR)L"ERROR",
		MB_ICONWARNING
	);
}

void Game::gameover()
{
	window->clear();
	UI->GetLoseScreen()->draw(window);
	window->display();
	system("pause");
}

void Game::you_won()
{
	UI->GetWinScreen()->draw(window);
	window->display();
	system("pause");
}
