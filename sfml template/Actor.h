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
	std::vector<Unit> unites;
	std::vector<Technologies> tech;
	//std::vector<std::vector<bool>> fog;
	int goldPerTurn;
	int sciencePerTurn;
	int prodactionPerTurn;
	int totalGold;
	int totalScience;
	int totalProdaction;
public:
	Actor(std::string name);
	//--------------
	void takeControl(sf::Event event);
	//--------GETERS
	int getPlayerID();
	std::vector<int> getEnemyListID();
	std::vector<int> getAlliesListID();
	std::string getName();
	std::vector<Town> getTowns();
	std::vector<Unit> getUnites();
	std::vector<Technologies> getTech();
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