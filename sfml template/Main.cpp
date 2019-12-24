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

using namespace sf;

int main(void) {
	Forest testforest;
	Grassland testGrassland;
	Hills testHills;
	River testRiver;
	Mountain testMountain;

	std::cout<<testGrassland.getDefense();


	try {
		RenderWindow w(VideoMode(1000, 600), "TITLE"/*, Style::Fullscreen*/);

		while (w.isOpen()) {
			Event ev;

			bool __keyPressedReleased = 0;
			while (w.pollEvent(ev)) {
				if (ev.type == Event::Closed)
					w.close();

			}

			w.clear(Color::Black);


			Map test;
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