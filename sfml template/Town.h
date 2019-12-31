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
	//int armor;
	int damage;
	int production;
	int goldIncome;
	int food;
	int foodIncome;
	int population;
	int happines;
	int playerID;
	int population_limit;
	int science;
public:
	Town(int positionX = 0, int positionY = 0, std::string name = "noName town");

	//functions that can be changed
	//void attackTake();
	void createUnit(Map& map, int unit, std::vector<Unit>& actor);
	void createBuilding(int building);
	void setPosition(int x, int y);
	void setColorByID();
	void spawn(int x, int y, Map& map);
	//getters
	int getHealth();
	//int getArmor();
	int getProduction();
	int getGoldIncome();
	int getFood();
	int getFoodIncome();
	int getPopulation();
	int getHappines();
	int getPlayer_id();
	int getPopulation_limit();
	int getScience();
	std::string getName();
	//setters 
	void setHealth(int health);
	//void setArmor(int armor);
	void setProduction(int prod);
	void setgoldIncome(int goldIncome);
	void setFood(int food);
	void setFoodIncome(int foodIncome);
	void setPopulation(int population);
	void setHappines(int happines);
	void setPlayer_id(int player_id);
	void setPopulation_limit(int population_limit);
	void setScience(int science);
	void setName(std::string name);
	//needed
	void draw(sf::RenderWindow& w);

	void destroy(Map& map);
	void retake(Map& map);
};