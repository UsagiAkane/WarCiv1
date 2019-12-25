#include "Map.h"


Map::Map(int sizeX, int sizeY)
{
	////1-hill  2-forest  3-grass  4-mountain
	//for (int i = 0; i < 100; i++) {
	//	for (int j = 0; j < 100; j++) {
	//		map[i][j] = ((1 + rand() % 4) * 100);
	//	}
	//}
	////1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
	//for (int i = 0; i < 100; i++) {
	//	for (int j = 0; j < 100; j++) {
	//		if (!(rand() % 10)) {
	//			if (map[i][j] == 100) {
	//				if (rand() % 2)
	//					map[i][j] += 1;
	//				else
	//					map[i][j] += 6;
	//			}
	//		}
	//	}
	//}


	//1-hill  2-forest  3-grass  4-mountain
	for (int i = 0; i < sizeY; i++) {
		std::vector<int>maptmp;
		for (int j = 0; j < sizeX; j++) {
			maptmp.push_back(((1 + rand() % 4) * 100));
		}
		map.push_back(maptmp);
	}
	//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (!(rand() % 10)) {
				if (map.at(i).at(j) == 100) {			//HILL
					if (rand() % 3)
						map.at(i).at(j) += 1;//COAL GEN
					else if (rand() % 4)
						map.at(i).at(j) += 6;//OIL GEN
				}
				else if (map.at(i).at(j) == 200) {		//FOREST
					if (rand() % 4)
						map.at(i).at(j) += 2;//GAME GEN
				}
				else if (map.at(i).at(j) == 300) {		//GRASS
					if (rand() % 4)
						map.at(i).at(j) += 1;//COAL GEN
					else if (rand() % 3)
						map.at(i).at(j) += 4;//HORSES GEN
				}
				else if (map.at(i).at(j) == 400) {		//MOUNTAIN
					if (rand() % 4)
						map.at(i).at(j) += 3;//GOLD GEN
					else if (rand() % 3)
						map.at(i).at(j) += 5;//OASIS GEN
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

	Coal coal;
	Game game;
	Gold gold;
	Horses horses;
	Oasis oasis;
	Oil oil;

	sf::Texture resTex;
	sf::Sprite sprite;

	//1-hill  2-forest  3-grass  4-mountain
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] / 100 == 1) {				//HILL DRAW
				hill.setPosition(i * 32, j * 32);
				hill.draw(w);
				//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
				if (map[i][j] % 100 == 1) {			//COAL GEN
					coal.setPosition(i * 32, j * 32);
					coal.draw(w);
				}
				else if (map[i][j] % 100 == 6) {	//OIL GEN
					oil.setPosition(i * 32, j * 32);
					oil.draw(w);
				}
			}
			else if (map[i][j] / 100 == 2) {		//FOREST DRAW
				forest.setPosition(i * 32, j * 32);
				forest.draw(w);
				//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
				if (map[i][j] % 100 == 2) {			//GAME GEN
					game.setPosition(i * 32, j * 32);
					game.draw(w);
				}
			}
			else if (map[i][j] / 100 == 3) {		//GRASSLAND DRAW
				grass.setPosition(i * 32, j * 32);
				grass.draw(w);
				//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
				if (map[i][j] % 100 == 4) {			//HORSES GEN
					horses.setPosition(i * 32, j * 32);
					horses.draw(w);
				}
				else if (map[i][j] % 100 == 1) {	//COAL GEN
					coal.setPosition(i * 32, j * 32);
					coal.draw(w);
				}
			}
			else if (map[i][j] / 100 == 4) {		//MOUNTAIN DRAW
				mountain.setPosition(i * 32, j * 32);
				mountain.draw(w);
				//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
				if (map[i][j] % 100 == 3) {			//GOLD GEN
					gold.setPosition(i * 32, j * 32);
					gold.draw(w);
				}
				else if (map[i][j] % 100 == 5) {	//OASIS GEN
					oasis.setPosition(i * 32, j * 32);
					oasis.draw(w);
				}
			}
		}
	}

}
