 // space invaders ++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <SFML\Graphics.hpp>



int main()
{


	Game*game = new Game();
	game->loop();


	delete game;
    return 0;
}

