#pragma once
#include<iostream>
#include<vector>
#include"Town.h"
#include"Technologies.h"
#include"Settlers.h"
#include "path.h"
#include"Ui.h"

#define BOT_DAMAGE_MOD 4

class Actor {
protected: 
	Ui ui;
	int playerID;
	sf::Sprite target;
	std::vector<int> enemyListID;
	std::vector<int> alliesListID;
	std::string name;
	std::vector<Town> towns;
	std::vector<Unit> units;
	std::vector<Technologies> tech;
	int totalGold;
	int totalScience;
	int unitController;//active Unit
	int townController;//active Town
public:
	Actor(std::string name,int playerID = 1);

	//DEBUG---------

	//do not use this function if u are not a proggramer (creator) of this app;
	void __SHOW_INFO_DEBUG();
	void __PUSH_UNIT_DEBUG(Unit* unit);
	void __PUSH_TOWN_DEBUG(Town* town);
	//--------------
	bool takeControl(sf::Event event, Map& map, sf::RenderWindow& w, int& year);
	void draw(sf::RenderWindow& w, Map& map);
	void takeTax();
	void pushbackEnemyID(int id);

	//--------GETERS
	std::vector<int> getEnemyListID();
	std::vector<int> getAlliesListID();
	std::string getName();
	std::vector<Town> getTowns();
	std::vector<Town>& getTownsLink();
	std::vector<Unit>& getUnits();
	std::vector<Technologies> getTech();
	std::vector<Unit>& getUnitsVec();
	Ui& getUI();
	int getPlayerID();
	int getTotalGold();
	int getTotalScience();
	//--------SETERS
	void setPlayerID(int playerID);
	void setTotalGold(int totalGold);
	void setTotalScience(int totalScience);
	void setUnitVector(std::vector<Unit>units);
	void setUnitTown(std::vector<Town>towns);
	


	//Methods
	virtual void endOfTurn(Map& map);//Give control to bot;
	virtual void saveUnits();
	virtual void saveTowns();
	virtual std::string getSaveActorInfo();
	virtual void saveActorInfo();
	virtual void saveTotalnfo();
	virtual void checkIsEnemy(int mouse_x, int mouse_y, Map& map, std::vector<Unit>& enemies, sf::RenderWindow& w, int direction);
	virtual void unitAttackTown(int mouse_x, int mouse_y,Map& map, std::vector<Town> & townsEnemy, sf::RenderWindow& w, int direction);
	virtual void takeControlUnit(sf::Event event, Map& map, sf::RenderWindow& w, Actor& actorEnemy);
	virtual void endOfTurnBot(Map & map,Actor & eActor);
	virtual void botAttackTown(Map& map, Actor& eActor,int x,int y, int i, int direction);




	~Actor() {}
};