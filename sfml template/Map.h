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
#include "Plains.h"
#include "Terrain.h"
#include <fstream>


class Map {
private:
	std::vector<std::vector<int>> map;
	std::vector<std::vector<int>> units;
public:
	Map(int sizeX = 50, int sizeY = 50, int resGenChanse = 8);

	//void loadMap();
	void saveMap();

	void loadTerrains(std::string line);
	void loadUnits(std::string line);

	Terrain getTile(int x, int y);
	Terrain getTileVec(int x, int y);
	int getUnitInd(int x, int y);
	int getUnitID(int x, int y);
	bool isTown(int x, int y);
	int getUnitPlayerID(int x, int y);
	void pushUnit(int x, int y, int unit);
	void moveUnit(int x, int y, int newx, int newy);
	void delUnit(int x, int y);
	std::vector<std::vector<int>>& _getVecTerrainsInt();
	std::vector<std::vector<int>>& _getVecUnitsInt();
	void __getInfo_DEBUG(int x, int y);
	void changePlayerID(int x, int y);
	void reTakeTown(int x,int y,int newPlayerID);

	void draw(sf::RenderWindow& w);
};