#include "Town.h"

Town::Town(int positionX, int positionY, std::string name) {
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
		//if (this->production > settlers->getProductionPrice()) {
		if (map.getUnitInd(positionX, positionY) % 10 == 0) {
			settlers->setPlayerID(this->playerID);
			settlers->spawn(positionX, positionY, map);
			actor.push_back(*settlers);
		}
		else
			std::cout << "<error> no space under the town;\n";
		//}
		break;
	case 2:
		if (this->production > settlers->getProductionPrice()) {
			if (map.getUnitInd(positionX, positionY) % 10 == 0) {
				militia->setPlayerID(this->playerID);
				militia->spawn(positionX, positionY, map);
				actor.push_back(*militia);
			}
			else
				std::cout << "<error> no space under the town;\n";
		}
		break;
	case 3:
		if (this->production > settlers->getProductionPrice()) {
			if (map.getUnitInd(positionX, positionY) % 10 == 0) {
				legion->setPlayerID(this->playerID);
				legion->spawn(positionX, positionY, map);
				actor.push_back(*legion);
				break;
			}
			else
				std::cout << "<error> no space under the town;\n";
		}
		break;
	case 4:
		if (this->production > settlers->getProductionPrice()) {
			if (map.getUnitInd(positionX, positionY) % 10 == 0) {
				cavalry->setPlayerID(this->playerID);
				cavalry->spawn(positionX, positionY, map);
				actor.push_back(*cavalry);
			}
			else
				std::cout << "<error> no space under the town;\n";
		}
		break;

	}
}
//1-Aqueduct, 2-Barracks, 3-Walls, 4-Lib, 5-Market
void Town::createBuilding(int building) {
	Aqueduct* aqueduct = new Aqueduct();			//1
	Barracks* barracks = new Barracks();			//2
	CityWalls* cityWalls = new CityWalls();			//3
	Library* library = new Library();				//4
	Marketplace* marketplace = new Marketplace();	//5

	switch (building) {
	case 1:
		if (this->production >= aqueduct->getProductionPrice()) {		//PRICE
			if (!static_cast<bool>(std::count_if(buildings.begin(), buildings.end(), [](Building& index) {return index.getName() == "Aqueduct"; }))) {		//HAVE OR NOT
				this->production -= aqueduct->getProductionPrice();
				this->buildings.push_back(*aqueduct);
				std::cout << "\nAqueduct builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		break;
	case 2:
		if (this->production >= barracks->getProductionPrice()) {		//PRICE
			if (!static_cast<bool>(std::count_if(buildings.begin(), buildings.end(), [](Building& index) {return index.getName() == "Barracks"; }))) {		 //HAVE OR NOT
				this->production -= barracks->getProductionPrice();
				this->buildings.push_back(*barracks);
				std::cout << "\nBarracks builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		break;
	case 3:
		if (this->production >= cityWalls->getProductionPrice()) {		//PRICE
			if (!static_cast<bool>(std::count_if(buildings.begin(), buildings.end(), [](Building& index) {return index.getName() == "City Walls"; }))) {	//HAVE OR NOT
				this->production -= cityWalls->getProductionPrice();
				this->buildings.push_back(*cityWalls);
				std::cout << "\nCity Walls builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		break;
	case 4:
		if (this->production >= library->getProductionPrice()) {		//PRICE
			if (!static_cast<bool>(std::count_if(buildings.begin(), buildings.end(), [](Building& index) {return index.getName() == "Library"; }))) { 		//HAVE OR NOT
				this->production -= library->getProductionPrice();
				this->buildings.push_back(*library);
				std::cout << "\nLibrary builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		break;
	case 5:
		if (this->production >= marketplace->getProductionPrice()) {	//PRICE
			if (!static_cast<bool>(std::count_if(buildings.begin(), buildings.end(), [](Building& index) {return index.getName() == "Marketplace"; }))) {	//HAVE OR NOT
				this->production -= marketplace->getProductionPrice();
				this->buildings.push_back(*marketplace);
				std::cout << "\nMarketplace builded.";//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
			}
		}
		break;
	}
}
void Town::setColorByID() {
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
//GETERS
int Town::getHealth() {
	return this->health;
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
int Town::getTrade() {
	return this->trade;
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
int Town::getPositionX() {
	return this->positionX;
}
int Town::getPositionY() {
	return this->positionY;
}
//SETTERS
void Town::setPosition(int x, int y) {
	this->positionX = x;
	this->positionY = y;
}
void Town::setHealth(int health) {
	this->health = health;
}
void Town::setProduction(int prod) {
	this->production = production;
}
void Town::setgoldIncome(int goldIncome) {
	this->goldIncome = goldIncome;
}
void Town::setFood(int food) {
	this->food = food;
}
void Town::setTrade(int trade) {
	this->trade = trade;
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

void Town::endOfTurn(Map& map) {
	//map.getTile(this->positionX, this->positionY).getName();
	this->food += map.getTile(this->positionX, this->positionY).getFood();
	this->production += map.getTile(this->positionX, this->positionY).getProdaction();
	this->trade += map.getTile(this->positionX, this->positionY).getTrade();
	//this->damage = map.getTile(this->positionX, this->positionY).getDefense();
}

void Town::spawn(int x, int y, Map& map) {
	setPosition(x, y);
	map.pushUnit(x, y, this->playerID * 100 + 50);
	setColorByID();
}

