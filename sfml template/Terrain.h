#pragma once
#include <SFML/Graphics.hpp>
#include "Resourses.h"

class Terrain {
protected:
	sf::Texture texture;
	sf::Sprite sprite;

	int move;
	int food;
	int prodaction;
	int trade;
	double defense;
public:
	virtual sf::Texture getTexture();
	virtual	int getMove();
	virtual	int getFood();
	virtual	int getProdaction();
	virtual	int getTrade();
	virtual	double getDefense();

	virtual void draw(sf::RenderWindow& w) { w.draw(sprite); }
	virtual void setPosition(float x, float y) { sprite.setPosition(x, y); }

};