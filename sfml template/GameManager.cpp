#include "GameManager.h"

GameManager::GameManager()
{
	//this->map

	Actor* player = new Actor("player", this->map);
	player->setPlayerID(1);
	Settlers* firstS = new Settlers;
	firstS->setPlayerID(player->getPlayerID());
	firstS->spawn(128, 160, this->map);
	player->__PUSH_UNIT_DEBUG(firstS);


	//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
	Actor* enemyActor = new Actor("Ruslan", map);
	enemyActor->setPlayerID(2);
	////////////////////////////CREATING UNITS
	Legion* legionEnemy = new Legion;
	Militia* militiaEnemy = new Militia;
	militiaEnemy->setPlayerID(2);
	militiaEnemy->spawn(128, 128, map);
	//EnemyUnitVector.push_back(militiaEnemy);
	enemyActor->__PUSH_UNIT_DEBUG(militiaEnemy);
	legionEnemy->setPlayerID(2);
	legionEnemy->spawn(96, 96, map);
	//EnemyUnitVector.push_back(legionEnemy);
	enemyActor->__PUSH_UNIT_DEBUG(legionEnemy);
	Town* townEnemy = new Town;
	townEnemy->setPlayer_id(2);
	townEnemy->spawn(32 * 5, 32 * 6, this->map);
	enemyActor->__PUSH_TOWN_DEBUG(townEnemy);


	//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-


	Actor* third = new Actor("Vova", map);
	third->setPlayerID(3);
	Settlers* settlers3 = new Settlers;
	Legion* legionEnemy3 = new Legion;
	legionEnemy3->setPlayerID(3);
	legionEnemy3->spawn(32 * 6, 32 * 6, map);
	settlers3->setPlayerID(3);
	settlers3->spawn(32 * 5, 32 * 5, map);
	third->__PUSH_UNIT_DEBUG(settlers3);
	third->__PUSH_UNIT_DEBUG(legionEnemy3);


	this->actors.push_back(*player);
	this->actors.push_back(*enemyActor);
	this->actors.push_back(*third);


	this->currentYear = -4000;
}

Map& GameManager::getMap()
{
	return this->map;
}

std::vector<Actor>& GameManager::getActors()
{
	return this->actors;
}

void GameManager::setYear(int year)
{
	this->currentYear = year;
}

int GameManager::getYear()
{
	return this->currentYear;
}

void GameManager::draw(sf::RenderWindow& w)
{
	map.draw(w);
	for (auto i : this->actors)
		i.draw(w);
}

Actor& GameManager::findActor(int ID)
{
	if (ID < 100 && ID > 0)
	{
		if (this->actors.at(ID - 1).getPlayerID() == ID)
			return this->actors.at(ID - 1);
	}
	else return this->actors.at(0);
}

std::vector<Unit>& GameManager::findActorUnit(int mouse_x, int mouse_y)
{

	if ((map.getUnitInd(mouse_x, mouse_y)) / 100 != 0 && (map.getUnitInd(mouse_x, mouse_y)) / 100 != this->actors.at(0).getPlayerID()) //check index of unit
		return findActor((map.getUnitInd(mouse_x, mouse_y)) / 100).getUnits();
	else
		std::cout << "CAN'T FIND UNIT" << std::endl;
}

void GameManager::saveGame()
{
	map.saveMap();
	for (auto i : actors)
	{
		i.saveTotalnfo();
	}
}

std::string getUnitInfoFromFile(int actorInd)
{
	std::string line;
	std::string buffer;
	std::string path = "Saves\\Save1.txt";
	std::ifstream fin;
	fin.open(path);
	short isnext = 0;
	short actori = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			if (isnext == 2)
			{
				fin >> buffer;
				if (buffer == "#")
					actorInd--;

				if (actorInd == 0 && buffer == "#")
					break;

				line += buffer;
				line += " ";

				if (buffer == "&")
					line.clear();

			}
			else
			{
				fin >> buffer;
				if (buffer == "=")
					isnext++;
			}
		}
		//std::cout << line << std::endl;//==============================DEBUG
	}
	else
		std::cout << "Can't open file" << std::endl;
	fin.close();
	return line;
}

int getUnitsCount(int actorInd) {
	std::string buffer = getUnitInfoFromFile(actorInd);
	short counter = 0;
	for (int i = 0; i < buffer.size(); i++)
	{
		if (buffer[i] == '|')
			counter++;
	}
	return counter;
}

std::string sliseStrings(std::string str, int index) {
	std::string tmp;
	index--;
	//1 0 1 3 0 0 1 3 160 160 |1 1 3 3 0 0 3 3 192 192 |
	for (auto i : str) {
		if (i == '|' && index == 0)break;
		if (index != 0) {
			if (i == '|') {
				index--;
				tmp.clear();
			}
		}
		if (i != '|')
			tmp += i;

		//std::cout << tmp << std::endl;
	}
	if (index == 0) {
		return tmp;
	}

}

