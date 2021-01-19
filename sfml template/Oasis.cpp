#include "Oasis.h"

Oasis::Oasis() {
	this->texture_.loadFromFile(PATH_TO_RESOURCES_OASIS);
	this->sprite_.setTexture(texture_);
	this->food = 3;
}

int Oasis::getFood() {
	return this->food;
}