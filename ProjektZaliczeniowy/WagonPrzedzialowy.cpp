#include "WagonPrzedzialowy.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

WagonPrzedzialowy::WagonPrzedzialowy(int _nr)
    : Wagon(_nr), liczbaPrzedzialow(5) {
    klasa = 1;
    cenaZaMiejsce = 100.00;
    generujMiejsca();
}

void WagonPrzedzialowy::generujMiejsca() {
    int licznik = 1;
    for (int i = 0; i < liczbaPrzedzialow; i++) {
        int nrP = i + 1;
        for (int j = 0; j < 6; j++) {
            TypMiejsca tm = (j == 0 || j == 5) ? TypMiejsca::OKNO : TypMiejsca::SRODEK;
            siedzenia.push_back(Miejsce(licznik++, nrP, 'X', tm, true, false, cenaZaMiejsce));
        }
    }
}

void WagonPrzedzialowy::wyswietlSchemat() {
    cout << "\n--- WAGON NR " << numerWagonu << " (Przedzialowy) ---\n";
    for (int i = 0; i < siedzenia.size(); i++) {
        if (i % 6 == 0) cout << "Przedzial " << (i / 6 + 1) << ": ";
        cout << "[ " << (siedzenia[i].czyWolne() ? to_string(siedzenia[i].pobierzNumer()) : "XX") << " ] ";
        if ((i + 1) % 6 == 0) cout << "\n";
    }
}