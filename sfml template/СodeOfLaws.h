#pragma once
#include "Technologies.h"
#include <vector>
#include <algorithm>

//���� ������ ��� ���� ����� �������
class �odeOfLaws :public Technologies
{
private:
public:
	�odeOfLaws();
	void checkPrevTech(std::vector<Technologies>& b);
};

