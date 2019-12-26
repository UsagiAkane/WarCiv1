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
#include "Legion.h"

using namespace sf;

int main(void) {

	Map test(100, 100);

	Militia m;
	Legion l;
	m.spawn(192,192, test);
	l.spawn(96, 96, test);


	std::srand(time(NULL));

	try {


		RenderWindow w(VideoMode(1100, 720), "TITLE");





		std::cout << "x=1" << ", y=1" << ", def = " << test.getTile(1, 1).getDefense() << ", food = " << test.getTile(1, 1).getFood() << ", move = " << test.getTile(1, 1).getMove() << ", prod = " << test.getTile(1, 1).getProdaction() << ", trade = " << test.getTile(1, 1).getTrade();
		while (w.isOpen()) {
			Event ev;


			bool __keyPressedReleased = 0;
			while (w.pollEvent(ev)) {


				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					m.move(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y, test);


				if (ev.type == Event::Closed)
				{
					w.close();
					std::cout << "HERE12" << std::endl;
				}

			}











			w.clear(Color::Black);


			test.draw(w);
			l.draw(w);
			m.draw(w);


			w.display();
		}


	}
	catch (const std::exception & e) {
		std::cout << e.what();
	}

	return 1;
}