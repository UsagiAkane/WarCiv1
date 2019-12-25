#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<string>
#include "Hills.h"
#include "Forest.h"
#include "Mountain.h"
#include "Grassland.h"

class Map {
private:
	//char map[100][100];
	int map[100][100];
	
public:
	Map();

	//void loadMap();
	//void saveMap();
	//void getTile();
	void draw(sf::RenderWindow& w);
};