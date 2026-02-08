#pragma once
#include <vector>
#include <string>
#include "Wagon.h"

class Pociag {
private:
    std::string nazwa;
    std::vector<Wagon*> wagony; // Wektor wskaznikow na wagony

public:
    Pociag(std::string _nazwa);
    ~Pociag();

    Pociag& operator+=(Wagon* w);

    void dodajWagon(Wagon* w);

    void zarezerwujMiejsce(int nrWagonu, int nrMiejsca);

    void wyswietlListePasazerow();
};