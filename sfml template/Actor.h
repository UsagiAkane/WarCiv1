#pragma once
#include<iostream>
#include<vector>
#include"Town.h"
#include"Technologies.h"
#include"Settlers.h"

class Actor {
	////WorldStat wStat;
	int playerID;
	std::vector<int> enemyListID;
	std::vector<int> alliesListID;
	std::string name;
	std::vector<Town> towns;
	std::vector<Unit> units;
	std::vector<Technologies> tech;
	//std::vector<std::vector<bool>> fog;
	int totalGold;
	int totalScience;
	int unitController;//active Unit
	int townController;//active Town
public:
	Actor(std::string name, Map& map, int playerID = 1);

	//DEBUG---------

	//do not use this function if u are not a proggramer (creator) of this app;
	void __SHOW_INFO_DEBUG();
	void __PUSH_UNIT_DEBUG(Unit* unit);
	void __PUSH_TOWN_DEBUG(Town* town);
	//--------------
	void takeControl(sf::Event event, Map& map, sf::RenderWindow& w);
	void draw(sf::RenderWindow& w);
	void takeTax();
	void pushbackEnemyID(int id);
	virtual void takeControlUnit(sf::Event event, Map& map, sf::RenderWindow& w, std::vector<Unit>& EnemyUnitVector);
	//--------GETERS
	std::vector<int> getEnemyListID();
	std::vector<int> getAlliesListID();
	std::string getName();
	std::vector<Town> getTowns();
	std::vector<Unit>& getUnits();
	std::vector<Technologies> getTech();
	std::vector<Unit>& getUnitsVec();
	//std::vector<std::vector<bool>> getFog;
	int getPlayerID();
	int getTotalGold();
	int getTotalScience();
	//--------SETERS
	void setPlayerID(int playerID);
	void setTotalGold(int totalGold);
	void setTotalScience(int totalScience);
	void setUnitVector(std::vector<Unit>units);


	//Methods
	virtual void endOfTurn(Map& map);//need work
	virtual void saveUnits();
	virtual void saveTowns();
	virtual std::string getSaveActorInfo();
	virtual void saveActorInfo();
	virtual void saveTotalnfo();




	~Actor() {}
};