//find digit from heap
int getIntFromStringByIndex(std::string com, int index)
{
	int tmp = 0;
	std::string time;
	if (index == 1) {
		for (int i = 0; i < com.size(); i++)
		{
			if (!std::isdigit(com[i]))
				break;
			time += com[i];
		}
		return stoi(time);
	}
	for (int i = 1; i < com.size(); i++)
	{
		if ((std::isdigit(com[i]) || com[i] == '|') && (com[i - 1] == ' '))
		{
			index--;
		}
		if (index == 1)
		{
			time += com[i];
		}
		if (index == 0)
		{
			std::cout << time << std::endl;
			return stoi(time);
		}
	}

}

std::vector<Unit> getUnitById(int actorInd)
{
	std::vector<Unit> tmp;

	//1 0 1 1 0 0 2 2 128 128 |1 1 3 3 0 0 3 2 96 96 |
	std::string preSlisedStr = getUnitInfoFromFile(actorInd);




	return tmp;
}

std::string getMapTerrainDataFromFile()
{
	std::string line;
	std::string buffer;
	std::string path = "Saves\\Save1.txt";
	std::ifstream fin;
	fin.open(path);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> buffer;
			if (buffer == "=") {
				break;
			}
			line += buffer;
			line += " ";
		}
		//std::cout << "\n\n\n\n\n";
		//for (auto i : line)
		//{
		//	std::cout << i;
		//}
	}
	else
		std::cout << "Can't open file" << std::endl;
	fin.close();
	return line;
}

std::string getMapUnitDataFromFile()
{
	std::string line;
	std::string buffer;
	std::string path = "Saves\\Save1.txt";
	std::ifstream fin;
	fin.open(path);
	bool isnext = false;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			if (isnext)
			{
				fin >> buffer;
				if (buffer == "=") {
					break;
				}
				line += buffer;
				line += " ";
			}
			else
			{
				fin >> buffer;
				if (buffer == "=")
					isnext = true;
			}
		}
	}
	else
		std::cout << "Can't open file" << std::endl;
	fin.close();
	return line;
}

std::string getActorInfoFromFile(int actorInd)
{
	std::string line;
	std::string buffer;
	std::string path = "Saves\\Save1.txt";
	std::ifstream fin;
	fin.open(path);
	short isnext = 0;
	short actori = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{

			if (isnext == 2)
			{
				fin >> buffer;
				if (buffer == "_") {
					actorInd--;
				}
				if (actorInd == 0 && buffer == "_")
				{
					break;
				}

				line += buffer;
				line += " ";

				if (buffer == "#") {
					line.clear();
				}
			}
			else
			{
				fin >> buffer;
				if (buffer == "=")
					isnext++;
			}
		}

	}
	else
		std::cout << "Can't open file" << std::endl;
	fin.close();
	return line;
}

std::string getActorName(int actorInd) {
	std::string namebuf = getActorInfoFromFile(actorInd);
	for (int i = 0; i < namebuf.size(); i++) {
		if (!std::isalpha(namebuf.at(i)))
			namebuf.erase(i);
	}
	return namebuf;
}

int getActorTG(int actorInd) {
	std::string namebuf = getActorInfoFromFile(actorInd);
	std::string intbuf;
	for (int i = 0; i < namebuf.size(); i++) {
		if (std::isdigit(namebuf.at(i)) || (namebuf.at(i) == ' ')) { intbuf += namebuf[i]; }
	}
	intbuf.erase(0, 3);
	return stoi(intbuf);
}

int getActorTS(int actorInd) {
	std::string namebuf = getActorInfoFromFile(actorInd);
	std::string intbuf;
	for (int i = 0; i < namebuf.size(); i++) {
		if (std::isdigit(namebuf.at(i)) || (namebuf.at(i) == ' ')) { intbuf += namebuf[i]; }
	}
	intbuf.erase(0, 3);

	for (int j = 0; j < intbuf.size(); j++) {
		if (intbuf.at(j) == ' ') {
			intbuf.erase(0, j);
			break;
		}
	}



	return stoi(intbuf);
}

int getActorsCount() {

	std::string buffer;
	std::string path = "Saves\\Save1.txt";
	std::ifstream fin;
	fin.open(path);
	short isnext = 0;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> buffer;
			if (buffer == "_")
				isnext++;
		}
	}
	else
		std::cout << "Can't open file" << std::endl;
	fin.close();

	return isnext;

}

void GameManager::loadGame()
{
	map.loadUnits(getMapUnitDataFromFile());
	map.loadTerrains(getMapTerrainDataFromFile());
	if (this->actors.size() > 0)
	{
		this->deleteAllActors();
		//getActorInfoFromFile();

		for (int i = 1; i <= getActorsCount(); i++) {
			this->actors.push_back(Actor(getActorName(i), map, i));
			this->actors[i - 1].setTotalGold(getActorTG(i));
			this->actors[i - 1].setTotalScience(getActorTS(i));
			//this->actors.at(i - 1).setTotalGold();
			//this->actors[i-1].__SHOW_INFO_DEBUG();

			//std::cout << getIntFromStringByIndex(getUnitInfoFromFile(i), 1) << std::endl;
			std::cout << sliseStrings(getUnitInfoFromFile(i), 2) << std::endl;
		}

	}
	else
	{
	}



}

void GameManager::deleteAllActors()
{
	this->actors.clear();
}

