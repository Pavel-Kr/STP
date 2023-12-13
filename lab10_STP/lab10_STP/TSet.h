#pragma once
#include <set>
#include <stdexcept>

template <class T>
class TSet
{
	std::set<T> elements;
public:
	TSet() {
		elements.clear();
	}
	void clear() {
		elements.clear();
	}
	void add(T d) {
		elements.insert(d);
	}
	void remove(T d) {
		elements.erase(d);
	}
	bool hasElements() {
		return !elements.empty();
	}
	bool contains(T d) {
		auto it = elements.find(d);
		return it != elements.end();
	}
	TSet combine(TSet& q) {
		TSet res;
		res.elements = elements;
		for (auto it : q.elements) {
			res.elements.insert(it);
		}
		return res;
	}
	TSet subtract(TSet& q) {
		TSet res;
		res.elements = elements;
		for (auto it : q.elements) {
			res.elements.erase(it);
		}
		return res;
	}
	TSet intersect(TSet& q) {
		TSet res;
		for (auto it : elements) {
			if (q.contains(it)) {
				res.elements.insert(it);
			}
		}
		return res;
	}
	int count() {
		return elements.size();
	}
	T operator[](int index) {
		if (index >= elements.size()) {
			throw std::invalid_argument("Index out of bounds");
		}
		auto start = elements.begin();
		for (int i = 0; i < index; i++) {
			start++;
		}
		return *start;
	}
};

