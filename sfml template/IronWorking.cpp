#include "IronWorking.h"

void IronWorking::checkPrevTech(std::vector<Technologies>& b) {
	int count = 0;
	std::for_each(b.begin(), b.end(), [&count](Technologies t) { if ((t.get_name() == "Bronze Working" && t.get_is_learned() == true)) { count++; } });
	count == 1 ? this->can_be_buildable_ = 1 : false;
}

IronWorking::IronWorking() :Technologies("Iron Working", 0, 0) {}