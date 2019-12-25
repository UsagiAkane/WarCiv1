#pragma once
#include <SFML/Graphics.hpp>


class Resourses
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	void draw(sf::RenderWindow& w);
	virtual void setPosition(float x, float y) { sprite.setPosition(x, y); }
};