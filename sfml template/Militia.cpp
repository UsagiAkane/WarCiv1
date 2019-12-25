#include "Militia.h"


Militia::Militia() : Unit("Militia", 1, 0, 1, 1, 0, 0, 10, 50, 2, -1,1)
{
	//sf::Texture texture;
	texture.loadFromFile("Warriors\\Militia.png");
	warriorSprite.setTexture(texture);
	//this->warriorSprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
}
