#pragma once

#include "player.h"
class game
{
private:
	unsigned int score;
	unsigned int level;

	player*player;
	vector//vector poziomow
public:
	game();
	game(int setscore, int setlevel);
	~game();
	void loop();

};

