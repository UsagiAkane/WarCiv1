#pragma once
#include <iostream>//debug
#include "Terrain.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Map.h"
#include <Windows.h>

#define BORDER_PIXEL_32 32
#define BORDER_PIXEL_16 16
#define BORDER_PIXEL_64 64

class Unit
{
protected:
	//general stat
	sf::Sprite warriorSprite;
	sf::Texture texture;
	std::string name;
	int health;
	int armor;
	int damage;
	int speed;
	int max_speed;
	unsigned short rank;
	unsigned int countOfKill;
	//cost
	int salary; //per turn
	int productionPrice;
	int price; //gold price
	//info for player
	int index; //index of unit, for example 1 = settlers
	int playerID; //this variable will show who the unit serves
	int positionX, positionY;
	//variable to know state of unit
	bool isActive;
	bool isAlive;
	//functions to call inside
	void checkForAttackAndAttackHide(int mouse_x, int mouse_y, Map& map, std::vector<int> &enemies_id, std::vector<Unit> &enemies, sf::RenderWindow& w, int direction);
	void animationOfAttack(int value,sf::RenderWindow& w,Map& map);
	void moveRightHidden(Map& map);
	void moveLeftHidden(Map& map);
	void moveDownHidden(Map& map);
	void moveTopHidden(Map& map);

public:
	//constuctor
	Unit(std::string name,int health,int armor,int damage,int speed,
		unsigned short rank,int salary,int productionPrice,int price,
		int index,int PlayerID,int maxspeed);

	//functions that can be changed
	virtual void move(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies, sf::RenderWindow& w);
	virtual void attack(Unit& u, Map& map,int x,int y);
	//functions ,that can be used by pressed key
	void skipTurn();
	void burrow();
	void wait();
	//getters
	int getDamage();
	int getHealth();
	int getArmor();
	int getRank();
	bool getIsAlive();
	bool getIsActive();
	sf::Sprite getSprite();
	int getIndex();
	int getPositionX();
	int getPositionY();
	std::string getName();
	//setters 
	void setDamage(int damage);
	void setHealth(int health);
	void setRank(int rank);
	void setCountOfKill(unsigned int countOfKill);
	void setActive(bool active);
	void setPosition(int x, int y);
	void setPlayerID(int ID);
	void setArmor(int armor);
	//needed
	void draw(sf::RenderWindow& w);
	void spawn(int x,int y, Map& map);
	void death(Map& map);
	void setColorByID();
	//find
    void delByPositionInVector(std::vector<Unit>&units);
	//virtual void createTown(std::vector<Town>& towns,Map & map);



	~Unit();
	

};

