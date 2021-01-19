#include "Gold.h"

Gold::Gold() {
	this->texture_.loadFromFile(PATH_TO_RESOURCES_GOLD);
	this->sprite_.setTexture(texture_);
	this->trade = 2;
}

int Gold::getTrade() {
	return this->trade;
}