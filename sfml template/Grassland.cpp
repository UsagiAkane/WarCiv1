#include "Grassland.h"

//1=coal, 2=horses
Grassland::Grassland(int res) {
	texture_.loadFromFile(PATH_TO_TERRAINS_GRASSLAND);
	this->sprite_.setTexture(this->texture_);
	this->name_ = "grassland";
	this->move_ = 1;
	this->food_ = 2;
	this->production_ = 1;
	this->trade_ = 0;
	this->defense_ = 0;

	if (res == 1) { this->production_ += coal.getProdaction(); }
	else if (res == 2) { this->production_ += horses.getProdaction(); }
}