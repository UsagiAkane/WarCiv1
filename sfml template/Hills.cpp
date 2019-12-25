#include "Hills.h"

Hills::Hills()
{
	texture.loadFromFile("Terrains\\Hills.png");
	this->sprite.setTexture(this->texture);

	this->move = 2;
	this->food = 1;
	this->prodaction = 2;
	this->trade = 0;
	this->defense = 2;
}

void Hills::draw(sf::RenderWindow& w)
{
	w.draw(this->sprite);
}

