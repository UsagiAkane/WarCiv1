#include "Barracks.h"

Barracks::Barracks():Building("Barracks",40,160,0,0,1,0,0,0)
{
	texture.loadFromFile("BuildingsIcons\\Barracks.png");
	sprite.setTexture(texture);
}
