#pragma once
#include"AI.h"
#include"Map.h"


class GameManager
{
private:
	
	std::vector<Actor> actors;
	Map map;
	int currentYear;
public:
	GameManager();

	Map& getMap();
	std::vector<Actor>& getActors();

	void setYear(int year);//set current year
	int& getYear();//return current year
	void draw(sf::RenderWindow&w);
	Actor& findActorHidden(int ID); // find and return vector by ID
	Actor& findActor(int mouse_x,int mouse_y);//get mouse position and return vector of units of actor
	void saveGame();
	void loadGame();
	void deleteAllActors();


};

