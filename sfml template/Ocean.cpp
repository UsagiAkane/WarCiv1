#include "Ocean.h"

Ocean::Ocean(int res) {
	texture_.loadFromFile(PATH_TO_TERRAINS_OCEAN);
	this->sprite_.setTexture(this->texture_);
	this->name_ = "ocean";
	this->move_ = 1;
	this->food_ = 1;
	this->production_ = 1;
	this->trade_ = 2;
	this->defense_ = 0;
}