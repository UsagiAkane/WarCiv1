#include "Hills.h"

//1=coal, 2=oil
Hills::Hills(int res) {
	texture_.loadFromFile(PATH_TO_TERRAINS_HILLS);
	this->sprite_.setTexture(this->texture_);
	this->name_ = "hills";
	this->move_ = 2;
	this->food_ = 1;
	this->production_ = 2;
	this->trade_ = 0;
	this->defense_ = 2;

	if (res == 1) { this->production_ += coal.getProdaction(); }
	else if (res == 2) { this->production_ += oil.getProdaction(); }
}