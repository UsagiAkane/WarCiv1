#include "Chariot.h"

Chariot::Chariot() :Unit("Legion", 1, 2, 4, 4, 0, 1, 30, 250, 5, 2, 4)
//name,health,armor,damage,speed,rank,salary,productionPrice,price,index,playerId,maxspeed
{
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile("Unites\\Chariot.png");
	warriorSprite.setTexture(*texture);
}