#include "Map.h"

Map::Map(int sizeX, int sizeY) {
	//1-hill  2-forest  3-grass  4-mountain
	for (int i = 0; i < sizeX; i++) {
		std::vector<int>maptmp;
		std::vector<int>unitstmp;
		for (int j = 0; j < sizeY; j++) {
			maptmp.push_back(((1 + rand() % 5) * 100));
			unitstmp.push_back(0);
		}
		this->map.push_back(maptmp);
		this->units.push_back(unitstmp);
	}
	//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
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

Terrain Map::getTile(int x, int y) {
	x /= 32;
	y /= 32;
	return getTileVec(x, y);
}

Terrain Map::getTileVec(int x, int y) {
	if (map.at(x).at(y) / 100 == 1) {				//HILL DRAW		
		if (map.at(x).at(y) % 100 == 1) {		//COAL DRAW
			return Hills(1);
		}
		else if (map.at(x).at(y) % 100 == 6) {	//OIL DRAW
			return Hills(2);
		}
		return Hills();
	}
	else if (map.at(x).at(y) / 100 == 2) {			//FOREST DRAW		
		if (map.at(x).at(y) % 100 == 2) {		//GAME DRAW
			return Forest(1);
		}
		return Forest();
	}
	else if (map.at(x).at(y) / 100 == 3) {			//GRASSLAND DRAW		
		if (map.at(x).at(y) % 100 == 4) {		//HORSES DRAW
			return Grassland(2);
		}
		else if (map.at(x).at(y) % 100 == 1) {	//COAL DRAW
			return Grassland(1);
		}
		return Grassland();
	}
	else if (map.at(x).at(y) / 100 == 4) {			//MOUNTAIN DRAW		
		if (map.at(x).at(y) % 100 == 3) {		//GOLD DRAW
			return Mountain(1);
		}
		else if (map.at(x).at(y) % 100 == 5) {	//OASIS DRAW
			return Mountain(2);
		}
		return Mountain();
	}
	else if (map.at(x).at(y) / 100 == 5)			//OCEAN
		return Ocean();
}
int Map::getUnitInd(int x, int y) {
	x /= 32;
	y /= 32;
	if (x > 0 && x < units.size()) {
		if (y > 0 && y < units.size()) {
			return this->units.at(x).at(y);
		}
		else return 0;
	}
	else return 0;
}
//int Map::getUnitID(int x, int y) {
//	return getUnitID(x, y) % 100;
//}
//int Map::getUnitPlayerID(int x, int y) {
//	return getUnitID(x, y) / 100;
//}
void Map::pushUnit(int x, int y, int unit) {
	x /= 32;
	y /= 32;
	//if (x > 0 || x < units.size()) {
	//	if (y > 0 || y < units.size()) {
	if (this->units.at(x).at(y) % 100 / 10 == 5)
		this->units.at(x).at(y) += unit % 10;
	else this->units.at(x).at(y) = unit;
	//	}
	//}
}
void Map::moveUnit(int x, int y, int newx, int newy) {
	x /= 32;
	y /= 32;
	newx /= 32;
	newy /= 32;
	if (this->units.at(x).at(y) % 100 / 10 == 5) {//FIX THIS
		this->units.at(newx).at(newy) = this->units.at(x).at(y) - 50;
		this->units.at(x).at(y) -= (this->units.at(x).at(y) % 10);
	}
	else {
		this->units.at(newx).at(newy) = this->units.at(x).at(y);
		this->units.at(x).at(y) = 0;
	}
}

void Map::delUnit(int x, int y) {
	x /= 32;
	y /= 32;
	if (this->units.at(x).at(y) % 100 / 10 == 5)
	{
		units.at(x).at(y) -= units.at(x).at(y) % 10;
	}
	else 
		this->units.at(x).at(y) = 0;
}
void Map::__getInfo_DEBUG(int x, int y)
{
	getTile(x, y).__getInfo_DEBUG();
	std::cout << "unut_index = " << this->units[x / 32][y / 32];
	std::cout << "\n-map-tile-end-\n";
}
void Map::draw(sf::RenderWindow& w) {
	Hills hill;
	Forest forest;
	Grassland grass;
	Mountain mountain;
	Ocean ocean;

	Coal coal;
	Game game;
	Gold gold;
	Horses horses;
	Oasis oasis;
	Oil oil;


	//1-hill  2-forest  3-grass  4-mountain
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.at(i).size(); j++) {
			if (map[i][j] / 100 == 1) {					//HILL DRAW
				hill.setPosition(i * 32, j * 32);
				hill.draw(w);
				//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
				if (map[i][j] % 100 == 1) {			//COAL DRAW
					coal.setPosition(i * 32, j * 32);
					coal.draw(w);
				}
				else if (map[i][j] % 100 == 6) {	//OIL DRAW
					oil.setPosition(i * 32, j * 32);
					oil.draw(w);
				}
			}
			else if (map[i][j] / 100 == 2) {			//FOREST DRAW
				forest.setPosition(i * 32, j * 32);
				forest.draw(w);
				//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
				if (map[i][j] % 100 == 2) {			//GAME DRAW
					game.setPosition(i * 32, j * 32);
					game.draw(w);
				}
			}
			else if (map[i][j] / 100 == 3) {			//GRASSLAND DRAW
				grass.setPosition(i * 32, j * 32);
				grass.draw(w);
				//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
				if (map[i][j] % 100 == 4) {			//HORSES DRAW
					horses.setPosition(i * 32, j * 32);
					horses.draw(w);
				}
				else if (map[i][j] % 100 == 1) {	//COAL DRAW
					coal.setPosition(i * 32, j * 32);
					coal.draw(w);
				}
			}
			else if (map[i][j] / 100 == 4) {			//MOUNTAIN DRAW
				mountain.setPosition(i * 32, j * 32);
				mountain.draw(w);
				//1-Coal  2-Game  3-Gold  4-Horses  5-Oasis  6-Oil
				if (map[i][j] % 100 == 3) {			//GOLD DRAW
					gold.setPosition(i * 32, j * 32);
					gold.draw(w);
				}
				else if (map[i][j] % 100 == 5) {	//OASIS DRAW
					oasis.setPosition(i * 32, j * 32);
					oasis.draw(w);
				}
			}
			else if (map[i][j] / 100 == 5) {			//OCEAN
				ocean.setPosition(i * 32, j * 32);
				ocean.draw(w);
			}


		}
	}
}
