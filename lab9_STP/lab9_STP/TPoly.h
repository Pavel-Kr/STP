#pragma once
#include <vector>
#include "TMember.h"

class TPoly
{
	std::vector<TMember> poly;
public:
	TPoly();
	TPoly(int coef, int degree);
	int get_degree();
	int get_coef(int degree);
	void clear();
	TPoly operator+(TPoly& rhs);
	TPoly operator*(TPoly& rhs);
	TPoly operator-(TPoly& rhs);
	TPoly operator-();
	bool operator==(TPoly& rhs);
	TPoly derivative();
	double evaluate(double x);
	std::pair<int, int> operator[](int index);
};

