#include "Forest.h"

Forest::Forest()
{
	texture.loadFromFile("Terrains\\Forest.png");
	this->sprite.setTexture(this->texture);

	this->move = 1;
	this->food = 1;
	this->prodaction = 2;
	this->trade = 0;
	this->defense = 1.5;

	if (!(rand() % 10)) {
		this->food += this->game.getFood();
		this->game.setHave(1);
	}
}

//void Forest::draw(sf::RenderWindow& w)
//{
//	sf::Sprite map_forest_tile(this->texture);
//	w.draw(map_forest_tile);
//}
