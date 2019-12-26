#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "Unit.h"
#include "Forest.h"
#include "Grassland.h"
#include "Hills.h"
#include "Mountain.h"
#include "Map.h"
#include "CodeofLaws.h"
#include "Militia.h"
#include "Legion.h"
#include <algorithm>

using namespace sf;

//КОСТЕ СДЕЛАТЬ ДЕЛИТ С КАРТЫ
int main(void) {

	//std::srand(time(NULL));
	Map test(100, 100);
	Militia m;
	Legion l;
	Militia m2enemy;

	std::vector<Unit> unites;

	
	m2enemy.setPlayerID(2);

	m.spawn(192, 192, test);
	l.spawn(96, 96, test);
	m2enemy.spawn(128, 128, test);

	unites.push_back(l);
	unites.push_back(m2enemy);

	std::vector<int> enemiesID;
	enemiesID.push_back(2);

	std::vector<Unit> my;
	my.push_back(m);

	//std::cout<<test.getTileVec(1, 1).getMove();


	try {
		RenderWindow w(VideoMode(1100, 720), "TITLE");

		while (w.isOpen()) {
			Event ev;

			while (w.pollEvent(ev)) {



				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					m.move(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y, test, enemiesID, unites);
					test.getTile(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y).__getInfo_DEBUG();
				}

				if (ev.type == Event::Closed)
					w.close();


			}
			w.clear(Color::Black);

		
			test.draw(w);

			for (auto i : unites)
			{
				i.draw(w);
			}
			for (auto i: my)
			{
				i.draw(w);
			}
	


			w.display();
		}


	}
	catch (const std::exception & e) {
		std::cout << e.what();
	}

	return 1;
}