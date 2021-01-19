#include "Masonry.h"

Masonry::Masonry() :Technologies("Masonry", 0, 1) {}

std::string Masonry::get_name() {
	return this->name_;
}

bool Masonry::get_is_learned() {
	return this->is_learned_;
}

Masonry::~Masonry() {}