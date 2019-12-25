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
	//Forest testforest;
	//Grassland testGrassland;
	//Hills testHills;
	//River testRiver;
	//Mountain testMountain;
	//Militia m;
	//Militia b;
	//m.attack(b,testforest);

	std::srand(time(NULL));

	try {
		RenderWindow w(VideoMode(1920, 1080), "TITLE");

		Map test;

		while (w.isOpen()) {
			Event ev;

			bool __keyPressedReleased = 0;
			while (w.pollEvent(ev)) {
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