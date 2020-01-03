#pragma once
#include <SFML/Graphics.hpp>
#include "Resourses.h"
#include <vector>
#include <string>
#include <algorithm>
#include "Map.h"
#include "Unit.h"
#include "Cavalry.h"
#include "Legion.h"
#include "Militia.h"
#include "Settlers.h"

#include "Aqueduct.h"
#include "Barracks.h"
#include "CityWalls.h"
#include "Library.h"
#include "Marketplace.h"


class Town {
private:
	sf::Font font;
	sf::Text populationText;
	sf::Sprite townSprite;
	sf::Texture texture;
	std::string name;
	std::vector<Building>buildings;
	//std::vector<Disasters>disasters;
	int positionX, positionY;
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

	//1-Settlers, 2-Militia, 3-Legion, 4-Cavalry
	void createUnit(Map& map, int unit, std::vector<Unit>& actor);
	//1-Aqueduct, 2-Barracks, 3-Walls, 4-Lib, 5-Market
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