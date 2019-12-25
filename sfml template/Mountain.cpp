#include "Mountain.h"

Mountain::Mountain()
{
	texture.loadFromFile("Terrains\\Mountains.png");
	this->sprite.setTexture(this->texture);

	this->move = 1;
	this->food = 2;
	this->prodaction = 1;
	this->trade = 0;
	this->defense = 1.5;

	if (!(rand() % 15)) {
		this->trade += this->gold.getTrade();
	}
	else if (!(rand() % 11)) {
		this->food += this->oasis.getFood();
	}
}