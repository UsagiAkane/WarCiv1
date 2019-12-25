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
}
//1=gold, 2=oasis
Mountain::Mountain(int res)
{
	texture.loadFromFile("Terrains\\Mountains.png");
	this->sprite.setTexture(this->texture);

	this->move = 1;
	this->food = 2;
	this->prodaction = 1;
	this->trade = 0;
	this->defense = 1.5;

	if (res == 1) { this->trade += gold.getTrade(); }
	else if (res == 2) { this->food += oasis.getFood(); }
}
