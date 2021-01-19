#include "Mountain.h"

//1=gold, 2=oasis
Mountain::Mountain(int res) {
	texture_.loadFromFile(PATH_TO_TERRAINS_MOUNTAIN);
	this->sprite_.setTexture(this->texture_);
	this->name_ = "mountain";
	this->move_ = 3;
	this->food_ = 2;
	this->production_ = 1;
	this->trade_ = 0;
	this->defense_ = 1;

	if (res == 1) { this->trade_ += gold.getTrade(); }
	else if (res == 2) { this->food_ += oasis.getFood(); }
}