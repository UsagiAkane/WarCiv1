#pragma once

#include <SFML/Graphics.hpp>
#include "Resourses.h"
#include <vector>
#include <string>
#include "Map.h"
#include "Unit.h"
#include "Cavalry.h"
#include "Legion.h"
#include "Militia.h"
#include "Settlers.h"



class Town {
private:
	sf::Sprite townSprite;
	sf::Texture texture;
	std::string name;
	int positionX, positionY;
	//std::vector<Building>buildings;
	//std::vector<Disasters>disasters;
	int health;
	int damage;
	int population;
	int population_limit;
	int production;
	int food;
	int trade;
	int happines;
	int goldIncome;
	int science;
	int playerID;
public:
	Town(int positionX = 0, int positionY = 0, std::string name = "noName town");

	//functions that can be changed
	//void attackTake();
	void createUnit(Map& map, int unit, std::vector<Unit>& actor);
	void createBuilding(int building);
	void setColorByID();
	void spawn(int x, int y, Map& map);
	//getters
	int getPositionX();
	int getPositionY();
	int getHealth();
	int getProduction();
	int getGoldIncome();
	int getFood();
	int getTrade();
	int getPopulation();
	int getHappines();
	int getPlayer_id();
	int getPopulation_limit();
	int getScience();
	std::string getName();
	//setters 
	void setPosition(int x, int y);
	void setHealth(int health);
	void setProduction(int prod);
	void setgoldIncome(int goldIncome);
	void setFood(int food);
	void setTrade(int trade);
	void setPopulation(int population);
	void setHappines(int happines);
	void setPlayer_id(int player_id);
	void setPopulation_limit(int population_limit);
	void setScience(int science);
	void setName(std::string name);
	//needed
	void draw(sf::RenderWindow& w);
	void endOfTurn(Map& map);

	void destroy(Map& map);
	void retake(Map& map);
};