#include "Map.h"


Map::Map()
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			map[i][j] = rand() % 4;
		}
	}
}

void Map::draw(sf::RenderWindow& w)
{
	Hills hill;
	Forest forest;
	Grassland grass;
	Mountain mountain;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 0) {
				hill.setPosition(i * 32, j * 32);
				hill.draw(w);
			}
			else if (map[i][j] == 1) {
				forest.setPosition(i * 32, j * 32);
				forest.draw(w);
			}
			else if (map[i][j] == 2) {
				grass.setPosition(i * 32, j * 32);
				grass.draw(w);
			}
			else if (map[i][j] == 3) {
				mountain.setPosition(i * 32, j * 32);
				mountain.draw(w);
			}
		}
	}

}
