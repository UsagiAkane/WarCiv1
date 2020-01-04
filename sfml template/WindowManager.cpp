#include "WindowManager.h"
#include "GameManager.h"

WindowManager::WindowManager()
{
	
	//this->w.setTitle("WarCiv");
	//this->w.setFramerateLimit(60);

}

void WindowManager::mainWindow() {

	try {
		GameManager game;
		sf::RenderWindow w(sf::VideoMode(1000, 600), "TITLE"/*, sf::Style::Fullscreen*/);
		sf::View view(w.getView());

		while (w.isOpen()) {
			sf::Event event;

			//CAMERA CONTROL
			if (isMouseInWindow(w))
				cameraControl(view, w);
		
			while (w.pollEvent(event)) {
				//CLOSE--------------
				if (event.type == event.Closed)
					w.close();
				//Check is mouse in window
				if (isMouseInWindow(w))
				{
					//all other control
					game.getActors().at(0).takeControl(event, game.getMap(), w);
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))//If you want to attack or move unit
					{
						if (event.MouseButtonReleased)
							game.getActors().at(0).takeControlUnit(event, game.getMap(), w, game.findActorUnit(getPosMouseByWindowX(w), getPosMouseByWindowY(w)));
					}

				}
				//////////////////////////////////DON'T USE THIS////////////////////////////
				/*	if (event.type ==sf::Event::MouseWheelScrolled)
					{
						if (event.mouseWheelScroll.delta > 0)
						{
							view.zoom(0.99f);
						}
						else if (event.mouseWheelScroll.delta < 0)
						{
							view.zoom(1.01f);
						}
					}*/

			}


			w.setView(view);
			//WINDOW-FILL-COLOR
			w.clear(sf::Color::Green);
			//draw all in game
			game.draw(w);
			//DISPLAY
			w.display();
		}
	}
	catch (const std::exception & e) {
		std::cout << e.what();
	}
}

void WindowManager::cameraControl(sf::View& view, sf::Window & w)
{
	if (sf::Mouse::getPosition(w).x >= w.getSize().x - BORDER_PIXEL_32)
		view.move(BORDER_PIXEL_32 / 6, 0);
	if (sf::Mouse::getPosition(w).x <= BORDER_PIXEL_32)
		view.move(-BORDER_PIXEL_32 / 6, 0);
	if (sf::Mouse::getPosition(w).y <= BORDER_PIXEL_32)
		view.move(0, -BORDER_PIXEL_32 / 6);
	if (sf::Mouse::getPosition(w).y >= w.getSize().y - BORDER_PIXEL_32)
		view.move(0, BORDER_PIXEL_32 / 6);
}

bool WindowManager::isMouseInWindow(sf::RenderWindow& w)
{
	return (sf::Mouse::getPosition(w).x >= 0 && sf::Mouse::getPosition(w).x < w.getSize().x) && ((sf::Mouse::getPosition(w).y >= 0 && sf::Mouse::getPosition(w).y < w.getSize().y)) ? true : false;
}

int WindowManager::getPosMouseByWindowX(sf::RenderWindow& w)
{
	return sf::Mouse::getPosition(w).x + (w.getView().getCenter().x - w.getSize().x / 2);
}

int WindowManager::getPosMouseByWindowY(sf::RenderWindow& w)
{
	return  sf::Mouse::getPosition(w).y + (w.getView().getCenter().y - w.getSize().y / 2);
}


