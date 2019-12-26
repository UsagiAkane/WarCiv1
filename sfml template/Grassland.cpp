#include "Grassland.h"

//1=coal, 2=horses
Grassland::Grassland(int res)
{
	texture.loadFromFile("Terrains\\Grassland.png");
	this->sprite.setTexture(this->texture);

	this->move = 1;
	this->food = 2;
	this->prodaction = 1;
	this->trade = 0;
	this->defense = 0;

	if (res == 1) {this->prodaction += coal.getProdaction();}
	else if(res==2){ this->prodaction += horses.getProdaction(); }
}