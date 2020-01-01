#pragma once
#include"Actor.h"
#include"Map.h"

class GameManager
{
private:
	std::vector<Actor> actors;
	Map map;
public:
	GameManager();

	Map& getMap();
	std::vector<Actor>& getActors();

	void draw(sf::RenderWindow&w);
	Actor& findActor(int ID);
	std::vector<Unit>& findActorUnit(int mouse_x,int mouse_y,int unit_pos_x,int unit_pos_y);

};

