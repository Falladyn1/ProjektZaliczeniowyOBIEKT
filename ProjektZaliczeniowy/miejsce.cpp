#include "miejsce.h"
#include <sstream>

miejsce::miejsce(int nr, int rz, char kol, TypMiejsca rodz, bool przedzial, bool stolik)
    : numerMiejsca(nr), rzad(rz), kolumna(kol), rodzaj(rodz),
    czyPrzedzial(przedzial), czyStolik(stolik), dostepnosc(true) {
}

bool miejsce::czyWolne() const {
    return dostepnosc;
}

int miejsce::pobierzNumer() const {
    return numerMiejsca;
}

void miejsce::zarezerwuj() {
    if (dostepnosc) {
        dostepnosc = false;
    }
}

void miejsce::zwolnij() {
    dostepnosc = true;
}

