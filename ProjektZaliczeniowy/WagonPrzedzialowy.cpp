#include "WagonPrzedzialowy.h"
#include <iostream>

using namespace std;

WagonPrzedzialowy::WagonPrzedzialowy(int _nr)
    : Wagon(_nr, 100.0) {
    generujMiejsca();
}

void WagonPrzedzialowy::generujMiejsca() {
    for (int i = 1; i <= 30; ++i) {
        TypMiejsca typ = TypMiejsca::SRODEK;
        if (i % 6 == 1 || i % 6 == 0) typ = TypMiejsca::OKNO;

        siedzenia.push_back(Miejsce(i, typ, cenaZaMiejsce));
    }
}

void WagonPrzedzialowy::wyswietlSchemat() {
    cout << "\n--- WAGON PRZEDZIALOWY NR " << numerWagonu << " (Klasa 1) ---\n";
    cout << "Uklad: [OKNO SRODEK SRODEK ...]\n";
}