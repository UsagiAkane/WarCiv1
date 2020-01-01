#include "GameManager.h"

GameManager::GameManager()
{
	//this->map

	Actor* player = new Actor("player", this->map);
	player->setPlayerID(1);
	player->pushbackEnemyID(2);
	player->pushbackEnemyID(3);
	Settlers* firstS = new Settlers;
	firstS->setPlayerID(player->getPlayerID());
	firstS->spawn(0, 64, this->map);
	player->__PUSH_UNIT_DEBUG(firstS);

	Legion* t = new Legion;
	t->setPlayerID(player->getPlayerID());
	t->spawn(0, 32, this->map);
	player->__PUSH_UNIT_DEBUG(t);


	//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
	Actor *enemyActor=new Actor("Ruslan", map);
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
	//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-


	Actor* third = new Actor("Vova", map);
	third->setPlayerID(3);
	Settlers* settlers3 = new Settlers;
	settlers3->setPlayerID(3);
	settlers3->spawn(32*5, 32*5, map);
	third->__PUSH_UNIT_DEBUG(settlers3);
	

	this->actors.push_back(*player);
	this->actors.push_back(*enemyActor);
	this->actors.push_back(*third);
}

Map& GameManager::getMap()
{
	return this->map;
}

std::vector<Actor>& GameManager::getActors()
{
	return this->actors;
}

void GameManager::draw(sf::RenderWindow& w)
{
	map.draw(w);
	for (auto i : this->actors)
		i.draw(w);
	
}

Actor& GameManager::findActor(int ID)
{
	for (auto i : this->actors)
	{
		if (i.getPlayerID() == ID)
			return i;

	}
}
