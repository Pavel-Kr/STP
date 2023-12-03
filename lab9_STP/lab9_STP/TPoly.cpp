#include "TPoly.h"

TPoly::TPoly()
{
	poly.clear();
}

TPoly::TPoly(int coef, int degree)
{
	poly.clear();
	if (coef != 0) {
		TMember m(coef, degree);
		poly.push_back(m);
	}
}

int TPoly::get_degree()
{
	if (poly.size() == 0) {
		return 0;
	}
	int max_deg = 0;
	for (int i = 0; i < poly.size(); i++) {
		if (poly[i].get_coef() != 0) {
			int deg = poly[i].get_degree();
			if (deg > max_deg) {
				max_deg = deg;
			}
		}
	}
	return max_deg;
}

int TPoly::get_coef(int degree)
{
	if (poly.size() == 0) {
		return 0;
	}
	for (int i = 0; i < poly.size(); i++) {
		if (poly[i].get_degree() == degree) {
			return poly[i].get_coef();
		}
	}
	return 0;
}

void TPoly::clear()
{
	poly.clear();
}

TPoly TPoly::operator+(TPoly& rhs)
{
	int l_deg = get_degree();
	int r_deg = rhs.get_degree();
	int max_deg = l_deg > r_deg ? l_deg : r_deg;
	TPoly res;
	for (int i = 0; i <= max_deg; i++) {
		int l_coef = get_coef(i);
		int r_coef = rhs.get_coef(i);
		int sum_coef = l_coef + r_coef;
		TMember m(sum_coef, i);
		res.poly.push_back(m);
	}
	return res;
}

TPoly TPoly::operator*(TPoly& rhs)
{
	int l_deg = get_degree();
	int r_deg = rhs.get_degree();
	int max_deg = l_deg + r_deg;
	TPoly res;
	// x^2 + 2x + 3
	// 5x + 4
	// 5x^3 + 10x^2 + 15x + 4x^2 + 8x + 12 = 5x^3 + 14x^2 + 23x + 12
	for (int i = 0; i <= max_deg; i++) { // iterate by degree of result
		int sum_coef = 0;
		for (int j = 0; j <= i; j++) {
			int l_coef = get_coef(j);          // iterate left degree from 0 to i
			int r_coef = rhs.get_coef(i - j);  // left deg + right deg = i
			sum_coef += l_coef * r_coef;
		}
		TMember m(sum_coef, i);
		res.poly.push_back(m);
	}
	return res;
}

TPoly TPoly::operator-(TPoly& rhs)
{
	int l_deg = get_degree();
	int r_deg = rhs.get_degree();
	int max_deg = l_deg > r_deg ? l_deg : r_deg;
	TPoly res;
	for (int i = 0; i <= max_deg; i++) {
		int l_coef = get_coef(i);
		int r_coef = rhs.get_coef(i);
		int sum_coef = l_coef - r_coef;
		TMember m(sum_coef, i);
		res.poly.push_back(m);
	}
	return res;
}

TPoly TPoly::operator-()
{
	TPoly res;
	for (int i = 0; i < poly.size(); i++) {
		int degree = poly[i].get_degree();
		int coef = poly[i].get_coef();
		TMember m(-coef, degree);
		res.poly.push_back(m);
	}
	return res;
}

bool TPoly::operator==(TPoly& rhs)
{
	int l_deg = get_degree();
	int r_deg = rhs.get_degree();
	if (l_deg != r_deg) {
		return false;
	}
	for (int i = 0; i <= l_deg; i++) {
		int l_coef = get_coef(i);
		int r_coef = rhs.get_coef(i);
		if (l_coef != r_coef) {
			return false;
		}
	}
	return true;
}

TPoly TPoly::derivative()
{
	TPoly res;
	for (int i = 0; i < poly.size(); i++) {
		res.poly.push_back(poly[i].derivative());
	}
	return res;
}

double TPoly::evaluate(double x)
{
	double res = 0;
	for (int i = 0; i < poly.size(); i++) {
		res += poly[i].evaluate(x);
	}
	return res;
}

std::pair<int, int> TPoly::operator[](int index)
{
	if (index < poly.size()) {
		std::pair<int, int> res;
		res.first = poly[index].get_coef();
		res.second = poly[index].get_degree();
		return res;
	}
	else {
		std::pair<int, int> res(0, 0);
		return res;
	}
}
