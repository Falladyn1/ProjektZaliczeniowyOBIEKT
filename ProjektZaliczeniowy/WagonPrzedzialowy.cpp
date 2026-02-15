#include "WagonPrzedzialowy.h"
#include "Wyjatki.h"
#include <iostream>
#include <iomanip>

using namespace std;

WagonPrzedzialowy::WagonPrzedzialowy(int _nr) : Wagon(_nr, 100.0) {
    generujMiejsca();
}

void WagonPrzedzialowy::generujMiejsca() {
    for (int i = 1; i <= 30; ++i) {
        TypMiejsca typ = SRODEK;
        if (i % 6 == 1 || i % 6 == 0) typ = OKNO;
        siedzenia.push_back(Miejsce(i, typ, cenaZaMiejsce));
    }
}

void WagonPrzedzialowy::wyswietlSchemat() {
    cout << "Wagon " << numerWagonu << " (Przedzialowy):\n";

    int iloscPrzedzialow = (int)siedzenia.size() / 6;

    for (int p = 0; p < iloscPrzedzialow; ++p) {
        int start = p * 6;
        cout << " P" << p + 1 << " ";

        for (int i = 0; i < 3; ++i) {
            int idx = start + i;
            if (siedzenia[idx].czyWolne()) {
                ustawKolor(KOLOR_ZIELONY);
                cout << "[" << setw(2) << siedzenia[idx].pobierzNumer() << "]";
            }
            else {
                ustawKolor(KOLOR_CZERWONY);
                cout << "[XX]";
            }
            ustawKolor(KOLOR_RESET);
        }
        cout << "\n    ";

        for (int i = 5; i >= 3; --i) {
            int idx = start + i;
            if (siedzenia[idx].czyWolne()) {
                ustawKolor(KOLOR_ZIELONY);
                cout << "[" << setw(2) << siedzenia[idx].pobierzNumer() << "]";
            }
            else {
                ustawKolor(KOLOR_CZERWONY);
                cout << "[XX]";
            }
            ustawKolor(KOLOR_RESET);
        }
        cout << "\n\n";
    }
}