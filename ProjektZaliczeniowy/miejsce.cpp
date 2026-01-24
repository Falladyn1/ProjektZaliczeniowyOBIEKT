#include "Miejsce.h"

Miejsce::Miejsce(int nr, int rz, char kol, TypMiejsca rodz, bool przedzial, bool stolik)
    : numerMiejsca(nr), rzad(rz), kolumna(kol), rodzaj(rodz),
    czyPrzedzial(przedzial), czyStolik(stolik), dostepnosc(true) {
}

bool Miejsce::czyWolne() const {
    return dostepnosc;
}

bool Miejsce::czyMaStolik() const {
    return czyStolik;
}

int Miejsce::pobierzNumer() const {
    return numerMiejsca;
}

TypMiejsca Miejsce::pobierzRodzaj() const {
    return rodzaj;
}

void Miejsce::zarezerwuj() {
    if (dostepnosc) {
        dostepnosc = false;
    }
}

void Miejsce::zwolnij() {
    dostepnosc = true;
}