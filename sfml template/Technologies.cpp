#include "Technologies.h"

Technologies::Technologies(std::string name, bool is_learned, bool can_be_buildable) {
	this->name_ = name;
	this->is_learned_ = is_learned;
	this->can_be_buildable_ = can_be_buildable;
}

std::string Technologies::get_name() {
	return this->name_;
}

bool Technologies::get_is_learned() {
	return this->is_learned_;
}

bool Technologies::get_can_be_buildable() {
	return this->can_be_buildable_;
}

void Technologies::learn() {
	this->is_learned_ = 1;
}

Technologies::~Technologies() {}