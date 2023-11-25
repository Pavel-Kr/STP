#pragma once
#include <string>

enum complexPart {
	REAL,
	IMAG
};

class TEditor
{
	std::string real;
	std::string imag;
	std::string complex;
	complexPart editingPart;
	bool hasRealDel = false;
	bool hasImagDel = false;

public:
	TEditor();
	bool isZero();
	void flipSign();
	void addDigit(int digit);
	void addZero();
	void deleteDigit();
	void clear();
	void processCommand(int command);
	std::string toString();
	void addDelimiter();
	void setComplexNumber(std::string num);
	void setEditingPart(complexPart part);
};

