#pragma once
#include "Technologies.h"
#include <vector>
#include <algorithm>

//свод законо для него нужен алфавит
class CodeOfLaws :public Technologies
{
private:
public:
	CodeOfLaws();
	void checkPrevTech(std::vector<Technologies>& b);
};

