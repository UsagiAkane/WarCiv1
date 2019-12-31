#include "GameManager.h"

GameManager::GameManager()
{
	//this->map

	Actor* player = new Actor("player", this->map);
	player->setPlayerID(1);
	player->pushbackEnemyID(2);


	//DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-DEBUG-
	Actor *enemyActor=new Actor("Ruslan", map);
	enemyActor->setPlayerID(2);
	////////////////////////////CREATING UNITS
	std::vector<int> enemiesID;
	enemiesID.push_back(2);
	//enemy units
	//std::vector<Unit> EnemyUnitVector;
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

	
	this->actors.push_back(*player);
	this->actors.push_back(*enemyActor);
}

void GameManager::draw(sf::RenderWindow& w)
{
	for (auto i : this->actors) {
		i.draw(w);
	}
}
