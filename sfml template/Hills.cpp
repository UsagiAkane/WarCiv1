#include "Hills.h"

//1=coal, 2=oil
Hills::Hills(int res)
{
	texture.loadFromFile("Terrains\\Hills.png");
	this->sprite.setTexture(this->texture);

	this->move = 2;
	this->food = 1;
	this->prodaction = 2;
	this->trade = 0;
	this->defense = 2;

	if (res == 1) { this->prodaction += coal.getProdaction(); }
	else if (res == 2) { this->prodaction += oil.getProdaction(); }
}