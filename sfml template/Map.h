#pragma once
#include<SFML/Graphics.hpp>
#include"Map_I.h"
#include"Terrain.h"
#include<vector>
#include"Forest.h"

class Map : /*public Map_I,*/ public Terrain {
private:
	std::vector<std::vector<Terrain>> map;
public:
	Map() {
		std::vector<Terrain> map1;
		map1.push_back(Forest());
		map.push_back(map1);
	}

	void loadMap();
	void saveMap();
	void getTile();
	void draw(sf::RenderWindow& w);
};

