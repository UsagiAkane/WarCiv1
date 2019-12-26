#include "Town.h"

int Town::getHealth() {
	return this->health;
}
int Town::getArmor() {
	return this->armor;
}
int Town::getProduction() {
	return this->production;
}
int Town::getGoldIncome() {
	return this->goldIncome;
}
int Town::getFood() {
	return this->food;
}
int Town::getFoodIncome() {
	return this->foodIncome;
}
int Town::getPopulation() {
	return this->population;
}
int Town::getPopulation_limit() {
	return this->population_limit;
}
int Town::getHappines() {
	return this->happines;
}
int Town::getPlayer_id() {
	return this->player_id;
}
int Town::getScience() {
	return this->science;
}

void Town::setHealth(int health){
	this->health = health;
}
void Town::setArmor(int armor){
	this->armor = armor;
}
void Town::setProduction(int prod){
	this->production = production;
}
void Town::setgoldIncome(int goldIncome){
	this->goldIncome = goldIncome;
}
void Town::setFood(int food){
	this->food = food;
}
void Town::setFoodIncome(int foodIncome){
	this->foodIncome = foodIncome;
}
void Town::setPopulation(int population){
	this->population = population;
}
void Town::setHappines(int happines){
	this->happines = happines;
}
void Town::setPlayer_id(int player_id){
	this->player_id = player_id;
}
void Town::setPopulation_limit(int population_limit){
	this->population_limit = population_limit;
}
void Town::setScience(int science){
	this->science = science;
}
