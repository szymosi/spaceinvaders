#pragma once

#include "player.h"
#include <SFML\Graphics.hpp>

#define height 720
#define width 1280

class Game
{
private:
	unsigned int score;
	unsigned int level;

	Player*player;

	Event event;
	RenderWindow*window;

public:
//	game();
	Game();
	Game(int setscore, int setlevel);
	~Game();
	Player*getplayer();
	void loop();

};

