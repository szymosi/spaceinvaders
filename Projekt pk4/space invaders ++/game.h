#pragma once

#include "player.h"
#include "vector"
#include <SFML\Graphics.hpp>

#define height 720
#define width 1280

class Game
{
private:
	unsigned int score;
	unsigned int level;

	Player*player;
	std::vector<Bullet*> bullets;

	Event event;
	RenderWindow*window;

public:
	Game();
	Game(int setscore, int setlevel);
	~Game();
	Player*getplayer();
	void movebullets();
	void loop();
	void draweverything();
};

