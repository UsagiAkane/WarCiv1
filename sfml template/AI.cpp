#include "AI.h"

AI::AI(int playerID) :Actor("OpenAI", playerID)
{

}

void AI::endOfTurnBot(Map& map)
{
	std::cout << "1"<< std::endl;
	for (auto i : this->units)
	{
		std::cout << map.getTile(i.getPositionX(), i.getPositionY() + 32).isWater() << std::endl;
		if (!(map.getTile(i.getPositionX(), i.getPositionY()+32).isWater()))
		{
			std::cout <<"CHECK" << std::endl;
			i.moveDownHidden(map);
		}


	}
}
