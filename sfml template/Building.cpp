#include "Building.h"

Building::Building(std::string name, int production_price, int gold_cost, int gold_per_turn, int increase_limit, int rank_multi, int money_multi, int science_multi, int increase_hp) {
	this->name_ = name;
	this->production_price_ = production_price;
	this->gold_cost_ = gold_cost;
	this->gold_per_turn_ = gold_per_turn;
	this->increase_limit_ = increase_limit;
	this->rank_multiplier_ = rank_multi;
	this->money_multiplier_ = money_multi;
	this->science_multiplier_ = science_multi;
	this->increase_hp_ = increase_hp;
}

std::string Building::get_name() {
	return this->name_;
}

int Building::get_production_price() {
	return this->production_price_;
}

int Building::get_gold_cost() {
	return this->gold_cost_;
}

int Building::get_gold_per_turn() {
	return this->gold_per_turn_;
}

int Building::get_increase_limit() {
	return this->increase_limit_;
}

int Building::get_rank_multiplier() {
	return this->rank_multiplier_;
}

int Building::get_money_multiplier() {
	return this->money_multiplier_;
}

int Building::get_science_multiplier() {
	return this->science_multiplier_;
}

int Building::get_increase_hp() {
	return this->increase_hp_;
}

int Building::get_sell_value() {
	return this->gold_cost_ / 4;
}

void Building::set_production_price(int production_price) {
	this->production_price_ = production_price;
}

void Building::set_gold_cost(int gold_cost) {
	this->gold_cost_ = gold_cost;
}

void Building::set_gold_per_turn(int gold_per_turn) {
	this->gold_per_turn_ = gold_per_turn_;
}

void Building::set_increase_limit(int increase_lim) {
	this->increase_limit_ = increase_lim;
}

void Building::set_rank_multiplier(int rank_multiplier) {
	this->rank_multiplier_ = rank_multiplier;
}

void Building::set_money_multiplier(int money_multiplier) {
	this->money_multiplier_ = money_multiplier;
}

void Building::set_science_multiplier(int science_multiplier) {
	this->science_multiplier_ = science_multiplier;
}

void Building::set_increase_hp(int increase_hp) {
	this->increase_hp_ = increase_hp;
}

bool Building::isBuildable(std::vector<Technologies> techno) {
	return true;
}

Building::~Building() {}