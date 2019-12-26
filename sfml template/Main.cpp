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

	//std::srand(time(NULL));
	Map test(100, 100);
	Militia m;
	Legion l;

	std::vector<Unit> unites;

	unites.push_back(l);

	m.spawn(192, 192, test);
	l.spawn(96, 96, test);

	std::vector<int> enemiesID;
	enemiesID.push_back(2);




	try {


		RenderWindow w(VideoMode(1100, 720), "TITLE");



		while (w.isOpen()) {
			Event ev;


			bool __keyPressedReleased = 0;
			while (w.pollEvent(ev)) {


				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					m.move(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y, test,enemiesID,unites);


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