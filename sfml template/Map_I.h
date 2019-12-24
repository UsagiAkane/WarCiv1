#pragma once
#include<SFML/Graphics.hpp>
class Map_I
{
	//<< Interface >>

	virtual void loadMap() = 0;
	virtual void saveMap() = 0;
	virtual void getTyle() = 0;
	virtual void showInfo() = 0;
	virtual void openSpace() = 0;
	virtual void draw(sf::RenderWindow& w) = 0;
};

