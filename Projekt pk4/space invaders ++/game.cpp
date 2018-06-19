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
	window = new RenderWindow(VideoMode{ width, height }, "space invaders", Style::Default);
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(false);
	Mouse::setPosition(Vector2i(width / 2, height / 2), *window);
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
	Clock movementclock;
	movementclock.restart();
	float movementtime;
	while (window->isOpen()&&!restart)
	{
		movementtime = movementclock.restart().asSeconds();
		//moving players bullets
		mutexplayer.lock();
		for (unsigned int i = 0; i < bullets.size(); i++)
		{
			bullets[i]->move(movementtime);
			if (!bullets[i]->CheckIfOnScreen(window->getSize(), bullets[i]->getposition()))
			{
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
			}
		}
		mutexplayer.unlock();
		//moving enemies bullets
		mutexenemy.lock();
		for (unsigned int a = 0; a < enemiesbullets.size(); a++)
		{
			enemiesbullets[a]->move(movementtime);
			if (!enemiesbullets[a]->CheckIfOnScreen(window->getSize(), enemiesbullets[a]->getposition()))
			{
				delete enemiesbullets[a];
				enemiesbullets.erase(enemiesbullets.begin() + a);
			}
		}
		mutexenemy.unlock();
		sleep(sf::seconds(0.8*frametime));//makeing sure movement time is long enough to make a move
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
	enemiesthread = std::thread(&Game::enemiesaction, this);
	bulletsthread = std::thread(&Game::movebullets, this);
	frameClock.restart();
	while (window->isOpen() && error==0)
	{
		frametime = frameClock.getElapsedTime().asSeconds();
		frameClock.restart();
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
//		movebullets();
		draweverything();
		collisions();
		levelhandling();
		window->display();
	}
	if (enemiesthread.joinable())
		enemiesthread.join();
	if (bulletsthread.joinable())
		bulletsthread.join();
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
	mutexplayer.lock();
	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->draw(window);
	}
	mutexplayer.unlock();
	for (unsigned int i = 0; i < level->getenemies().size(); i++)
	{
		mutexenemy.lock();
		for (unsigned int a = 0; a < enemiesbullets.size(); a++)
		{
			enemiesbullets[a]->draw(window);//draw enemies bullets
		}
		level->getenemies()[i]->draw(window);//draw enemies
		mutexenemy.unlock();
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
	Clock movementclock;
	movementclock.restart();
	float movementtime;
	while (window->isOpen() && !restart)
	{
		movementtime = movementclock.restart().asSeconds();
		mutexenemy.lock();
		for (unsigned int i = 0; i < this->level->getenemies().size(); i++)
		{
			this->level->getenemies()[i]->move(movementtime);
			this->level->getenemies()[i]->shoot();
			std::copy(this->level->getenemies()[i]->getbullets().begin(), this->level->getenemies()[i]->getbullets().end(), back_inserter(enemiesbullets));
			this->level->getenemies()[i]->getbullets().clear();
		}
		mutexenemy.unlock();
		sleep(sf::seconds(0.9*frametime));//makeing sure movement time is long enough to make a move
	}
}

void Game::collisions()
{
	mutexenemy.lock();
	for (unsigned int a = 0; a < enemiesbullets.size(); a++)
	{
		if (player->colides(enemiesbullets[a]))
		{
			player->changeHP(-(enemiesbullets[a]->getdmg()));//colisions of player and enemies bullets
			delete enemiesbullets[a];
			enemiesbullets.erase(enemiesbullets.begin() + a);
		}
	}
	mutexenemy.unlock();
	mutexplayer.lock();
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
	mutexplayer.unlock();
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
	if (enemiesthread.joinable())
		enemiesthread.join();
	if (bulletsthread.joinable())
		bulletsthread.join();
	this->restart = 0;
	this->quit = 0;
	while (level->getenemies().size() > 0)
		level->removeenemy(0);
	player->SetHP(player->getMaxHP());
	level->setLevelId(1);
	this->score = 0;
	this->gamepassed = 0;
	this->clearbullets();
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
		this->frameClock.restart();
	}
}

void Game::clearbullets()
{
	for (unsigned int i = 0; i < enemiesbullets.size(); i++)
		delete enemiesbullets[i];
	enemiesbullets.clear();
	for (unsigned int i = 0; i < bullets.size(); i++)
		delete bullets[i];
	bullets.clear();
}
