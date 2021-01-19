#include "CodeOfLaws.h"

CodeOfLaws::CodeOfLaws() : Technologies("Code of Laws", 0, 0) {}

void CodeOfLaws::checkPrevTech(std::vector<Technologies>& b) {
	int count = 0;
	std::for_each(b.begin(), b.end(), [&count](Technologies t) { if ((t.get_name() == "Alphabet" && t.get_is_learned() == true)) { count++; } });
	count == 1 ? this->can_be_buildable_ = 1 : false;
}