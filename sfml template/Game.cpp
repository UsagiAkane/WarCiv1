#include "Game.h"

Game::Game()
{
	this->texture.loadFromFile("Resources\\Game.png");
	this->sprite.setTexture(texture);
	this->food = 2;
}

int Game::getFood()
{
	return this->food;
}
