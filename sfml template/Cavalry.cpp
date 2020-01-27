#include "Cavalry.h"

Cavalry::Cavalry():Unit("Cavalry",1,1,2,5,0,1,20,120,4,1,5)
{
	sf::Texture* texture = new sf::Texture;
	texture->loadFromFile(PATH_TO_UNITES_CAVALARY);
	warriorSprite.setTexture(*texture);
}
