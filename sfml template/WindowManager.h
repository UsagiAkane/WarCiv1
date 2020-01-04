#pragma once
#include "Actor.h"

class WindowManager{
private:
	//sf::RenderWindow w;
public:
	WindowManager();
	//RenderWindow w;
	//WindowManager();
	void mainWindow();
	void cameraControl(sf::View& view, sf::Window& window);
	bool isMouseInWindow(sf::RenderWindow & w);
	int getPosMouseByWindowX(sf::RenderWindow& w);
	int getPosMouseByWindowY(sf::RenderWindow& w);
};

