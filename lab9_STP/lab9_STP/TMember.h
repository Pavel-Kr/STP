#pragma once
#include <string>

class TMember
{
	int coef;
	int degree;
public:
	TMember(int coef, int deg);
	int get_degree();
	void set_degree(int deg);
	int get_coef();
	void set_coef(int coef);
	bool operator==(TMember& rhs);
	TMember derivative();
	double evaluate(double x);
	std::string toString();
};

