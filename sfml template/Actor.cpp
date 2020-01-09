#include "Actor.h"

Actor::Actor(std::string name, Map& map, int playerID) {
	this->playerID = playerID;
	this->name = name;
	//std::vector<std::vector<bool>> fog;
	this->totalGold = 0;
	this->totalScience = 0;
	this->unitController = 0;
	this->townController = 0;
}

void Actor::__SHOW_INFO_DEBUG()
{
	std::cout << this->name << std::endl;
	std::cout << this->playerID << std::endl;
	std::cout << this->totalGold << std::endl;
	std::cout << this->totalScience << std::endl;
	//std::cout << this-> << std::endl;
	//std::cout << this-> << std::endl;
	//std::cout << this-> << std::endl;
	//std::cout << this-> << std::endl;
}

void Actor::__PUSH_UNIT_DEBUG(Unit* unit) { this->units.push_back(*unit); }
void Actor::__PUSH_TOWN_DEBUG(Town* town) { this->towns.push_back(*town); }

void Actor::takeControl(sf::Event event, Map& map, sf::RenderWindow& w) {
	//to make camera dynamic
	int mouse_x = sf::Mouse::getPosition(w).x + (w.getView().getCenter().x - w.getSize().x / 2);
	int mouse_y = sf::Mouse::getPosition(w).y + (w.getView().getCenter().y - w.getSize().y / 2);

	//UNIT-MOVE----------

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		if (event.MouseButtonReleased) {
			if (this->towns.size() > 0) {
				for (int i = 0; i < static_cast<int>(towns.size()); i++) {
					if (this->towns.at(i).getPositionX() == (mouse_x / 32 * 32) && this->towns.at(i).getPositionY() == (mouse_y / 32 * 32)) {
						this->townController = i;
						std::cout << "\ntownCon " << this->townController;//debug
					}
				}
			}
			map.__getInfo_DEBUG(mouse_x, mouse_y);
		}
	}

	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
			//UNIT-TARGET--------
		case sf::Keyboard::Right:
			this->unitController++;
			if (this->unitController >= static_cast<int>(this->units.size()))
				this->unitController = 0;
			break;
			//CREATE-TOWN--------
		case sf::Keyboard::W:
			if (this->units.size() != 0) {
				if (this->units.at(this->unitController).getIsAlive() == true) {
					if (this->units.at(this->unitController).getIndex() == 1) {
						//std::cout << map.getUnitInd(this->units.at(unitController).getPositionX(), this->units.at(unitController).getPositionY()) << std::endl;//debug
						map.getTile(this->units.at(unitController).getPositionX(), this->units.at(unitController).getPositionY()).__getInfo_DEBUG();
						if (map.getUnitInd(this->units.at(this->unitController).getPositionX(), this->units.at(this->unitController).getPositionY()) % 100 / 10 == 0) {
							Town* town = new Town(this->units.at(this->unitController).getPositionX(), this->units.at(this->unitController).getPositionY());
							this->units.at(this->unitController).death(map);
							this->units.erase(this->unitController + this->units.begin());
							town->setPlayer_id(1);
							town->spawn(town->getPositionX(), town->getPositionY(), map);
							this->towns.push_back(*town);
						}
						else std::cout << "<error> this tile already has town\n";
						//std::cout << map.getUnitInd(this->towns.at(0).getPositionX(), this->towns.at(0).getPositionY());//debug
					}
				}
			}
			break;
		case sf::Keyboard::Num1:
			if (this->towns.size() > 0)
				this->towns.at(townController).createUnit(map, 1, this->units);
			break;
		case sf::Keyboard::Num2:
			if (this->towns.size() > 0)
				this->towns.at(townController).createUnit(map, 2, this->units);
			break;
		case sf::Keyboard::Num3:
			if (this->towns.size() > 0)
				this->towns.at(townController).createUnit(map, 3, this->units);
			break;
		case sf::Keyboard::Num4:
			if (this->towns.size() > 0)
				this->towns.at(townController).createUnit(map, 4, this->units);
			break;
		case sf::Keyboard::D:
			if (this->towns.size() > 0)
				this->towns.at(townController).createBuilding(1);
			break;
		case sf::Keyboard::Enter:
			std::cout << "\nTurn ended!" << std::endl;
			endOfTurn(map);
			break;
		}
	}
}

