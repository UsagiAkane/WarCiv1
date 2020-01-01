#include "Militia.h"


Militia::Militia() : Unit("Militia", 1, 0, 1, 1, 0, 0, 10, 50, 2, 1,1)
//name,health,armor,damage,speed,rank,salary,productionPrice,price,index,playerId,maxspeed
{
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile("Unites\\Militia.png");
	warriorSprite.setTexture(*texture);

}
