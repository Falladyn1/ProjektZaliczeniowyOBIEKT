#include "WagonBezprzedzialowy.h"
#include <iostream>
#include <iomanip>

using namespace std;

WagonBezprzedzialowy::WagonBezprzedzialowy(int _nr)
    : Wagon(_nr), liczbaRzedow(10) {
    klasa = 2;
    cenaZaMiejsce = 60.00;
    generujMiejsca();
}

void WagonBezprzedzialowy::generujMiejsca() {
    int licznik = 1;
    for (int r = 1; r <= liczbaRzedow; ++r) {
        bool maStolik = (r % 2 == 0);
        siedzenia.push_back(Miejsce(licznik++, r, 'A', TypMiejsca::OKNO, false, maStolik, cenaZaMiejsce));
        siedzenia.push_back(Miejsce(licznik++, r, 'B', TypMiejsca::KORYTARZ, false, maStolik, cenaZaMiejsce));
        siedzenia.push_back(Miejsce(licznik++, r, 'C', TypMiejsca::KORYTARZ, false, maStolik, cenaZaMiejsce));
        siedzenia.push_back(Miejsce(licznik++, r, 'D', TypMiejsca::OKNO, false, maStolik, cenaZaMiejsce));
    }
}

void WagonBezprzedzialowy::wyswietlSchemat() {
    cout << "\n--- WAGON NR " << numerWagonu << " (Bezprzedzialowy) ---\n";
    for (const auto& m : siedzenia) {
        if (m.pobierzNumer() % 4 == 1) cout << "Rzad " << (m.pobierzNumer() / 4 + 1) << ": ";
        cout << "[ " << (m.czyWolne() ? to_string(m.pobierzNumer()) : "XX") << " ] ";
        if (m.pobierzNumer() % 4 == 0) cout << "\n";
    }
}