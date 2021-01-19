#include "Game.h"

Game::Game() {
	this->texture_.loadFromFile(PATH_TO_RESOURCES_GAME);
	this->sprite_.setTexture(texture_);
	this->food = 2;
}

int Game::getFood() {
	return this->food;
}