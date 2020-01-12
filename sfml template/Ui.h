#pragma once
#include<SFML/Graphics.hpp>

class Ui {
private:
	//sf::RectangleShape DownLeftRect;
	//sf::RectangleShape DownRightRect;
	//sf::RectangleShape DownMiddleRect;
	sf::Font font;
	sf::Text tgold;
	sf::Text tsience;
	sf::Text tturn;
	sf::Text tyear;
	sf::Sprite vScrollSprite;
public:
	Ui();

	void resize(sf::RenderWindow& w);
	void draw(sf::RenderWindow& w);
	void setParams(int gold, int sience, int turn, int year);





};
