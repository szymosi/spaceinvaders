#pragma once

#include "player.h"
#include "Level.h"
#include "UserInterface.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

#define height 720
#define width 1280

class Game
{
private:
	unsigned int score;
	float frametime;
	unsigned int numberoflevels;

	bool gamepassed;// true if all levels passed
	bool restart = 0;
	bool quit = 0;

	Player*player;
	Level*level;
	UserInterface*UI;
	std::vector<Bullet*> bullets; //players bullets
	std::vector<Bullet*> enemiesbullets;//enemies bullets

	Event event; //SFML events
	RenderWindow*window;
	Clock Clock;//used for calculateing frametime

	bool error = 0;// 1 if fatal errors occerred
public:
	Game();
	Game(int setscore, int setlevel, unsigned int numberoflevels);//default values 0,1,3 
	~Game();
	Player*getplayer();
	float getframetime();//used for calculating bullets and enemies speeds
	void movebullets();//moves enemies and players bullets
	void loop();//main loop of game
	void draweverything();//draws players and enemies bullets, enemies and player 
	void levelhandling();//removes dead enemies, checks if level poassed, load new levels, checks if game won
	void enemiesaction();//enemies move and shoot
	void colliesions();//finds and handling colisions
	void messagebox();//shows ERROR messagebox
	void gameover();//Shows game over screen
	void you_won();//Shows win screen
	void restartgame();//starts the game from default level with full hp
	void pausemenu();
	void clearenemiesbullets();
};