void Actor::draw(sf::RenderWindow& w)
{
	//TOWNS-DRAW
	for (auto i : this->towns) {
		i.draw(w);
	}
	//UNITS-DRAW
	for (auto i : this->units) {
		i.draw(w);
	}
}

void Actor::takeTax()
{
	for (auto i : this->towns) {
		this->totalGold += i.getGoldIncome();
		this->totalScience += i.getScience();
	}
}

void Actor::pushbackEnemyID(int ID)
{
	this->enemyListID.push_back(ID);
}

void Actor::takeControlUnit(sf::Event event, Map& map, sf::RenderWindow& w, std::vector<Unit>& EnemyUnitVector)
{
	if (this->units.size() > 0) {
		if (this->units.at(this->unitController).getIsAlive() == true)
			this->units.at(this->unitController).move(sf::Mouse::getPosition(w).x + (w.getView().getCenter().x - w.getSize().x / 2), sf::Mouse::getPosition(w).y + (w.getView().getCenter().y - w.getSize().y / 2), map, this->enemyListID, EnemyUnitVector, w);
		else {
			this->units.erase(this->unitController + this->units.begin());
			this->unitController = 0;
		}
	}
}

#pragma region GETTERS
int Actor::getPlayerID()
{
	return this->playerID;
}

std::vector<int> Actor::getEnemyListID()
{
	return this->enemyListID;
}

std::vector<int> Actor::getAlliesListID()
{
	return this->alliesListID;
}

std::string Actor::getName()
{
	return this->name;
}

std::vector<Town> Actor::getTowns()
{
	return this->towns;
}

std::vector<Unit>& Actor::getUnits()
{
	return this->units;
}

std::vector<Technologies> Actor::getTech()
{
	return this->tech;
}

std::vector<Unit>& Actor::getUnitsVec()
{
	return this->units;
}

int Actor::getTotalGold()
{
	return this->totalGold;
}

int Actor::getTotalScience()
{
	return this->totalScience;
}

#pragma endregion

#pragma region SETTERS
void Actor::setPlayerID(int playerID)
{
	this->playerID = playerID;
}


void Actor::setTotalGold(int totalGold)
{
	this->totalGold = totalGold;
}

void Actor::setTotalScience(int totalScience)
{
	this->totalScience = totalScience;
}

void Actor::setUnitVector(std::vector<Unit> units)
{
	this->units = units;
}

void Actor::setUnitTown(std::vector<Town> towns)
{
	this->towns = towns;
}

#pragma endregion

void Actor::endOfTurn(Map& map)
{
	for (int i = 0; i < static_cast<int>(towns.size()); i++) {
		towns[i].endOfTurn(map);
	}
	for (int i = 0; i < static_cast<int>(units.size()); i++) {
		units.at(i).recharge();
	}
}

void Actor::saveUnits()
{
	std::string path = "Saves\\Save1.txt";
	std::ofstream fout;
	fout.open(path, std::ofstream::app);
	if (!fout.is_open())
		std::cout << "Error, file wasn't opened" << std::endl;
	else
	{
		for (auto i : units)
		{
			fout << i.getSaveUnitInfo();
		}
		fout << "\n#\n";
	}
	fout.close();
}

void Actor::saveTowns()
{
	std::string path = "Saves\\Save1.txt";
	std::ofstream fout;
	fout.open(path, std::ofstream::app);
	if (!fout.is_open())
		std::cout << "Error, file wasn't opened" << std::endl;
	else
	{
		for (auto i : towns)
		{
			fout << i.getSaveTownInfo();
			fout << "\n*\n";
		}
		fout << "\n&\n";
	}
	fout.close();
}

std::string Actor::getSaveActorInfo()
{
	std::string unitInfo;
	unitInfo += this->name;
	unitInfo += " ";
	unitInfo += std::to_string(this->playerID);
	unitInfo += " ";
	unitInfo += std::to_string(this->totalGold);
	unitInfo += " ";
	unitInfo += std::to_string(this->totalScience);
	unitInfo += "\n_\n";
	return unitInfo;
}

void Actor::saveActorInfo()
{
	std::string path = "Saves\\Save1.txt";
	std::ofstream fout;
	fout.open(path, std::ofstream::app);
	if (!fout.is_open())
		std::cout << "Error, file wasn't opened" << std::endl;
	else
	{
		fout << getSaveActorInfo();
	}

	fout.close();
}

void Actor::saveTotalnfo()
{
	saveActorInfo();
	saveTowns();
	saveUnits();
}
