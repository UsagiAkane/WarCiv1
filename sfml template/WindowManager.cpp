#include "WindowManager.h"
#include "GameManager.h"

void WindowManager::mainWindow() {
	GameManager game;
	try {
		RenderWindow w(VideoMode(1100, 720), "TITLE"/*,Style::Fullscreen*/);

		while (w.isOpen()) {
			Event event;

			while (w.pollEvent(event)) {
				//CLOSE--------------
				if (event.type == event.Closed)
					w.close();
				//Check is mouse in window
				if ((Mouse::getPosition(w).x >= 0 && Mouse::getPosition(w).x < w.getSize().x)&&((Mouse::getPosition(w).y >= 0 && Mouse::getPosition(w).y < w.getSize().y)))
					game.getActors().at(0).takeControl(event, game.getMap(), w, game.findActorUnit(Mouse::getPosition(w).x, Mouse::getPosition(w).y));
			}
			//WINDOW-FILL-COLOR
			w.clear(Color::Black);

			game.draw(w);
			//DISPLAY
			w.display();
		}
	}
	catch (const std::exception & e) {
		std::cout << e.what();
	}
}