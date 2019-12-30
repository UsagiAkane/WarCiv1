#include "Town.h"

Town::Town(int positionX, int positionY) {
	this->texture.loadFromFile("Icons\\Town.png");
	this->TownSprite.setTexture(texture);
	this->positionX = positionX;
	this->positionY = positionY;
	this->TownSprite.setPosition(positionX, positionY);
	this->name = "noName town";
	this->health = 10;
	//armor=0;
	this->damage = 1;
	this->production = 0;
	this->goldIncome = 0;
	this->food = 5;
	this->foodIncome = 0;
	this->population = 1;
	this->population_limit = 10;
	this->happines = 100;
	this->player_id = 1;//debug
	this->science = 0;
	//this->TownSprite.setColor();
}

void Town::createUnit(Map& map, int unit, std::vector<Unit>& actor) {
	Settlers* settlers = new Settlers();
	Militia* militia = new Militia();
	Legion* legion = new Legion();
	Cavalry* cavalry = new Cavalry();
	switch (unit) {
	case 1:
		if (map.getUnitInd(positionX, positionY) % 10 == 0)
			settlers->spawn(positionX, positionY, map);
		settlers->setPlayerID(this->player_id);
		settlers->setColorByID();
		actor.push_back(*settlers);
		break;
	case 2:
		if (map.getUnitInd(positionX, positionY) % 10 == 0)
			militia->spawn(positionX, positionY, map);
		militia->setPlayerID(this->player_id);
		militia->setColorByID();
		actor.push_back(*militia);
		break;
	case 3:
		if (map.getUnitInd(positionX, positionY) % 10 == 0)
			legion->spawn(positionX, positionY, map);
		else {
			std::cout << "<error> no space under the town;\n";
		}
		legion->setPlayerID(this->player_id);
		legion->setColorByID();
		actor.push_back(*legion);
		break;
	case 4:
		if (map.getUnitInd(positionX, positionY) % 10 == 0)
			cavalry->spawn(positionX, positionY, map);
		cavalry->setPlayerID(this->player_id);
		cavalry->setColorByID();
		actor.push_back(*cavalry);
		break;
	}
}

void Town::setPosition(int x, int y)
{
	this->positionX = x;
	this->positionY = y;
}

int Town::getHealth() {
	return this->health;
}
//int Town::getArmor() {
//	return this->armor;
//}
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

std::string Town::getName()
{
	return this->name;
}

void Town::setHealth(int health) {
	this->health = health;
}
//void Town::setArmor(int armor) {
//	this->armor = armor;
//}
void Town::setProduction(int prod) {
	this->production = production;
}
void Town::setgoldIncome(int goldIncome) {
	this->goldIncome = goldIncome;
}
void Town::setFood(int food) {
	this->food = food;
}
void Town::setFoodIncome(int foodIncome) {
	this->foodIncome = foodIncome;
}
void Town::setPopulation(int population) {
	this->population = population;
}
void Town::setHappines(int happines) {
	this->happines = happines;
}
void Town::setPlayer_id(int player_id) {
	this->player_id = player_id;
}
void Town::setPopulation_limit(int population_limit) {
	this->population_limit = population_limit;
}
void Town::setScience(int science) {
	this->science = science;
}

void Town::setName(std::string name)
{
	this->name = name;
}

void Town::draw(sf::RenderWindow& w)
{
	w.draw(this->TownSprite);
}
