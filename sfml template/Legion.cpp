#include "Legion.h"

Legion::Legion() :Unit("Legion",1,1,3,2,0,1,20,120,3,2,2)
//name,health,armor,damage,speed,rank,salary,productionPrice,price,index,playerId,maxspeed
{

	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile("Unites\\Legion.png");
	warriorSprite.setTexture(*texture);
}

