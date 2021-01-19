#include "Trade.h"

Trade::Trade() :Technologies("Trade", 0, 0) {}

void Trade::checkPrevTech(std::vector<Technologies>& b) {
	int count = 0;
	std::for_each(b.begin(), b.end(), [&count](Technologies t) { if ((t.get_name() == "Currency" && t.get_is_learned() == true) || (t.get_name() == "Code of Laws" && t.get_is_learned() == true)) { count++; } });
	count == 2 ? this->can_be_buildable_ = 1 : false;
}