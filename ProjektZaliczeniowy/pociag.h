#pragma once
#include <vector>
#include <string>
#include "Wagon.h"

class Pociag
{
private:
	std::string nazwa;
	std::vector<Wagon*> wagony;

public:
	Pociag(std::string _nazwa);
	~Pociag();
	void dodajWagon(Wagon* wagon);
	void zarezerwuj(int nrWagonu, int nrMiejsca);
	void wyswietlSklad();
	void pokazWagon(int nrWagonu);
};

