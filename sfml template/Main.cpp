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
#include "Town.h"

using namespace sf;

int main(void) {

	std::srand(time(NULL));
	Map map(100, 100);

	////////////////////////////CREATING UNITS
	std::vector<int> enemiesID;
	enemiesID.push_back(2);
	//enemy units
	std::vector<Unit> EnemyUnites;
	Legion legionEnemy;
	Militia militiaEnemy;
	militiaEnemy.setPlayerID(2);
	militiaEnemy.spawn(128, 128, map);
	legionEnemy.setPlayerID(2);
	legionEnemy.spawn(96, 96, map);

	EnemyUnites.push_back(legionEnemy);
	EnemyUnites.push_back(militiaEnemy);
	//my units
	std::vector<Unit> myUnitVector;
	Militia myMilitia;
	Militia myMilitia2;
	//myMilitia.setPlayerID(1); //BY DEFAULT
	myMilitia.spawn(192, 192, map);
	//myMilitia2.setPlayerID(1); //BY DEFAULT
	myMilitia2.spawn(224, 192, map);

	myUnitVector.push_back(myMilitia);
	myUnitVector.push_back(myMilitia2);

	//my towns
	std::vector<Town> myTownVector;
	Town town(32, 32);
	town.createUnit(map, 1, myUnitVector);





	int what_unit = 0;
	try {
		RenderWindow w(VideoMode(1100, 720), "TITLE");

		while (w.isOpen()) {
#pragma region events
			Event event;

			while (w.pollEvent(event)) {
				//CLOSE--------------
				if (event.type == event.Closed)
					w.close();
				//UNIT-MOVE----------
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (event.MouseButtonReleased) {
						if (myUnitVector.size() > 0) {
							if (myUnitVector.at(what_unit).getIsAlive() == true)
								myUnitVector.at(what_unit).move(sf::Mouse::getPosition(w).x, sf::Mouse::getPosition(w).y, map, enemiesID, EnemyUnites, w);
							else {
								myUnitVector.erase(what_unit + myUnitVector.begin());
								what_unit = 0;
							}
						}
					}
				}
				if (event.type == sf::Event::KeyPressed) {
					switch (event.key.code) {
						//UNIT-TARGET--------
					case sf::Keyboard::Right:
						what_unit++;
						if (what_unit >= myUnitVector.size())
							what_unit = 0;
						break;
						//CREATE-TOWN--------
					case sf::Keyboard::W:
						if (myUnitVector.at(what_unit).getIsAlive() == true) {
							if (myUnitVector.at(what_unit).getIndex() == 1) {
								//town.createUnit(map, 1, myUnitVector);
							}
						}
						break;
					}
				}

			}
#pragma endregion
			//WINDOW-FILL-COLOR
			w.clear(Color::Black);
			//MAP-DRAW
			map.draw(w);
			//UNITES-AND-TOWNS-DRAW
			town.draw(w);
			for (auto i : EnemyUnites)
			{
				i.draw(w);
			}
			for (auto i : myUnitVector)
			{
				i.draw(w);
			}
			//DISPLAY
			w.display();
		}



	}
	catch (const std::exception & e) {
		std::cout << e.what();
	}

	return 1;
}