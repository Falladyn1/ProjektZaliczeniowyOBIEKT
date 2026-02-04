#pragma once
#include <vector>
#include <string>
#include "Wagon.h"

class Pociag {
private:
    std::string nazwa;
    std::vector<Wagon*> wagony;

public:
    Pociag(std::string _nazwa);
    ~Pociag();

    void dodajWagon(Wagon* w);
    void zarezerwujMiejsce(int nrWagonu, int nrMiejsca);
    void wyswietlWagon(int nrWagonu);

    void znajdzWolneMiejsce(TypMiejsca typ);
};