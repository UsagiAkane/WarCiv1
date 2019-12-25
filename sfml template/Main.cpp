#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Unit.h"
#include "Forest.h"
#include "Grassland.h"
#include "Hills.h"
#include "River.h"
#include "Mountain.h"
#include "Map.h"
#include "CodeofLaws.h"
#include "Militia.h"

using namespace sf;

int main(void) {

	std::srand(time(NULL));

	try {

		RenderWindow w(VideoMode(1920, 1080), "TITLE");
		Militia m;

		Map test(40, 20);

		std::cout << "x=1" << ", y=1" << ", def = " << test.getTile(1, 1).getDefense() << ", food = " << test.getTile(1, 1).getFood() << ", move = " << test.getTile(1, 1).getMove() << ", prod = " << test.getTile(1, 1).getProdaction() << ", trade = " << test.getTile(1, 1).getTrade();
		while (w.isOpen()) {
			Event ev;

			bool __keyPressedReleased = 0;
			while (w.pollEvent(ev)) {
				//if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				//	m.move(ev.mouseButton.x,ev.mouseButton.y);
				if (ev.type == Event::Closed)
					w.close();
				if (ev.key.code == Keyboard::Escape)
					w.close();
			}

			w.clear(Color::Black);


			test.draw(w);



			w.display();
		}
	

	}
	catch (const std::exception & e) {
		std::cout << e.what();
	}

	return 1;
}