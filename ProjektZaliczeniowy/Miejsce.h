#pragma once
#include "Pasazer.h"

enum class TypMiejsca { OKNO, SRODEK, KORYTARZ };

class Miejsce {
private:
    int numerMiejsca;
    int rzad;
    char kolumna;
    bool czyPrzedzial;
    bool czyStolik;
    TypMiejsca rodzaj;

    double cenaBazowa;
    Pasazer* pasazer;

public:
    Miejsce(int nr, int rz, char kol, TypMiejsca rodz, bool przedzial, bool stolik, double cena);
    ~Miejsce();

    bool czyWolne() const;
    int pobierzNumer() const;
    TypMiejsca pobierzRodzaj() const;

    double obliczCeneKoncowa() const;

    // Zwraca wskaznik na pasazera (potrzebne do rejestru)
    Pasazer* pobierzPasazera() const;

    void zarezerwuj(Pasazer* nowyPasazer);
    void zwolnij();
};