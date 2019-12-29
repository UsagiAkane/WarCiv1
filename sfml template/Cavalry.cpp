#include "Cavalry.h"

Cavalry::Cavalry():Unit("Cavalry",1,1,2,4,0,1,20,120,4,1,4)
{
	texture.loadFromFile("Unites\\Cavalry.png");
	warriorSprite.setTexture(texture);
}
