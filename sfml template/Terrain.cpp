#include "Terrain.h";

sf::Texture Terrain::getTexture()
{
	return this->texture;
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

double Terrain::getDefense()
{
	return this->defense;
}
