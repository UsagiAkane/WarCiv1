#include "Actor.h"

Actor::Actor(std::string name, Map& map) {
	playerID = 1;
	this->name = name;
	this->enemyListID.push_back(2);//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG

	//std::vector<std::vector<bool>> fog;
	this->goldPerTurn = 0;
	this->sciencePerTurn = 0;
	this->prodactionPerTurn = 0;
	this->totalGold = 0;
	this->totalScience = 0;
	this->totalProdaction = 0;
	this->unitController = 0;
}

void Actor::__PUSH_UNIT_DEBUG(Unit *unit)
{
	this->units.push_back(*unit);
}

void Actor::takeControl(sf::Event event, Map& map, sf::RenderWindow& w, std::vector<Unit>& EnemyUnitVector) {
	//UNIT-MOVE----------
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (event.MouseButtonReleased) {
			if (this->units.size() > 0) {
				if (this->units.at(this->unitController).getIsAlive() == true)
					this->units.at(this->unitController).move(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y, map, this->enemyListID, EnemyUnitVector, w);
				else {
					this->units.erase(unitController + this->units.begin());
					this->unitController = 0;
				}
			}
		}
	}
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
			//UNIT-TARGET--------
		case sf::Keyboard::Right:
			unitController++;
			if (unitController >= this->units.size())
				unitController = 0;
			break;
			//CREATE-TOWN--------
		case sf::Keyboard::W:
			if (this->units.at(unitController).getIsAlive() == true) {
				if (this->units.at(unitController).getIndex() == 1) {
					if (map.getUnitInd(this->units.at(unitController).getPositionX(), this->units.at(unitController).getPositionY()) % 100 / 10 == 0) {
						Town* town = new Town(this->units.at(unitController).getPositionX(), this->units.at(unitController).getPositionY());
						town->spawn(this->units.at(unitController).getPositionX(), this->units.at(unitController).getPositionY(), map);
						this->towns.push_back(*town);
						this->units.at(unitController).death(map);
						this->units.erase(unitController + this->units.begin());
					}
					else std::cout << "<error> this tile already has town\n";
				}
			}
			break;
		case sf::Keyboard::S:
			this->towns.at(0).createUnit(map, 1, this->units);
			break;
		case sf::Keyboard::Enter:
			std::cout << "Enter" << std::endl;
			endOfTurn();
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
		this->totalGold+=i.getGoldIncome();
		this->totalProdaction += i.getProduction();
		this->totalScience += i.getScience();
	}
}

void Actor::pushbackEnemyID(int ID)
{
	this->enemyListID.push_back(ID);
}

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

int Actor::getGoldPerTurn()
{
	return this->goldPerTurn;
}

int Actor::getSciencePerTurn()
{
	return this->sciencePerTurn;
}

int Actor::getProdactionPerTurn()
{
	return this->prodactionPerTurn;
}

int Actor::getTotalGold()
{
	return this->totalGold;
}

int Actor::getTotalScience()
{
	return this->totalScience;
}

int Actor::getTotalProdaction()
{
	return this->totalProdaction;
}

void Actor::setPlayerID(int playerID)
{
	this->playerID = playerID;
}

void Actor::setGoldPerTurn(int goldPerTurn)
{
	this->goldPerTurn = goldPerTurn;
}

void Actor::setSciencePerTurn(int sciencePerTurn)
{
	this->sciencePerTurn = sciencePerTurn;
}

void Actor::setProdactionPerTurn(int prodactionPerTurn)
{
	this->prodactionPerTurn = prodactionPerTurn;
}

void Actor::setTotalGold(int totalGold)
{
	this->totalGold = totalGold;
}

void Actor::setTotalScience(int totalScience)
{
	this->totalScience = totalScience;
}

void Actor::setTotalProdaction(int totalProdaction)
{
	this->totalProdaction = totalProdaction;
}

void Actor::endOfTurn()
{
	for (int i = 0; i < units.size(); i++)
	{
		units.at(i).recharge();
	}
}
