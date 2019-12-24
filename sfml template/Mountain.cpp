#include "Mountain.h"

Mountain::Mountain()
{
	//texture load from file
	this->move = 1;
	this->food = 2;
	this->prodaction = 1;
	this->trade = 0;
	this->defense = 1.5;

	if (!(rand() % 15)) {
		this->trade += this->gold.getTrade();
		this->gold.setHave(1);
	}
	else if (!(rand() % 11)) {
		this->food += this->oasis.getFood();
		this->oasis.setHave(1);
	}
}