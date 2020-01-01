#pragma once
#include <iostream>//debug
#include "Terrain.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Map.h"
#include <Windows.h>


#define BORDER_PIXEL_16 16
#define BORDER_PIXEL_60 60
#define BORDER_PIXEL_30 30
#define BORDER_PIXEL_32 32


class Unit
{
protected:
	//general stat
	sf::Sprite warriorSprite;
	std::string name;
	int health;
	int armor;
	int damage;
	int steps;
	int maxSteps;
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
	void moveRightHidden(Map& map, int mouse_x, int mouse_y);
	void moveLeftHidden(Map& map, int mouse_x, int mouse_y);
	void moveDownHidden(Map& map, int mouse_x, int mouse_y);
	void moveTopHidden(Map& map, int mouse_x, int mouse_y);

public:
	//constuctor
	Unit(std::string name,int health,int armor,int damage,int speed,
		unsigned short rank,int salary,int productionPrice,int price,
		int index,int PlayerID,int maxspeed);

	//functions that can be changed
	virtual void move(int mouse_x, int mouse_y, Map& map, std::vector<int>& enemies_id, std::vector<Unit>& enemies, sf::RenderWindow& w);
	virtual void attack(Unit& u, Map& map,int x,int y);
	virtual void recharge();
	
	
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
	int getPlayerId();
	int getMaxSpeed();
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
	void checkUpUnit();
	void checkSteps();
	//find
    void delByPositionInVector(std::vector<Unit>&units);

	~Unit();
	

};

