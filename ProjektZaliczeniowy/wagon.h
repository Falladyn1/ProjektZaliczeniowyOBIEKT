#pragma once
#include <vector>
#include "miejsce.h"
class wagon
{
private:
	int numerWagonu;
	int klasa; // 1 lub 2
	std::vector<miejsce> siedzenia;
public:
	wagon(int _nr);
	virtual ~wagon() = default;

	virtual void generujMiejsca() = 0;
	int pobierzNumer() const { return numerWagonu; }
	std::vector<miejsce>& pobierzMiejsca() { return siedzenia; }
};

