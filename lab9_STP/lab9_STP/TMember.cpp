#include "TMember.h"
#include <cmath>
#include <sstream>

TMember::TMember(int coef, int deg) : coef(coef), degree(deg)
{

}

int TMember::get_degree()
{
	return degree;
}

void TMember::set_degree(int deg)
{
	degree = deg;
}

int TMember::get_coef()
{
	return coef;
}

void TMember::set_coef(int coef)
{
	this->coef = coef;
}

bool TMember::operator==(TMember& rhs)
{
	if (this->coef == rhs.coef && this->degree == rhs.degree) {
		return true;
	}
	return false;
}

TMember TMember::derivative()
{
	return TMember(coef * degree, degree - 1);
}

double TMember::evaluate(double x)
{
	return coef * pow(x, degree);
}

std::string TMember::toString()
{
	std::stringstream ss;
	ss << coef << "x^" << degree;
	return ss.str();
}
