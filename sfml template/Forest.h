#pragma once
#include "Terrain.h"
#include "Game.h"

class Forest :public Terrain {
private:
	Game game;
public:
	Forest();
	Forest(int res);

	//void draw(sf::RenderWindow& w);
};

