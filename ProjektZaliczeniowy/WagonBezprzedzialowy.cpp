#include "WagonBezprzedzialowy.h"
#include <iostream>

using namespace std;

WagonBezprzedzialowy::WagonBezprzedzialowy(int _nr)
    : Wagon(_nr, 60.0) { // Cena 60 zl
    generujMiejsca();
}

void WagonBezprzedzialowy::generujMiejsca() {
    // 10 rzedow po 4 miejsca = 40 miejsc
    for (int i = 1; i <= 40; ++i) {
        TypMiejsca typ = TypMiejsca::KORYTARZ;
        if (i % 4 == 1 || i % 4 == 0) typ = TypMiejsca::OKNO;

        siedzenia.push_back(Miejsce(i, typ, cenaZaMiejsce));
    }
}

void WagonBezprzedzialowy::wyswietlSchemat() {
    cout << "\n--- WAGON BEZPRZEDZIALOWY NR " << numerWagonu << " (Klasa 2) ---\n";
    cout << "Uklad: [OKNO KORYTARZ KORYTARZ OKNO]\n";
}