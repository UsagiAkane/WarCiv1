#include "Ocean.h"

Ocean::Ocean(int res){
	texture.loadFromFile("Terrains\\Ocean.png");
	this->sprite.setTexture(this->texture);
	this->name = "ocean";
	this->move = 1;
	this->food = 1;
	this->prodaction = 1;
	this->trade = 2;
	this->defense = 0;
}