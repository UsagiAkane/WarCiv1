#include "Actor.h"

Actor::Actor(std::string name, Map& map) {
	playerID = 1;
	this->name = name;
	//std::vector<std::vector<bool>> fog;
	this->goldPerTurn = 0;
	this->sciencePerTurn = 0;
	this->prodactionPerTurn = 0;
	this->totalGold = 0;
	this->totalScience = 0;
	this->totalProdaction = 0;
	this->unitController = 0;
	this->townController = 0;
}

void Actor::__PUSH_UNIT_DEBUG(Unit* unit)
{
	this->units.push_back(*unit);
}

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
		case sf::Keyboard::S:
			if (this->towns.size() > 0) {
				//std::cout << "\ntownCon " << this->townController;//debug
				this->towns.at(townController).createUnit(map, 1, this->units);
			}
			break;
		case sf::Keyboard::D:
			if (this->towns.size() > 0) {
				//std::cout << "\ntownCon " << this->townController;//debug
				this->towns.at(townController).createBuilding(1);
			}
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
		this->totalProdaction += i.getProduction();
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

void Actor::endOfTurn(Map& map)
{
	for (int i = 0; i < static_cast<int>(towns.size()); i++) {
		towns[i].endOfTurn(map);
	}
	for (int i = 0; i < static_cast<int>(units.size()); i++) {
		units.at(i).recharge();
	}
}
