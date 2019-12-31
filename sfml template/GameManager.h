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

	void draw(sf::RenderWindow&w);

};

