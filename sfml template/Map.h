#pragma once
#include<SFML/Graphics.hpp>
#include "Hills.h"
#include "Forest.h"
#include "Mountain.h"
#include "Grassland.h"

#define SIZEX 100;
#define SIZEY 100;

class Map {
private:
	char map[100][100];
public:
	Map();

	//void loadMap();
	//void saveMap();
	//void getTile();
	void draw(sf::RenderWindow& w);
};