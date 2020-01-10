#pragma once
#include"Actor.h"
#include"Map.h"
#include"Ui.h"

class GameManager
{
private:
	Ui ui;
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
	Actor& findActor(int ID); // find and return vector by ID
	std::vector<Unit>& findActorUnit(int mouse_x,int mouse_y);//get mouse position and return vector of units of actor
	void saveGame();
	void loadGame();
	void deleteAllActors();

};

