#include "Actor.h"

Actor::Actor(std::string name) {
	playerID = 1;
	this->name = name;
	Settlers* baseSettlers = new Settlers;
	this->unites.push_back(*baseSettlers);
	//std::vector<std::vector<bool>> fog;
	this->goldPerTurn = 0;
	this->sciencePerTurn = 0;
	this->prodactionPerTurn = 0;
	this->totalGold = 0;
	this->totalScience = 0;
	this->totalProdaction = 0;

}

void Actor::takeControl(sf::Event event)
{

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

std::vector<Unit> Actor::getUnites()
{
	return this->unites;
}

std::vector<Technologies> Actor::getTech()
{
	return this->tech;
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
