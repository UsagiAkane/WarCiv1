#pragma once
#include "Technologies.h"

class Masonry :public Technologies {
public:
	Masonry();
	std::string get_name() override;
	bool get_is_learned() override;

	~Masonry();
};
