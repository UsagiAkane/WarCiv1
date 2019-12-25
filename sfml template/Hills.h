#pragma once
#include "Terrain.h"
#include "Coal.h"
#include "Oil.h"

class Hills :public Terrain {
private:
	Coal coal;
	Oil oil;
public:
	Hills();
	Hills(int res);
	//void draw(sf::RenderWindow& w);
};