#pragma once
#include "Pasazer.h"

enum TypMiejsca { OKNO, SRODEK, KORYTARZ };

class Miejsce {
private:
    int numerMiejsca;
    TypMiejsca rodzaj;
    double cenaBazowa;
    Pasazer* pasazer;

public:
    Miejsce(int nr, TypMiejsca r, double cena);
    ~Miejsce();
    bool czyWolne();
    int pobierzNumer();
    TypMiejsca pobierzRodzaj();
    Pasazer* pobierzPasazera();
    double obliczCeneKoncowa();

    void zarezerwuj(Pasazer* p);
    void zwolnij();
};