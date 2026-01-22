#include "Miejsce.h"
#include <sstream>

Miejsce::Miejsce(int nr, int rz, char kol, TypMiejsca rodz, bool przedzial, bool stolik)
    : numerMiejsca(nr), rzad(rz), kolumna(kol), rodzaj(rodz),
    czyPrzedzial(przedzial), czyStolik(stolik), dostepnosc(true) {
}

bool Miejsce::czyWolne() const {
    return dostepnosc;
}

int Miejsce::pobierzNumer() const {
    return numerMiejsca;
}

void Miejsce::zarezerwuj() {
    if (dostepnosc) {
        dostepnosc = false;
    }
}

void Miejsce::zwolnij() {
    dostepnosc = true;
}

