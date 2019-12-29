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
#include "Cavalry.h"
#include "Settlers.h"

using namespace sf;

int main(void) {

	std::srand(time(NULL));
	Map test(100, 100);

	////////////////////////////CREATING UNITS
	//enemies units
	Legion l;
	Militia m2enemy;
	std::vector<Unit> unites;
	m2enemy.setPlayerID(2);
	l.spawn(96, 96, test);
	l.setColorByID();
	m2enemy.setColorByID();

	m2enemy.spawn(128, 128, test);
	unites.push_back(l);
	unites.push_back(m2enemy);
	//my
	std::vector<Unit> my;
	std::vector<int> enemiesID;
	Militia m;
	Militia s;
	m.setHealth(1);
	m.spawn(192, 192, test);
	s.spawn(224, 192, test);
	m.setColorByID();
	s.setColorByID();

	enemiesID.push_back(2);
	my.push_back(m);
	my.push_back(s);

	int what_unit = 0;
	Cavalry cavalry;
	cavalry.spawn(0, 0, test);

	Settlers settlers;
	settlers.spawn(256, 256, test);
	settlers.setPlayerID(1);
	settlers.setColorByID();
	my.push_back(settlers);

   //////TEST///////////////////



	try {
		RenderWindow w(VideoMode(1100, 720), "TITLE");

		while (w.isOpen()) {
			Event ev;

			while (w.pollEvent(ev)) {


				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

					////////////////////////////MOVE TARGET UNIT
					if (ev.MouseButtonReleased)
					{
						if (my.size() > 0)
						{
							if (my.at(what_unit).getIsAlive() == true)
								my.at(what_unit).move(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y, test, enemiesID, unites, w);
							else
							{
								my.erase(what_unit + my.begin());
								what_unit = 0;
							}
						}
					}
				}

				if (ev.type == ev.Closed)
					w.close();


				if (ev.type == sf::Event::KeyPressed)
				{
					switch (ev.key.code)
					{
					case sf::Keyboard::Right:
					{
						what_unit++;
						if (what_unit >= my.size())
							what_unit = 0;
						break;
					}

					}
				}



			}
			w.clear(Color::Black);


			test.draw(w);
			cavalry.draw(w);

			for (auto i : unites)
			{
				i.draw(w);
			}
			for (auto i : my)
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