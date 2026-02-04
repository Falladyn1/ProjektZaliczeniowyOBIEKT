#pragma once
#include <vector>
#include <string>
#include "Wagon.h"

class pociag {
private:
    std::string nazwa;
    std::vector<Wagon*> wagony;

public:
    pociag(std::string _nazwa);
    ~pociag();

    void dodajWagon(Wagon* w);
    void zarezerwujMiejsce(int nrWagonu, int nrMiejsca);
    void wyswietlWagon(int nrWagonu);
};