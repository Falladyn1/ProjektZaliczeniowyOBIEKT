#pragma once
#include <string>

enum class TypMiejsca { OKNO, SRODEK, KORYTARZ };

class miejsce {
private:
    int numerMiejsca;
    int rzad;          
    char kolumna;      
    bool dostepnosc;
    bool czyPrzedzial;
    bool czyStolik;
    TypMiejsca rodzaj;

public:
    miejsce(int nr, int rz, char kol, TypMiejsca rodü, bool przedzial, bool stolik);

    bool czyWolne() const;
    int pobierzNumer() const;
    void zarezerwuj();
    void zwolnij();
};