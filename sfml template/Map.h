#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<string>
#include "Hills.h"
#include "Forest.h"
#include "Mountain.h"
#include "Grassland.h"
#include "Terrain.h"

class Map {
private:
	std::vector<std::vector<int>> map;
public:
	Map(int sizeX = 100, int sizeY = 100);

	//void loadMap();
	//void saveMap();
	//void getTile();

	//int getMove(int x, int y);
	//int getFood(int x, int y);
	//int getProdaction(int x, int y);
	//int getTrade(int x, int y);
	//double getDefense(int x, int y);

	Terrain getTile(int x, int y);

	void draw(sf::RenderWindow& w);
};