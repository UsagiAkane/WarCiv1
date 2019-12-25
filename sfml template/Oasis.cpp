#include "Oasis.h"

Oasis::Oasis()
{
	this->texture.loadFromFile("Resources\\Oasis.png");
	this->sprite.setTexture(texture);
	this->food = 3;
}

int Oasis::getFood()
{
	return this->food;
}
