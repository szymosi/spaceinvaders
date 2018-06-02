#pragma once

#include "player.h"
#include "vector"
#include "Enemy.h"
#include "SmallEnemy.h"
#include "MediumEnemy.h"
#include <SFML\Graphics.hpp>
#include<iostream>

#define height 720
#define width 1280

class Game
{
private:
	unsigned int score;
	unsigned int level;
	float frametime;

	Player*player;
	std::vector<Bullet*> bullets;
	Enemy*enemy;

	Event event;
	RenderWindow*window;
	Clock Clock;

public:
	Game();
	Game(int setscore, int setlevel);
	~Game();
	Player*getplayer();
	float getframetime();
	void movebullets();
	void loop();
	void draweverything();
};

