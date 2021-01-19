#pragma once
#include <iostream>//debug
#include "Terrain.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Map.h"
#include <Windows.h>

#define BORDER_PIXEL_16 16
#define BORDER_PIXEL_60 60
#define BORDER_PIXEL_30 30
#define BORDER_PIXEL_32 32

class Unit {
protected:
	//general stat
	sf::Sprite warrior_sprite_;
	std::string name_;
	int health_;
	int armor_;
	int damage_;
	int steps_;
	int max_steps_;
	unsigned short rank_;
	unsigned int count_of_kill_;
	//cost
	int salary_; //per turn
	int production_price_;
	int price_; //gold price
	//info for player
	int index_; //index of unit, for example 1 = settlers
	int player_id_; //this variable will show who the unit serves
	int position_x_, position_y_;
	//variable to know state of unit
	bool is_active_;
	bool is_alive_;
	//functions to call inside
	void checkForAttackAndAttackHide(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies, sf::RenderWindow& w, int direction);

public:
	//constuctor
	Unit(std::string name, int health, int armor, int damage, int speed,
		unsigned short rank, int salary, int production_price, int price,
		int index, int player_id, int max_speed);

	//functions that can be changed
	virtual void move(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies, sf::RenderWindow& w);
	virtual void attack(Unit& u, Map& map, int x, int y);
	virtual void recharge();

	//DEBUG
	void get_show_info_debug();

	//functions ,that can be used by pressed key
	void skip_turn();
	void burrow();
	void wait();
	//getters
	int get_damage();
	int get_health();
	int get_armor();
	int get_rank();
	bool get_is_alive();
	bool get_is_active();
	sf::Sprite get_sprite();
	int get_index();
	int get_position_x();
	int get_position_y();
	std::string get_name();
	int get_player_id();
	int get_max_speed();
	int get_production_price();
	int get_price();
	int get_steps();
	//setters
	void set_damage(int damage);
	void set_health(int health);
	void set_rank(int rank);
	void set_count_of_kill(unsigned int count_of_kill);
	void set_active(bool active);
	void set_position(int x, int y);
	void set_player_id(int id);
	void set_armor(int armor);
	void set_steps(int steps);
	//needed
	void draw(sf::RenderWindow& w, Map& map);
	void spawn(int x, int y, Map& map);
	void death(Map& map);
	void set_color_by_id();
	void check_up_unit();
	void check_steps();
	bool is_enemy_in_enemy_id_list(std::vector<Unit> enemies_id);
	void animation_of_attack(int value, sf::RenderWindow& w, Map& map);
	void move_right_hidden(Map& map, int mouse_x = 0, int mouse_y = 0);
	void move_left_hidden(Map& map, int mouse_x = 0, int mouse_y = 0);
	void move_down_hidden(Map& map, int mouse_x = 0, int mouse_y = 0);
	void move_top_hidden(Map& map, int mouse_x = 0, int mouse_y = 0);
	//TO SAVE
	std::string get_save_unit_info();

	//find
	void del_by_position_in_vector(std::vector<Unit>& units);
	int find_index_of_enemy(int mouse_x, int mouse_y, Map& map);
	~Unit();
};