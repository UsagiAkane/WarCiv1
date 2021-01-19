#pragma once
#include <SFML/Graphics.hpp>
#include "Resourses.h"
#include <string>
#include "path.h"

class Terrain {
protected:
	sf::Texture texture_;
	sf::Sprite sprite_;
	std::string name_;
	int move_;
	int food_;
	int production_;
	int trade_;
	int defense_;
public:

	Terrain();

	sf::Texture get_texture();
	std::string get_name();
	int get_move();
	int get_food();
	int get_production();
	int get_trade();
	int get_defense();
	bool is_water();

	void __getInfo_DEBUG();
	void get_info(sf::RenderWindow& w);
	virtual void draw(sf::RenderWindow& w);
	virtual void set_position(float x, float y) { sprite_.setPosition(x, y); }
};