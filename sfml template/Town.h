#pragma once
#include "Map.h"
#include "Cavalry.h"
#include "Legion.h"
#include "Militia.h"
#include "Settlers.h"
#include "Aqueduct.h"
#include "Barracks.h"
#include "CityWalls.h"
#include "Library.h"
#include "Marketplace.h"
#include "Chariot.h"

class Town {
private:
	sf::Font font_;
	sf::Text population_text_;
	sf::Sprite town_sprite_;
	sf::Texture texture_;
	std::string name_;
	std::vector<Building>buildings_;
	//std::vector<Disasters>disasters;
	int position_x_, position_y_;
	int health_;
	int damage_;
	int population_;
	int population_limit_;
	int production_;
	int food_;
	int trade_;
	int happines_;
	int gold_income_;
	int science_;
	int player_id_;
	void statInfo(sf::RenderWindow& w);
public:
	bool isMenu;
	//=====================================================
	explicit Town(int position_x = 0, int position_y = 0, std::string name = "NoNameTown");

	//functions that can be changed

	///1-Settlers, 2-Militia, 3-Legion, 4-Cavalry, 5-Chariot
	void create_unit(Map& map, int unit, std::vector<Unit>& actor);
	///1-Aqueduct, 2-Barracks, 3-Walls, 4-Lib, 5-Market
	void create_building(int building);
	void set_color_by_id();
	void spawn(int x, int y, Map& map);

	//getters

	int get_position_x();
	int get_position_y();
	int get_health();
	int get_production();
	int get_gold_income();
	int get_food();
	int get_trade();
	int get_population();
	int get_happines();
	int get_player_id();
	int get_population_limit();
	int get_science();
	int get_damage();
	std::string get_name();

	//setters

	void set_position(int x, int y);
	auto set_health(int health) -> void;
	void set_production(int prod);
	void set_gold_income(int goldIncome);
	void set_food(int food);
	void set_trade(int trade);
	void set_population(int population);
	void set_happines(int happines);
	void set_player_id(int player_id);
	void set_population_limit(int population_limit);
	void set_science(int science);
	void set_name(std::string name);
	void set_damage(int damage);

	//needed

	void draw(sf::RenderWindow& w, Map& map);
	void end_of_turn(Map& map, int& gold, int& science);
	std::string get_save_town_info();
};