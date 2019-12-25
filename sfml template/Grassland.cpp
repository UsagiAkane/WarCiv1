#include "Grassland.h"

Grassland::Grassland()
{
	texture.loadFromFile("Terrains\\Grassland.png");
	this->sprite.setTexture(this->texture);

	this->move = 1;
	this->food = 2;
	this->prodaction = 1;
	this->trade = 0;
	this->defense = 1;

	if (!(rand() % 15)) {
		this->prodaction += this->coal.getProdaction();
	}
	else if (!(rand() % 11)) {
		this->prodaction += this->horses.getProdaction();
	}
}

