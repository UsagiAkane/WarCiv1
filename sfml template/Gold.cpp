#include "Gold.h"

Gold::Gold()
{
	this->texture.loadFromFile("Resources\\Gold.png");
	this->sprite.setTexture(texture);
	this->trade = 2;
}

int Gold::getTrade()
{
	return this->trade;
}
