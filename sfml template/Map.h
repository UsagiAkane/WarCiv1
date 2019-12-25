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
	//int map[100][100];
	std::vector<std::vector<int>> map;


public:
	Map(int sizeX = 100, int sizeY = 100);

	//void loadMap();
	//void saveMap();
	//void getTile();


	void draw(sf::RenderWindow& w);
};