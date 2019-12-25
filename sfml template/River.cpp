#include "River.h"

River::River()
{
	texture.loadFromFile("Terrains\\Forest.png");
	this->sprite.setTexture(this->texture);

	this->move = 1;
	this->food = 2;
	this->prodaction = 1;
	this->trade = 0;
	this->defense = 1.5;
}

