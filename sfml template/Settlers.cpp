#include "Settlers.h"
//name,health,armor,damage,speed,rank,salary,productionPrice,price,index,playerId,maxspeed
Settlers::Settlers() :Unit("Settlers",1,0,1,2,0,0,40,320,1,0,2)
{
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile("Unites\\Settlers.png");
	warriorSprite.setTexture(*texture);
}

