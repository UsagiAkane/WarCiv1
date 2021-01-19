#include "Oil.h"

Oil::Oil() {
	this->texture_.loadFromFile(PATH_TO_RESOURCES_OIL);
	this->sprite_.setTexture(texture_);
	this->prodaction = 4;
}

int Oil::getProdaction() {
	return this->prodaction;
}