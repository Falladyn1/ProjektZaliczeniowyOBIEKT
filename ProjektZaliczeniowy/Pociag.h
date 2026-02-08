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

    Pociag& operator+=(Wagon* w);

    Pasazer* zarezerwujMiejsce(int nrWagonu, int nrMiejsca);

    void wyswietlWagon(int nrWagonu);
    void znajdzWolneMiejsce(TypMiejsca typ);
};