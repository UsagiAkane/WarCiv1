#include "WindowManager.h"
#include "GameManager.h"

void WindowManager::mainWindow(){
	GameManager game;
	try {
		RenderWindow w(VideoMode(1100, 720), "TITLE"/*,Style::Fullscreen*/);

		while (w.isOpen()) {
			Event event;

			while (w.pollEvent(event)) {
				//CLOSE--------------
				if (event.type == event.Closed)
					w.close();
				game.getActors().at(0).takeControl(event,game.getMap(),w, game.getActors().at(1).getUnits());
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