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

	sf::Texture getTexture();
	std::string getName();
	int getMove();
	int getFood();
	int getProdaction();
	int getTrade();
	int getDefense();
	bool isWater();

	void __getInfo_DEBUG();

	virtual void draw(sf::RenderWindow& w) { w.draw(sprite); }
	virtual void setPosition(float x, float y) { sprite.setPosition(x, y); }

};