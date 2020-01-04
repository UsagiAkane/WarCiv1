#include "WindowManager.h"
#include "GameManager.h"

void WindowManager::mainWindow() {
	GameManager game;
	try {
		sf::RenderWindow w(sf::VideoMode(1000, 600), "TITLE", sf::Style::Fullscreen);
		w.setFramerateLimit(60);

		sf::View view(w.getView());

		while (w.isOpen()) {
			sf::Event event;

			while (w.pollEvent(event)) {
				//CLOSE--------------
				if (event.type == event.Closed)
					w.close();
				//Check is mouse in window
				if ((sf::Mouse::getPosition(w).x >= 0 && sf::Mouse::getPosition(w).x < static_cast<int>(w.getSize().x)) && ((sf::Mouse::getPosition(w).y >= 0 && sf::Mouse::getPosition(w).y < static_cast<int>(w.getSize().y))))
					game.getActors().at(0).takeControl(event, game.getMap(), w, game.findActorUnit(sf::Mouse::getPosition(w).x + (w.getView().getCenter().x - w.getSize().x / 2), sf::Mouse::getPosition(w).y + (w.getView().getCenter().y - w.getSize().y / 2)));
				
				
					if (sf::Mouse::getPosition(w).x >= static_cast<int>(w.getSize().x) - BORDER_PIXEL_32)
						view.move(BORDER_PIXEL_32 / 6, 0);
					if (sf::Mouse::getPosition(w).x <= BORDER_PIXEL_32)
						view.move(-BORDER_PIXEL_32 / 6, 0);
					if (sf::Mouse::getPosition(w).y <= BORDER_PIXEL_32)
						view.move(0, -BORDER_PIXEL_32 / 6);
					if (sf::Mouse::getPosition(w).y >= static_cast<int>(w.getSize().y) - BORDER_PIXEL_32)
						view.move(0, BORDER_PIXEL_32 / 6);
				
	

				////////////////////////////////////DON'T USE THIS////////////////////////////
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