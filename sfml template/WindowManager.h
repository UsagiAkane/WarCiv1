#pragma once
#include "Actor.h"
#include "GameManager.h"

class WindowManager{
private:
	sf::RenderWindow w;
	bool isMenu = false;//true

public:
	WindowManager();
	//RenderWindow w;
	//WindowManager();
	void newGameWindow();
	void cameraControl(sf::View& view, sf::Window& window);
	bool isMouseInWindow(sf::RenderWindow & w);
	int getPosMouseByWindowX(sf::RenderWindow& w);
	int getPosMouseByWindowY(sf::RenderWindow& w);
	void mainMenu(sf::RenderWindow& w);
	void gameMenu(sf::RenderWindow& w, GameManager& game);

	sf::RenderWindow& getWindow();
	
};

