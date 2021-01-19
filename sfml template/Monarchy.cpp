#include "Monarchy.h"

Monarchy::Monarchy() :Technologies("Monarchy", 0, 0) {}

void Monarchy::checkPrevTech(std::vector<Technologies>& b) {
	int count = 0;
	std::for_each(b.begin(), b.end(), [&count](Technologies t) { if ((t.get_name() == "Ceremonial Burial" && t.get_is_learned() == true) || (t.get_name() == "Alphabet" && t.get_is_learned() == true)) { count++; } });
	count == 2 ? this->can_be_buildable_ = 1 : false;
}