#include "Town.h"


Town::Town(int positionX, int positionY,std::string name) {

	this->texture.loadFromFile("Icons\\Town.png");
	this->townSprite.setTexture(texture);
	this->positionX = positionX;
	this->positionY = positionY;
	this->townSprite.setPosition(positionX, positionY);
	this->name = name;
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
	this->playerID = 1;//debug
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
		settlers->setPlayerID(this->playerID);
		settlers->setColorByID();
		actor.push_back(*settlers);
		break;
	case 2:
		if (map.getUnitInd(positionX, positionY) % 10 == 0)
			militia->spawn(positionX, positionY, map);
		militia->setPlayerID(this->playerID);
		militia->setColorByID();
		actor.push_back(*militia);
		break;
	case 3:
		if (map.getUnitInd(positionX, positionY) % 10 == 0)
			legion->spawn(positionX, positionY, map);
		else {
			std::cout << "<error> no space under the town;\n";
		}
		legion->setPlayerID(this->playerID);
		legion->setColorByID();
		actor.push_back(*legion);
		break;
	case 4:
		if (map.getUnitInd(positionX, positionY) % 10 == 0)
			cavalry->spawn(positionX, positionY, map);
		cavalry->setPlayerID(this->playerID);
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

void Town::setColorByID()
{
	if (this->playerID == 1)
		townSprite.setColor(sf::Color(180, 180, 255));//blue
	else if (this->playerID == 2)
		townSprite.setColor(sf::Color(255, 180, 180));//red
	else if (this->playerID == 3)
		townSprite.setColor(sf::Color(255, 255, 100));//yellow
	else if (this->playerID == 4)
		townSprite.setColor(sf::Color(180, 255, 180));//green
	else if (this->playerID == 5)
		townSprite.setColor(sf::Color(100, 255, 255));//purple
	else if (this->playerID == 6)
		townSprite.setColor(sf::Color(220, 125, 220));//pink
	else if (this->playerID > 6)
		townSprite.setColor(sf::Color(50, 50, 50));//dark
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
	return this->playerID;
}
int Town::getScience() {
	return this->science;
}
std::string Town::getName() {
	return this->name;
}
//SETTERS
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
	this->playerID = player_id;
}
void Town::setPopulation_limit(int population_limit) {
	this->population_limit = population_limit;
}
void Town::setScience(int science) {
	this->science = science;
}
void Town::setName(std::string name) {
	this->name = name;
}
//OTHER
void Town::draw(sf::RenderWindow& w) {
	w.draw(this->townSprite);
}

void Town::spawn(int x, int y, Map& map) {
	map.pushUnit(x, y, this->playerID * 100 + 50);
	setColorByID();
}
