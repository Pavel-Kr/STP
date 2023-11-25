#include "TEditor.h"
#include <iostream>
#include <vector>
#include <regex>

TEditor::TEditor()
{
	clear();
	editingPart = REAL;
}

bool TEditor::isZero()
{
	return real == "0" && imag == "0";
}

void TEditor::flipSign()
{
	switch (editingPart)
	{
	case REAL:
		if (real[0] == '-') {
			real.erase(0, 1);
		}
		else {
			real.insert(0, 1, '-');
		}
		break;
	case IMAG:
		if (imag[0] == '-') {
			imag.erase(0, 1);
		}
		else {
			imag.insert(0, 1, '-');
		}
		break;
	default:
		break;
	}
}

void TEditor::addDigit(int digit)
{
	if (digit > 0 && digit < 10) {
		char d = digit + '0';
		switch (editingPart)
		{
		case REAL:
			real += d;
			break;
		case IMAG:
			imag += d;
			break;
		default:
			break;
		}
	}
}

void TEditor::addZero()
{
	switch (editingPart)
	{
	case REAL:
		real += '0';
		break;
	case IMAG:
		imag += '0';
		break;
	default:
		break;
	}
}

void TEditor::deleteDigit()
{
	switch (editingPart)
	{
	case REAL:
		if (real.length() > 0) {
			if (real[real.length() - 1] == '.') {
				hasRealDel = false;
			}
			real.pop_back();
		}
		break;
	case IMAG:
		if (imag.length() > 0) {
			if (imag[imag.length() - 1] == '.') {
				hasImagDel = false;
			}
			imag.pop_back();
		}
		break;
	default:
		break;
	}
}

void TEditor::clear()
{
	real = "0";
	imag = "0";
	complex = "0 + 0i";
}

void TEditor::processCommand(int command)
{
	switch (command)
	{
	case 1:
		// add digit
		int digit;
		std::cout << "Enter digit: ";
		std::cin >> digit;
		if (digit == 0) {
			addZero();
		}
		else {
			addDigit(digit);
		}
		break;
	case 2:
		flipSign();
		break;
	case 3:
		addDelimiter();
		break;
	case 4:
		deleteDigit();
		break;
	case 5:
		clear();
		break;
	case 6:
		std::cout << "Complex nuber = " << toString() << std::endl;
		system("pause");
		break;
	case 7:
	{
		std::string num;
		std::cout << "Enter complex number: ";
		std::cin >> num;
		setComplexNumber(num);
		break;
	}
	case 8:
		int input;
		std::cout << "Select editing part: 1 - real, 2 - imaginary: ";
		std::cin >> input;
		switch (input)
		{
		case 1:
			setEditingPart(REAL);
			break;
		case 2:
			setEditingPart(IMAG);
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			return;
		}
	default:
		std::cout << "Invalid command: " << command << std::endl;
		break;
	}
}

std::string TEditor::toString()
{
	complex = real;
	complex += " ";
	if (imag[0] != '-') {
		complex += "+ ";
	}
	complex += imag;
	complex += "i";
	return complex;
}

void TEditor::addDelimiter()
{
	switch (editingPart)
	{
	case REAL:
		if (!hasRealDel) {
			real += ".";
			hasRealDel = true;
		}
		break;
	case IMAG:
		if (!hasImagDel) {
			imag += ".";
			hasImagDel = true;
		}
		break;
	default:
		break;
	}
}

std::vector<std::string> split(std::string str, std::string delim) {
	size_t pos_start = 0, pos_end, delim_len = delim.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = str.find(delim, pos_start)) != std::string::npos) {
		token = str.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(str.substr(pos_start));
	return res;
}

void TEditor::setComplexNumber(std::string num)
{
	std::string no_spaces = "";
	for (char c : num) {
		if (c != ' ') {
			no_spaces += c;
		}
	}
	std::regex r(R"(\-?\d+(\.\d+)?(\+|\-)\d+(\.\d+)?i)"); // real.realFrac (+ or -) imag.imagFrac i (fractional parts are optional)
	if (!std::regex_match(no_spaces.data(), r)) {
		std::cout << "Invalid format" << std::endl;
		return;
	}
	editingPart = REAL;
	real = "";
	imag = "";
	int i = 0;
	if (no_spaces[i] == '-') {
		real += '-';
		i++;
	}
	for (; i < no_spaces.length(); i++) {
		if (no_spaces[i] == '+' || no_spaces[i] == '-') {
			editingPart = IMAG;
			if (no_spaces[i] == '-') {
				flipSign();
			}
			continue;
		}
		if (no_spaces[i] == '.') {
			addDelimiter();
			continue;
		}
		int digit = no_spaces[i] - '0';
		if (digit == 0) {
			addZero();
		}
		else {
			addDigit(digit);
		}
	}
	editingPart = REAL;
}

void TEditor::setEditingPart(complexPart part)
{
	editingPart = part;
}
