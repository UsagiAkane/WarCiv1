#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Town.h"
#include"Unit.h"
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
	int goldPerTurn;
	int sciencePerTurn;
	int prodactionPerTurn;
	int totalGold;
	int totalScience;
	int totalProdaction;
	int unitController;//active Unit
public:
	Actor(std::string name, Map& map);
	//DEBUG---------
	//do not use this function if u are not a proggramer (creator) of this app;
	void __PUSH_UNIT_DEBUG(Unit *unit);
	//--------------
	void takeControl(sf::Event event, Map& map, sf::RenderWindow& w,std::vector<Unit>&EnemyUnitVector);
	void draw(sf::RenderWindow& w);
	void takeTax();
	void pushbackEnemyID(int id);
	//--------GETERS
	int getPlayerID();
	std::vector<int> getEnemyListID();
	std::vector<int> getAlliesListID();
	std::string getName();
	std::vector<Town> getTowns();
	std::vector<Unit>& getUnits();
	std::vector<Technologies> getTech();
	std::vector<Unit>& getUnitsVec();
	//std::vector<std::vector<bool>> getFog;
	int getGoldPerTurn();
	int getSciencePerTurn();
	int getProdactionPerTurn();
	int getTotalGold();
	int getTotalScience();
	int getTotalProdaction();
	//--------SETERS
	void setPlayerID(int playerID);
	void setGoldPerTurn(int goldPerTurn);
	void setSciencePerTurn(int sciencePerTurn);
	void setProdactionPerTurn(int prodactionPerTurn);
	void setTotalGold(int totalGold);
	void setTotalScience(int totalScience);
	void setTotalProdaction(int totalProdaction);


	~Actor() {}
};