#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Technologies.h"

class Building {
protected:
	std::string name_;
	sf::Sprite sprite_;
	//prices:
	int production_price_;
	int gold_cost_;
	int gold_per_turn_;
	//player info
	int increase_limit_;
	int rank_multiplier_;
	int money_multiplier_;
	int science_multiplier_;
	int increase_hp_;
public:
	Building(std::string, int production_price, int gold_cost, int gold_per_turn,
		int increase_limit, int rank_multi, int money_multi, int science_multi, int increase_hp);
	//getters
	std::string get_name();
	int get_production_price();
	auto get_gold_cost() -> int;
	int get_gold_per_turn();
	int get_increase_limit();
	int get_rank_multiplier();
	auto get_money_multiplier() -> int;
	int get_science_multiplier();
	auto get_increase_hp() -> int;
	auto get_sell_value() -> int;
	//setters
	void set_production_price(int production_price);
	void set_gold_cost(int gold_cost);
	auto set_gold_per_turn(int gold_per_turn) -> void;
	void set_increase_limit(int increase_lim);
	auto set_rank_multiplier(int rank_multiplier) -> void;
	void set_money_multiplier(int money_multiplier);
	void set_science_multiplier(int science_multiplier);
	void set_increase_hp(int increase_hp);
	//methods
	virtual bool isBuildable(std::vector<Technologies> techno);

	//destructor
	~Building();
};
