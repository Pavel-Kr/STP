#pragma once
#include <string>

#define _On true
#define _Off false

template<class T>
class TMemory
{
	T FNumber;
	bool FState;
public:
	TMemory();
	void write(T E);
	T read();
	void add(T E);
	void clear();
	std::string getState();
};

template<class T>
TMemory<T>::TMemory()
{
	FNumber = T();
	FState = _Off;
}

template<typename T>
void TMemory<T>::write(T E)
{
	if (FState == _Off) {
		FNumber = E;
		FState = _On;
	}
}

template<typename T>
T TMemory<T>::read()
{
	T copy = FNumber;
	return copy;
}

template<typename T>
void TMemory<T>::add(T E)
{
	FNumber = FNumber + E;
	FState = _On;
}

template<typename T>
void TMemory<T>::clear()
{
	FNumber = T();
	FState = _Off;
}

template<typename T>
std::string TMemory<T>::getState()
{
	std::string result;
	if (FState == _On) {
		result = "On";
	}
	else {
		result = "Off";
	}
	return result;
}