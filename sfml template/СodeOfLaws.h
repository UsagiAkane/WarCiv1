#pragma once
#include "Technologies.h"
#include <vector>
#include <algorithm>

//свод законо для него нужен алфавит
class СodeOfLaws :public Technologies
{
private:
public:
	СodeOfLaws();
	void checkPrevTech(std::vector<Technologies>& b);
};

