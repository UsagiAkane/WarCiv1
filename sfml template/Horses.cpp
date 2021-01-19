#include "Horses.h"

Horses::Horses() {
	this->texture_.loadFromFile(PATH_TO_RESOURCES_HORSES);
	this->sprite_.setTexture(texture_);
	this->prodaction = 2;
}

int Horses::getProdaction() {
	return this->prodaction;
}