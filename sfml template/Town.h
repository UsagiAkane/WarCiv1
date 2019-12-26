#pragma once
#include <SFML/Graphics.hpp>
#include "Resourses.h"
#include <vector>
#include <string>
#include "Map.h"

class Town {
private:
	std::string name;
	//std::vector<Building>buildings;
	//std::vector<Disasters>disasters;
	int health;
	int armor;
	int production;
	int goldIncome;
	int food;
	int foodIncome;
	int population;
	int happines;
	int player_id;
	int population_limit;
	int science;
public:
	Town();

	//functions that can be changed
	void attackTake();
	void createUnit(int x, int y, Map& map);
	void createBuilding(int building);
	//getters
	int getHealth();
	int getArmor();
	int getProduction();
	int getGoldIncome();
	int getFood();
	int getFoodIncome();
	int getPopulation();
	int getHappines();
	int getPlayer_id();
	int getPopulation_limit();
	int getScience();
	//setters 
	void setHealth(int health);
	void setArmor(int armor);
	void setProduction(int prod);
	void setgoldIncome(int goldIncome);
	void setFood(int food);
	void setFoodIncome(int foodIncome);
	void setPopulation(int population);
	void setHappines(int happines);
	void setPlayer_id(int player_id);
	void setPopulation_limit(int population_limit);
	void setScience(int science);
	//needed
	void draw(sf::RenderWindow& w);
	void spawn(int x, int y, Map& map);
	void destroy(Map& map);
	void retake(Map& map);
};