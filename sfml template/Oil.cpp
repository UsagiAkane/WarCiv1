#include "Oil.h"

Oil::Oil()
{
	this->texture.loadFromFile("Resources\\Oil.png");
	this->sprite.setTexture(texture);
	this->prodaction = 4;
}

int Oil::getProdaction()
{
	return this->prodaction;
}
