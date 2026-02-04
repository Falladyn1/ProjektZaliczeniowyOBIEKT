#pragma once
#include <string>

enum class TypMiejsca { OKNO, SRODEK, KORYTARZ };

class Miejsce {
private:
    int numerMiejsca;
    int rzad;
    char kolumna;
    bool dostepnosc;     // true - wolne, false - zajete
    bool czyPrzedzial;
    bool czyStolik;
    TypMiejsca rodzaj;

public:
    Miejsce(int nr, int rz, char kol, TypMiejsca rodz, bool przedzial, bool stolik);

    bool czyWolne() const;
    bool czyMaStolik() const;
    int pobierzNumer() const;
    TypMiejsca pobierzRodzaj() const;

    void zarezerwuj();
    void zwolnij();
};