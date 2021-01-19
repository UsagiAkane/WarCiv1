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
#include "path.h"

class Map {
private:
	std::vector<std::vector<int>> map;
	std::vector<std::vector<int>> units;
public:
	explicit Map(int size_x = 50, int size_y = 50, int res_gen_chanse = 8);

	//CHECKERS
	Terrain get_tile(int x, int y);
	Terrain get_tile_vec(int x, int y);
	bool is_town(int x, int y);
	bool is_fog(int x, int y);
	//UNITS
	int get_unit_id(int x, int y);
	int get_unit_ind(int x, int y);
	int get_unit_player_id(int x, int y);
	void push_unit(int x, int y, int unit);
	void move_unit(int x, int y, int newx, int newy, int unitPlayerID);
	void del_unit(int x, int y);
	//SYSTEM/SAVES
	std::vector<std::vector<int>>& get_vec_terrains_int();
	std::vector<std::vector<int>>& get_vec_units_int();
	void save_map();
	void load_terrains(std::string line);
	void load_units(std::string line);
	void re_take_town(int x, int y, int newPlayerID);
	void radar_fog(int newx, int newy);
	void __getInfo_DEBUG(int x, int y);
	void get_info(int x, int y, sf::RenderWindow& w);

	void draw(sf::RenderWindow& w);
};