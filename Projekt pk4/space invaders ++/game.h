#pragma once

#include "player.h"
#include "vector"
#include "Level.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include <Windows.h>

#define height 720
#define width 1280

class Game
{
private:
	unsigned int score;
	float frametime;

	Player*player;
	Level*level;
	std::vector<Bullet*> bullets;

	Event event;
	RenderWindow*window;
	Clock Clock;

	bool error = 0;
public:
	Game();
	Game(int setscore, int setlevel);
	~Game();
	Player*getplayer();
	float getframetime();
	void movebullets();
	void loop();
	void draweverything();
	void levelhandling();
	void enemiesaction();
	void colliesions();
	void messagebox();
	void gameover();
};

