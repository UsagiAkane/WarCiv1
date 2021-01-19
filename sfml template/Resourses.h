#pragma once
#include <SFML/Graphics.hpp>
#include "path.h"

class Resourses {
protected:
	sf::Texture texture_;
	sf::Sprite sprite_;
public:
	void draw(sf::RenderWindow& w);
	virtual void set_position(float x, float y) { sprite_.setPosition(x, y); }
};