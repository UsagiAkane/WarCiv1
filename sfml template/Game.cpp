#include "Game.h"

Game::Game()
{
	//texture
	this->food = 2;
	this->have = 0;
}

int Game::getFood()
{
	return this->food;
}
