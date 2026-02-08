#include "WagonBezprzedzialowy.h"
#include "Wyjatki.h"
#include <iostream>
#include <iomanip>

using namespace std;

WagonBezprzedzialowy::WagonBezprzedzialowy(int _nr) : Wagon(_nr, 60.0) {
    generujMiejsca();
}

void WagonBezprzedzialowy::generujMiejsca() {
    for (int i = 1; i <= 40; ++i) {
        TypMiejsca typ = TypMiejsca::KORYTARZ;
        if (i % 4 == 1 || i % 4 == 0) typ = TypMiejsca::OKNO;
        siedzenia.push_back(Miejsce(i, typ, cenaZaMiejsce));
    }
}

void WagonBezprzedzialowy::wyswietlSchemat() {
    cout << "Wagon " << numerWagonu << " (Bezprzedzialowy):\n";
    for (size_t i = 0; i < siedzenia.size(); ++i) {
        if (siedzenia[i].czyWolne()) {
            ustawKolor(KOLOR_ZIELONY);
            cout << "[" << setw(2) << siedzenia[i].pobierzNumer() << "]";
        }
        else {
            ustawKolor(KOLOR_CZERWONY);
            cout << "[XX]";
        }
        ustawKolor(KOLOR_RESET);

        if ((i + 1) % 4 == 0) cout << "\n";
        else if ((i + 1) % 2 == 0) cout << "   ";
        else cout << " ";
    }
}