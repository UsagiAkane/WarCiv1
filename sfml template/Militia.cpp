#include "Militia.h"


Militia::Militia() : Unit("Militia", 1, 0, 1, 1, 0, 0, 10, 50, 2, -1,1)
{
	//sf::Texture texture;
	texture.loadFromFile("Unites\\Militia.png");
	warriorSprite.setTexture(texture);

}
