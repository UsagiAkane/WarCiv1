#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<string>
#include "Hills.h"
#include "Forest.h"
#include "Mountain.h"
#include "Grassland.h"
#include "Ocean.h"
#include "Terrain.h"
#include <fstream>


class Map {
private:
	std::vector<std::vector<int>> map;
	std::vector<std::vector<int>> units;
public:
	Map(int sizeX = 100, int sizeY = 100);

	//void loadMap();
	void saveMap();

	void loadTerrains(std::string line);
	void loadUnits(std::string line);

	Terrain getTile(int x, int y);
	Terrain getTileVec(int x, int y);
	int getUnitInd(int x, int y);
	int getUnitID(int x, int y);
	int getUnitPlayerID(int x, int y);
	void pushUnit(int x, int y, int unit);
	void moveUnit(int x, int y, int newx, int newy);
	void delUnit(int x, int y);
	std::vector<std::vector<int>>& _getVecTerrainsInt();
	std::vector<std::vector<int>>& _getVecUnitsInt();
	void __getInfo_DEBUG(int x, int y);

	void draw(sf::RenderWindow& w);
};