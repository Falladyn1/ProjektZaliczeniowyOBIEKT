#include "WagonBezprzedzialowy.h"
#include "Wyjatki.h"
#include <iostream>
#include <iomanip>

using namespace std;

WagonBezprzedzialowy::WagonBezprzedzialowy(int nr) : Wagon(nr, 60.0) {
    generujMiejsca();
}

void WagonBezprzedzialowy::generujMiejsca() {
    for (int i = 1; i <= 40; i++) {
        TypMiejsca typ;
        if (i % 4 == 1 || i % 4 == 0) {
            typ = OKNO;
        }
        else {
            typ = KORYTARZ;
        }

        Miejsce noweMiejsce(i, typ, cenaZaMiejsce);
        siedzenia.push_back(noweMiejsce);
    }
}

void WagonBezprzedzialowy::wyswietlSchemat() {
    cout << "Wagon " << numerWagonu << " (Bezprzedzialowy):" << endl;
    for (int i = 0; i < siedzenia.size(); i++) {
        if (siedzenia[i].czyWolne() == true) {
            ustawKolor(KOLOR_ZIELONY);
            cout << "[" << setw(2) << siedzenia[i].pobierzNumer() << "]";
        }
        else {
            ustawKolor(KOLOR_CZERWONY);
            cout << "[XX]";
        }
        ustawKolor(KOLOR_RESET);

        // Formatowanie wyswietlania
        if ((i + 1) % 4 == 0) {
            cout << endl;
        }
        else if ((i + 1) % 2 == 0) {
            cout << "   ";
        }
        else {
            cout << " ";
        }
    }
}