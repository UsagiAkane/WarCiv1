#include <iostream>
#include "Terrain.h";

Terrain::Terrain()
{
	this->name = "<Terrain>";
	this->move = 0;
	this->food = 0;
	this->prodaction = 0;
	this->trade = 0;
	this->defense = 0;
}

sf::Texture Terrain::getTexture()
{
	return this->texture;
}

std::string Terrain::getName()
{
	return this->name;
}

int Terrain::getMove()
{
	return this->move;
}

int Terrain::getFood()
{
	return this->food;
}

int Terrain::getProdaction()
{
	return this->prodaction;
}

int Terrain::getTrade()
{
	return this->trade;
}

int Terrain::getDefense()
{
	return this->defense;
}

void Terrain::__getInfo_DEBUG()
{
	std::cout << "\n-----tile-----\n";
	std::cout << "name = " << this->name << std::endl;
	std::cout << "move = " << this->move << std::endl;
	std::cout << "food = " << this->food << std::endl;
	std::cout << "prodaction = " << this->prodaction << std::endl;
	std::cout << "trade = " << this->trade << std::endl;
	std::cout << "defense = " << this->defense;
	std::cout << "\n---tile-end---\n";
}
