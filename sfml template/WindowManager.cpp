#include "WindowManager.h"
#include "GameManager.h"

void WindowManager::mainWindow() {
	GameManager game;
	try {
		RenderWindow w(VideoMode(1000, 720), "TITLE"/*, Style::Fullscreen*/);
		sf::View view(w.getView());

		while (w.isOpen()) {
			Event event;

			while (w.pollEvent(event)) {
				//CLOSE--------------
				if (event.type == event.Closed)
					w.close();
				//Check is mouse in window
				if ((Mouse::getPosition(w).x >= 0 && Mouse::getPosition(w).x < w.getSize().x) && ((Mouse::getPosition(w).y >= 0 && Mouse::getPosition(w).y < w.getSize().y)))
					game.getActors().at(0).takeControl(event, game.getMap(), w, game.findActorUnit(sf::Mouse::getPosition(w).x + (w.getView().getCenter().x - w.getSize().x / 2), sf::Mouse::getPosition(w).y + (w.getView().getCenter().y - w.getSize().y / 2)));

				
				if (Mouse::getPosition(w).x >= w.getSize().x - BORDER_PIXEL_32)
					view.move(BORDER_PIXEL_32 / 6, 0);
				if (Mouse::getPosition(w).x <= BORDER_PIXEL_32)
					view.move(-BORDER_PIXEL_32 / 6, 0);
				if (Mouse::getPosition(w).y <= BORDER_PIXEL_32)
					view.move(0, -BORDER_PIXEL_32 / 6);
				if (Mouse::getPosition(w).y >= w.getSize().y - BORDER_PIXEL_32)
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
			w.clear(Color::Green);
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