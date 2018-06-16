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
	for (unsigned int i = 0; i < enemiesbullets.size(); i++)
		delete enemiesbullets[i];
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
	for (unsigned int a = 0; a < enemiesbullets.size(); a++)
	{
		Bullet*tmpbullet = enemiesbullets[a];
		tmpbullet->move(frametime);
		if (!tmpbullet->CheckIfOnScreen(window->getSize(), tmpbullet->getposition()))
		{
			delete enemiesbullets[a];
			enemiesbullets.erase(enemiesbullets.begin() + a);
		}
	}
}

void Game::loop()
{
	Mouse::setPosition(Vector2i(width/2,height/2),*window);
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
	while (window->isOpen() && error==0)
	{
		frametime = Clock.getElapsedTime().asSeconds();
		Clock.restart();
		window->clear(Color::Black);
		window->pollEvent(event);
		if (event.type == Event::Closed)
		{
			window->close();
		}
		if (gamepassed)
			you_won();
		if (!player->isAlive())
			gameover();
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			pausemenu();
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			Bullet*tmp = player->Shoot();
			if (tmp != NULL)
				bullets.push_back(tmp);
		}
		player->SetPosition(Mouse::getPosition(*window),window->getSize());
		enemiesaction();
		movebullets();
		draweverything();
		collisions();
		levelhandling();
		window->display();
	}
	if(error==1)
		messagebox();
}



void Game::draweverything()
{
	//draw UI
	UI->ScaleHpBar((float)(player->GetHP()) / (float)(player->getMaxHP()));
	UI->Getbackground()->draw(window);
	UI->GetHpBar()->draw(window);
	UI->GetHpBackground()->draw(window);
	// draw players bullets
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->draw(window);
	}
	for (unsigned int i = 0; i < level->getenemies().size(); i++)
	{
		for (unsigned int a = 0; a < enemiesbullets.size(); a++)
		{
			enemiesbullets[a]->draw(window);//draw enemies bullets
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
		std::copy(level->getenemies()[i]->getbullets().begin(), level->getenemies()[i]->getbullets().end(), back_inserter(enemiesbullets));
		level->getenemies()[i]->getbullets().clear();
	}
}

void Game::collisions()
{
	for (unsigned int a = 0; a < enemiesbullets.size(); a++)
	{
		if (player->colides(enemiesbullets[a]))
		{
			player->changeHP(-(enemiesbullets[a]->getdmg()));//colisions of player and enemies bullets
			delete enemiesbullets[a];
			enemiesbullets.erase(enemiesbullets.begin() + a);
		}
	}
	for (unsigned int i = 0; i < level->getenemies().size(); i++)
	{
		if (player->colides(level->getenemies()[i]))
		{
			player->changeHP(-10);//collisions of player with enemies
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
	while (!this->restart && !this->quit)
	{
		window->clear();
		UI->GetLoseScreen()->draw(window);
		UI->GetRestartButton()->draw(window);
		UI->GetQuitButton()->draw(window);
		player->SetPosition(Mouse::getPosition(*window), window->getSize());
		player->draw(window);
		window->display();
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (player->colides(UI->GetRestartButton()))
			{
				this->restart = 1;
			}
			if (player->colides(UI->GetQuitButton()))
			{
				this->quit = 1;
			}
		}
	}
	if (this->restart==1)
	{
		this->restartgame();
	}
	if (this->quit == 1)
	{
		this->window->close();
	}
}

void Game::you_won()
{
	while (!this->restart && !this->quit)
	{
		window->clear();
		UI->GetWinScreen()->draw(window);
		UI->GetRestartButton()->draw(window);
		UI->GetQuitButton()->draw(window);
		player->SetPosition(Mouse::getPosition(*window), window->getSize());
		player->draw(window);
		window->display();
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (player->colides(UI->GetRestartButton()))
			{
				this->restart = 1;
			}
			if (player->colides(UI->GetQuitButton()))
			{
				this->quit = 1;
			}
		}
	}
	if (this->restart == 1)
	{
		this->restartgame();
	}
	if (this->quit == 1)
	{
		this->window->close();
	}
}

void Game::restartgame()
{
	this->restart = 0;
	this->quit = 0;
	while (level->getenemies().size() > 0)
		level->removeenemy(0);
	player->SetHP(player->getMaxHP());
	level->setLevelId(1);
	this->score = 0;
	this->gamepassed = 0;
	this->clearenemiesbullets();
	this->loop();
}

void Game::pausemenu()
{
	bool resume = 0;
	while (!this->restart && !this->quit && !resume)
	{
		window->clear();
		UI->GetPauseScreen()->draw(window);
		UI->GetResumeButton()->draw(window);
		UI->GetRestartButton()->draw(window);
		UI->GetQuitButton()->draw(window);
		player->SetPosition(Mouse::getPosition(*window), window->getSize());
		player->draw(window);
		window->display();
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (player->colides(UI->GetResumeButton()))
			{
				resume = 1;
			}
			if (player->colides(UI->GetRestartButton()))
			{
				this->restart = 1;
			}
			if (player->colides(UI->GetQuitButton()))
			{
				this->quit = 1;
			}
		}
	}
	if (this->restart == 1)
	{
		this->restartgame();
	}
	if (this->quit == 1)
	{
		this->window->close();
	}
	if (resume == 1)
	{
		this->Clock.restart();
	}
}

void Game::clearenemiesbullets()
{
	for (unsigned int i = 0; i < enemiesbullets.size(); i++)
		delete enemiesbullets[i];
	enemiesbullets.clear();
}
