#pragma once
#include "Pasazer.h"

enum class TypMiejsca { OKNO, SRODEK, KORYTARZ };

class Miejsce {
private:
    int numerMiejsca;
    TypMiejsca rodzaj;
    double cenaBazowa;
    Pasazer* pasazer; // Wskaznik na pasazera

public:
    Miejsce(int nr, TypMiejsca r, double cena);
    ~Miejsce();

    bool czyWolne() const;
    int pobierzNumer() const;
    TypMiejsca pobierzRodzaj() const;
    Pasazer* pobierzPasazera() const;

    double obliczCeneKoncowa() const;

    void zarezerwuj(Pasazer* p);
    void zwolnij();
};