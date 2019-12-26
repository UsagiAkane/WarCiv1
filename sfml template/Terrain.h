#pragma once
#include <SFML/Graphics.hpp>
#include "Resourses.h"
#include <string>

class Terrain {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	std::string name;
	int move;
	int food;
	int prodaction;
	int trade;
	int defense;
public:
	Terrain();

	virtual sf::Texture getTexture();
	virtual	std::string getName();
	virtual	int getMove();
	virtual	int getFood();
	virtual	int getProdaction();
	virtual	int getTrade();
	virtual	int getDefense();

	void __getInfo_DEBUG();

	virtual void draw(sf::RenderWindow& w) { w.draw(sprite); }
	virtual void setPosition(float x, float y) { sprite.setPosition(x, y); }

};