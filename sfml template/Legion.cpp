#include "Legion.h"

Legion::Legion() :Unit("Legion",1,1,3,2,0,1,20,120,3,2,2)
{
	texture.loadFromFile("Unites\\Legion.png");
	warriorSprite.setTexture(texture);
}