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

	if (!(rand() % 15)) {
		this->prodaction += this->coal.getProdaction();
		this->coal.setHave(1);
	}
	else if (!(rand() % 11)) {
		this->prodaction += this->oil.getProdaction();
		this->oil.setHave(1);
	}
}

