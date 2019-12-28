#include "Unit.h"
//Checking whether a unit can attack
void Unit::checkForAttackAndAttackHide(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies, sf::RenderWindow& w,int direction)
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
					animationOfAttack(direction, w, map);
					break;
				}
				time++;
			}
			break;

		}
	}
}

void Unit::animationOfAttack(int value, sf::RenderWindow& w, Map& map)
{
	sf::Texture textureTMP;
	textureTMP.loadFromFile("Icons\\swordicon.png");
	sf::Sprite tmp(textureTMP);
	sf::Texture textureTMPs;
	textureTMPs.loadFromFile("Icons\\shieldicon.png");
	sf::Sprite tmps(textureTMPs);
	//right
	if (value == 1)
	{
		tmp.setPosition(positionX+10, positionY);
		tmp.setScale(0.9, 0.9);
		tmps.setScale(0.7, 0.7);
		tmps.setPosition(positionX+30, positionY+3);
	}
	//left
	else if (value == 2)
	{
		textureTMP.loadFromFile("Icons\\swordiconflip.png");
		tmp.setPosition(positionX - 10, positionY);
		tmp.setScale(0.9, 0.9);
		tmps.setScale(0.7, 0.7);
		tmps.setPosition(positionX - 20, positionY +3);
	}
	//top
	else if (value == 3)
	{
		tmp.setPosition(positionX , positionY-10);
		tmp.setScale(0.9, 0.9);
		tmps.setScale(0.7, 0.7);
		tmps.setPosition(positionX+6, positionY -20);
	}
	//down
	else if (value == 4)
	{
		textureTMP.loadFromFile("Icons\\swordiconflipdown.png");
		tmp.setPosition(positionX, positionY + 10);
		tmp.setScale(0.9, 0.9);
		tmps.setScale(0.7, 0.7);
		tmps.setPosition(positionX + 9, positionY + 30);
	}

	w.draw(warriorSprite);
	w.draw(tmps);
	w.draw(tmp);
	w.display();
	Sleep(600);
}

void Unit::moveRightHidden(Map & map)
{
	positionX += BORDER_PIXEL_32;
	this->warriorSprite.setPosition(positionX, positionY);
	this->speed--;
	map.moveUnit(positionX - BORDER_PIXEL_32, positionY, positionX, positionY);
}

void Unit::moveLeftHidden(Map& map)
{
	positionX -= BORDER_PIXEL_32;
	this->warriorSprite.setPosition(positionX, positionY);
	this->speed--;
	map.moveUnit(positionX + BORDER_PIXEL_32, positionY, positionX, positionY);
}

void Unit::moveDownHidden(Map& map)
{
	positionY += BORDER_PIXEL_32;
	this->warriorSprite.setPosition(positionX, positionY);
	this->speed--;
	map.moveUnit(positionX, positionY - BORDER_PIXEL_32, positionX, positionY);
}

void Unit::moveTopHidden(Map& map)
{
	positionY -= BORDER_PIXEL_32;
	this->warriorSprite.setPosition(positionX, positionY);
	this->speed--;
	map.moveUnit(positionX, positionY + BORDER_PIXEL_32, positionX, positionY);
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

void Unit::move(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies, sf::RenderWindow& w)
{
	/*if (isActive != 0)
	{*/
	////right
	if (((mouse_x <= this->positionX + BORDER_PIXEL_64 && mouse_x >= this->positionX + BORDER_PIXEL_32) && (mouse_y >= positionY && mouse_y <= this->positionY + BORDER_PIXEL_32)))//check position of mouse
	{
		if ((map.getUnitInd(mouse_x, mouse_y)) == 0)//check is tile empty
			moveRightHidden(map);
		else if ((map.getUnitInd(mouse_x, mouse_y)) % 100 != 0) //check index of unit
			checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies, w,1);   //Checking whether a unit can attack

	}
	////left
	else if (((mouse_x >= this->positionX - BORDER_PIXEL_32 && mouse_x <= this->positionX) && (mouse_y >= positionY && mouse_y <= this->positionY + BORDER_PIXEL_32)))//check position of mouse
	{
		if ((map.getUnitInd(mouse_x, mouse_y)) == 0)//check is tile empty
			moveLeftHidden(map);
		else if ((map.getUnitInd(mouse_x, mouse_y)) % 100 != 0)//check index of unit
			checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies,w,2); //Checking whether a unit can attack
	}
	////top
	else if ((mouse_y >= positionY - BORDER_PIXEL_32 && mouse_y <= positionY) && (mouse_x >= positionX && mouse_x <= positionX + BORDER_PIXEL_32))//check position of mouse
	{
		if ((map.getUnitInd(mouse_x, mouse_y)) == 0)//check is tile empty
			moveTopHidden(map);
		else if ((map.getUnitInd(mouse_x, mouse_y)) % 100 != 0)//check index of unit
			checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies, w,3); //Checking whether a unit can attack

	}
	////down
	else if ((mouse_y <= positionY + BORDER_PIXEL_64 && mouse_y >= positionY + BORDER_PIXEL_32) && (mouse_x >= positionX && mouse_x <= positionX + BORDER_PIXEL_32))//check position of mouse
	{
		if ((map.getUnitInd(mouse_x, mouse_y)) == 0)//check is tile empty
			moveDownHidden(map);
		else if ((map.getUnitInd(mouse_x, mouse_y)) % 100 != 0)//check index of unit
			checkForAttackAndAttackHide(mouse_x, mouse_y, map, enemies_id, enemies, w,4); //Checking whether a unit can attack
	}
	if (speed <= 0)
		this->isActive = false;

	//}
}

void Unit::attack(Unit& uEnemy, Map& map, int x, int y)
{

	//damage to attacker
	this->health -= ((uEnemy.getDamage() + uEnemy.getRank()) - (this->armor));
	this->setArmor(this->armor - (uEnemy.getDamage() + uEnemy.getRank()));
	//damage to defender unit
	uEnemy.health -= ((this->getDamage() + this->getRank()) - (uEnemy.getArmor() + map.getTile(x, y).getDefense()));
	uEnemy.setArmor(armor - (this->getDamage() + this->getRank()));

	if (this->getHealth() <= 0)
	{
		this->death(map);
	}
		

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
	this->isAlive = false;
	this->isActive = false;
	this->max_speed = 0;
	map.delUnit(positionX, positionY);


	//to del from vector

	/*for (auto i = my.begin(); i < my.end(); i++)
{
	if ((*i).getSprite().getPosition().x == this->warriorSprite.getPosition().x && (*i).getSprite().getPosition().y == this->warriorSprite.getPosition().y)
	{

	}
}*/


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

int Unit::getPositionInVector(std::vector<Unit> &units, int positionX, int positionY)
{
	int tmp=0;
	std::for_each(units.begin(), units.end(), [&tmp, &positionX, &positionY](Unit& u)
		{ if (u.getSprite().getPosition().x == positionX && u.getSprite().getPosition().y == positionY) return tmp;
		else tmp++; });
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
