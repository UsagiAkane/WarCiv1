#pragma once
#include <SFML/Graphics.hpp>
#include "Resourses.h"

class Terrain {
protected:
	sf::Texture texture;
	//sf::Sprite map_forest_tile;

	int move;
	int food;
	int prodaction;
	int trade;
	double defense;
public:
	virtual sf::Texture getTexture();
	virtual	int getMove();
	virtual	int getFood();
	virtual	int getProdaction();
	virtual	int getTrade();
	virtual	double getDefense();
	//virtual void draw(sf::RenderWindow&w)=0;
};