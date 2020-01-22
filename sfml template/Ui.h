#pragma once
#include<SFML/Graphics.hpp>

#define LOGS_COUNT 10

class Ui {
private:
	sf::Font font;
	sf::Text tgold;
	sf::Text tsience;
	sf::Text tturn;
	sf::Text tyear;
	std::vector<sf::Text> gLog;
	sf::Sprite vScrollSprite;
	int lastChangedLog;
public:
	bool isLog = false;


	void changeLog(std::string& str,bool clean=false);
	Ui();
	void gameLog(sf::RenderWindow& w);
	void resize(sf::RenderWindow& w);
	void draw(sf::RenderWindow& w);
	void setParams(int gold, int sience, int turn, int year);
	void clearLogs();





};
