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
	std::vector<std::vector<int>> units;
public:
	Map(int sizeX = 100, int sizeY = 100);

	//void loadMap();
	//void saveMap();
	//void getTile();

	Terrain getTile(int x, int y);
	Terrain getTileVec(int x, int y);
	int getUnitInd(int x, int y);
	void pushUnit(int x, int y, int unit);
	void moveUnit(int x, int y, int newx, int newy);

	void draw(sf::RenderWindow& w);
};