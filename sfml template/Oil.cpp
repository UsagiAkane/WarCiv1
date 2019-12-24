#include "Oil.h"

Oil::Oil()
{
	//tex
	this->prodaction = 4;
	this->have = 0;
}

int Oil::getProdaction()
{
	return this->prodaction;
}
