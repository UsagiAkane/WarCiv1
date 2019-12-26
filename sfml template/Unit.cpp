#include "Unit.h"
//Checking whether a unit can attack
void Unit::checkForAttackAndAttackHide(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies)
{
	int time = 0;//trash variable
	for (auto i : enemies_id)//try to find enemy in enemy vector
	{
		if (i == (map.getUnitInd(mouse_x, mouse_y) / 100))//compare id of all playeres and enemies id
		{
			//show to ruslan debug
			for (auto j : enemies)//
			{
				if (j.getIndex() == (map.getUnitInd(mouse_x, mouse_y) % 100))
				{
					attack(enemies.at(time), map, mouse_x, mouse_y);
					break;
				}
				time++;
			}
			break;

		}
	}
}

void Unit::animationOfAttack(int value,sf::RenderWindow & w,Map & map)
{
	if (value == 1)
	{
		
		/*
		warriorSprite.setPosition(positionX, positionY);
		w.draw(warriorSprite);*/
	}
}

Unit::Unit(std::string name, int health, int armor, int damage, int speed, unsigned short rank, int salary, int productionPrice, int price, int index, int PlayerID, int maxspeed)
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
	this->countOfKill = 0;
	this->isAlive = 1;
	this->positionX = 0;
	this->positionY = 0;
}

void Unit::move(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies,sf::RenderWindow & w)
{
	/*if (isActive != 0)
	{*/
		//right
		if (((mouse_x <= this->positionX + BORDER_PIXEL_64 && mouse_x >= this->positionX + BORDER_PIXEL_32) && (mouse_y >= positionY && mouse_y <= this->positionY + BORDER_PIXEL_32)))
		{
			if ((map.getUnitInd(mouse_x, mouse_y)) == 0)
			{
				positionX += BORDER_PIXEL_32;
				this->warriorSprite.setPosition(positionX, positionY);
				this->speed--;
				map.moveUnit(positionX - BORDER_PIXEL_32, positionY, positionX, positionY);
			}
			else if ((map.getUnitInd(mouse_x, mouse_y)) % 100 != 0) //check index of unit
			{
				checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies);   //Checking whether a unit can attack
				animationOfAttack(1, w,map);
			}

		}
		//left
		else if (((mouse_x >= this->positionX - BORDER_PIXEL_32 && mouse_x <= this->positionX) && (mouse_y >= positionY && mouse_y <= this->positionY + BORDER_PIXEL_32)))
		{
			if ((map.getUnitInd(mouse_x, mouse_y)) == 0)
			{
				positionX -= BORDER_PIXEL_32;
				this->warriorSprite.setPosition(positionX, positionY);
				this->speed--;
				map.moveUnit(positionX + BORDER_PIXEL_32, positionY, positionX, positionY);
			}
			else if ((map.getUnitInd(mouse_x, mouse_y)) % 100 != 0)//check index of unit
				checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies); //Checking whether a unit can attack
		}
		//down
		else if ((mouse_y >= positionY - BORDER_PIXEL_32 && mouse_y <= positionY) && (mouse_x >= positionX && mouse_x <= positionX + BORDER_PIXEL_32))
		{
			if ((map.getUnitInd(mouse_x, mouse_y)) == 0)
			{
				positionY -= BORDER_PIXEL_32;
				this->warriorSprite.setPosition(positionX, positionY);
				this->speed--;
				map.moveUnit(positionX, positionY + BORDER_PIXEL_32, positionX, positionY);
			}
			else if ((map.getUnitInd(mouse_x, mouse_y)) % 100 != 0)//check index of unit
				checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies); //Checking whether a unit can attack

		}
		//top
		else if ((mouse_y <= positionY + BORDER_PIXEL_64 && mouse_y >= positionY + BORDER_PIXEL_32) && (mouse_x >= positionX && mouse_x <= positionX + BORDER_PIXEL_32))
		{
			if ((map.getUnitInd(mouse_x, mouse_y)) == 0)
			{
				positionY += BORDER_PIXEL_32;
				this->warriorSprite.setPosition(positionX, positionY);
				this->speed--;
				map.moveUnit(positionX, positionY - BORDER_PIXEL_32, positionX, positionY);
			}
			else if ((map.getUnitInd(mouse_x, mouse_y)) % 100 != 0)//check index of unit
				checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies); //Checking whether a unit can attack
		}
		else {}
		if (speed <= 0)
			this->isActive = false;

	/*}*/
}

void Unit::attack(Unit& uEnemy, Map& map, int x, int y)
{
	
	//damage to attacker
	this->health -= ((uEnemy.getDamage() + uEnemy.getRank()) - (this->armor));
	this->setArmor(this->armor - (uEnemy.getDamage() + uEnemy.getRank()));
	//damage to defender unit
	uEnemy.health -= ((this->getDamage() + this->getRank()) - (uEnemy.getArmor() + map.getTile(x, y).getDefense()));
	uEnemy.setArmor(armor - (this->getDamage() + this->getRank()));


	//debug
	if (this->getHealth() <= 0)
		this->death(map);

	if (uEnemy.getHealth() <= 0)
	{
		uEnemy.death(map);
		this->countOfKill += 1;
	}
		


}

void Unit::skipTurn()
{
	this->isActive = false;
	this->speed -= this->speed;
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
	this->countOfKill = countOfKill;
}

void Unit::setActive(bool active)
{
	this->isActive = active;
}

void Unit::setPosition(int x, int y)
{
	this->positionX = x;
	this->positionY = y;
	this->warriorSprite.setPosition(x, y);
}

void Unit::setPlayerID(int ID)
{
	this->playerID = ID;
}

void Unit::draw(sf::RenderWindow& w)
{
	if (this->isAlive)
		w.draw(this->warriorSprite);

}

void Unit::spawn(int x, int y, Map& map)
{
	this->positionX = x;
	this->positionY = y;
	this->warriorSprite.setPosition(x, y);
	map.pushUnit(x, y, (this->playerID * 100) + this->index);
}

void Unit::death(Map& map)
{
	map.delUnit(positionX, positionY);
	this->isAlive = false;
	this->isActive = false;
	this->max_speed = false;
}

void Unit::setColorByID()
{
	if (this->playerID == 1)
		warriorSprite.setColor(sf::Color(180, 180, 255));//blue
	else if (this->playerID == 2)
		warriorSprite.setColor(sf::Color(255, 180, 180));//red
	else if (this->playerID == 3)
		warriorSprite.setColor(sf::Color(255, 255, 100));//yellow
	else if (this->playerID == 4)
		warriorSprite.setColor(sf::Color(180, 255, 180));//green
	else if (this->playerID == 5)
		warriorSprite.setColor(sf::Color(100, 255, 255));//purple
	else if (this->playerID == 6)
		warriorSprite.setColor(sf::Color(220, 125, 220));//pink
	else if (this->playerID > 6)
		warriorSprite.setColor(sf::Color(50, 50, 50));//dark

}

void Unit::setArmor(int armor)
{
	this->armor = armor;
}

sf::Sprite Unit::getSprite()
{
	return this->warriorSprite;
}

int Unit::getIndex()
{
	return this->index;
}

Unit::~Unit()
{
}
