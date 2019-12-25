#include "Map.h"


Map::Map()
{
	//1-hill  2-forest  3-grass  4-mountain
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			map[i][j] = ((1 + rand() % 4) * 100);
		}
	}
	//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (!(rand() % 10)) {
				if (map[i][j] == 100) {
					if (rand() % 2)
						map[i][j] += 1;
					else
						map[i][j] += 6;
				}
			}
		}
	}

}

void Map::draw(sf::RenderWindow& w)
{
	Hills hill;
	Forest forest;
	Grassland grass;
	Mountain mountain;

	sf::Texture resTex;
	sf::Sprite sprite;

	//Coal coal;
	//Game game;
	//Gold gold;
	//Horses horses;
	//Oasis oasis;
	//Oil oil;

	//1-hill  2-forest  3-grass  4-mountain
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] / 100 == 1) {
				hill.setPosition(i * 32, j * 32);
				hill.draw(w);
				if (map[i][j] % 100 == 1) {
					resTex.loadFromFile("Coal.png");
					sprite.setTexture(resTex);
					sprite.setPosition(i * 32, j * 32);
					w.draw(sprite);
				}
				else if (map[i][j] % 100 == 6) {
					resTex.loadFromFile("Oil.png");
					sprite.setTexture(resTex);
					sprite.setPosition(i * 32, j * 32);
					w.draw(sprite);
				}
			}
			else if (map[i][j] / 100 == 2) {
				forest.setPosition(i * 32, j * 32);
				forest.draw(w);
			}
			else if (map[i][j] / 100 == 3) {
				grass.setPosition(i * 32, j * 32);
				grass.draw(w);
			}
			else if (map[i][j] / 100 == 4) {
				mountain.setPosition(i * 32, j * 32);
				mountain.draw(w);
			}
		}
	}

}
