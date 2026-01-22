#pragma once
#include <vector>
#include "Miejsce.h"
class Wagon
{
protected:
	int numerWagonu;
	int klasa; // 1 lub 2
	std::vector<Miejsce> siedzenia;
public:
	Wagon(int _nr);
	virtual ~Wagon() = default;

	virtual void generujMiejsca() = 0;
	int pobierzNumer() const { return numerWagonu; }
	std::vector<Miejsce>& pobierzMiejsca() { return siedzenia; }
};

