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

	std::srand(time(NULL));
	Map test(100, 100);

	//enemies units
	Legion l;
	Militia m2enemy;
	std::vector<Unit> unites;
	m2enemy.setPlayerID(2);
	l.spawn(96, 96, test);
	m2enemy.spawn(128, 128, test);
	unites.push_back(l);
	unites.push_back(m2enemy);
	//my
	std::vector<Unit> my;
	std::vector<int> enemiesID;
	Militia m;
	m.setHealth(10);
	m.spawn(192, 192, test);
	enemiesID.push_back(2);
	my.push_back(m);

	//std::cout<<test.getTileVec(1, 1).getMove();


	try {
		RenderWindow w(VideoMode(1100, 720), "TITLE");

		while (w.isOpen()) {
			Event ev;

			while (w.pollEvent(ev)) {



				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					std::for_each(my.begin(), my.end(), [&w, &test, &enemiesID, &unites](Unit& u)
						{u.move(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y, test, enemiesID, unites); });
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