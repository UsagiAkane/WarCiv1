#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

#include "Forest.h"
#include "Grassland.h"
#include "Hills.h"
#include "River.h"
#include "Mountain.h"

#include"Map.h"

#include"CodeOfLaws.h"

using namespace sf;

int main(void) {
	Forest testforest;
	Grassland testGrassland;
	Hills testHills;
	River testRiver;
	Mountain testMountain;

	std::cout << testGrassland.getDefense();

	std::srand(time(NULL));

	try {
		RenderWindow w(VideoMode(1920, 1080), "TITLE"/*, Style::Fullscreen*/);

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
			//test.draw(w);

			//Texture texture_forest;
			//texture_forest.loadFromFile("Terrains\\Forest.png");
			//Sprite map_forest_tile(texture_forest);

			//w.draw(map_forest_tile);//user


			w.display();
		}

	}
	catch (const std::exception & e) {
		std::cout << e.what();
	}

	return 1;
}