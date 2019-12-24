#include "Grassland.h"

Grassland::Grassland()
{
	//texture load from file
	this->move = 1;
	this->food = 2;
	this->prodaction = 1;
	this->trade = 0;
	this->defense = 1;

	if (!(rand() % 15)) {
		this->prodaction += this->coal.getProdaction();
		this->coal.setHave(1);
	}
	else if (!(rand() % 11)) {
		this->prodaction += this->horses.getProdaction();
		this->horses.setHave(1);
	}
}

