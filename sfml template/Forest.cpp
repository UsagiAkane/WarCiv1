#include "Forest.h"

Forest::Forest(int res) {
	texture_.loadFromFile(PATH_TO_TERRAINS_FOREST);
	this->sprite_.setTexture(this->texture_);
	this->name_ = "forest";
	this->move_ = 1;
	this->food_ = 1;
	this->production_ = 2;
	this->trade_ = 0;
	this->defense_ = 1;

	if (res == 1)
		this->food_ += this->game.getFood();
}