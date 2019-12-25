#include "Horses.h"

Horses::Horses()
{
	this->texture.loadFromFile("Resources\\Horses.png");
	this->sprite.setTexture(texture);
	this->prodaction = 2;
}

int Horses::getProdaction()
{
	return this->prodaction ;
}
