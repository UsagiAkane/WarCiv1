#include "Unit.h"

Unit::Unit(std::string name, int health, int armor, int damage, int speed, unsigned short rank, int salary, int productionPrice, int price, int index, int PlayerID)
{
	
	this->name = name;
	this->health = health;
	this->armor = armor;
	this->damage = damage;
	this->speed = speed;
	this->rank = 0;
	this->salary = salary;
	this->productionPrice = productionPrice;
	this->price = price;
	this->index = index;
	this->playerID = PlayerID;
	this->isActive = true;
	this->count_of_kill = 0;
	this->isAlive = 1;
	this->positionX = 0;
	this->positionY = 0;
}

void Unit::move(int mouse_x, int mouse_y)
{
	if (mouse_x >= this->positionX)
		positionX += 32;
	else if (mouse_x <= this->positionX)
		positionX -= 32;

}

void Unit::attack(Unit& uEnemy, Terrain t)
{
	//damage to attacker
	this->health -= (uEnemy.getDamage() + uEnemy.getRank()) - (this->armor + t.getDefense());
	//damage to attacked unit
	uEnemy.health -= (getDamage() + getRank()) - (uEnemy.armor + t.getDefense());
	//debug
	std::cout << getIsAlive();
	std::cout << uEnemy.getIsAlive();
}

void Unit::attackTake()
{
}

void Unit::skipTurn()
{
	this->isActive = false;
}

void Unit::burrow()
{
	this->isActive = false;
}

bool Unit::getIsAlive()
{
	if (health <= 0)
	{
		isAlive = false;
		return false;
	}
	else
		return true;

}

bool Unit::getIsActive()
{
	return this->isActive;
}

void Unit::wait()
{
	this->isActive = false;
}

int Unit::getDamage()
{
	return this->damage;
}

int Unit::getHealth()
{
	return this->health;
}

int Unit::getArmor()
{
	return this->armor;
}

int Unit::getRank()
{
	return this->rank;
}

void Unit::setDamage(int damage)
{
	this->damage = damage;
}

void Unit::setHealth(int health)
{
	this->health = health;
}

void Unit::setRank(int rank)
{
	this->rank = rank;
}

void Unit::setCountOfKill(unsigned int countOfKill)
{
	this->count_of_kill = countOfKill;
}

void Unit::setActive(bool active)
{
	this->isActive = active;
}

Unit::~Unit()
{
}
