#include "Coal.h"

Coal::Coal() {
	this->texture_.loadFromFile(PATH_TO_RESOURCES_COAL);
	this->sprite_.setTexture(texture_);
	this->prodaction = 2;
}

int Coal::getProdaction() {
	return this->prodaction;
}