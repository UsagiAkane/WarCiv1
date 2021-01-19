#include "Plains.h"

Plains::Plains(int res) {
	texture_.loadFromFile(PATH_TO_TERRAINS_PLAINS);
	this->sprite_.setTexture(this->texture_);
	this->name_ = "plains";
	this->move_ = 1;
	this->food_ = 1;
	this->production_ = 1;
	this->trade_ = 0;
	this->defense_ = 1;

	if (res == 1)
		this->production_ += this->horses.getProdaction();
}