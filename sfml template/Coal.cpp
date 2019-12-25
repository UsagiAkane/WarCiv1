#include "Coal.h"

Coal::Coal()
{
	this->texture.loadFromFile("Resources\\Coal.png");
	this->sprite.setTexture(texture);
	this->prodaction = 2;
}

int Coal::getProdaction()
{
	return this->prodaction;
}
