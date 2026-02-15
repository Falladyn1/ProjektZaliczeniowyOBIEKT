#include "WagonPrzedzialowy.h"
#include "Wyjatki.h"
#include <iostream>
#include <iomanip>

using namespace std;

WagonPrzedzialowy::WagonPrzedzialowy(int nr) : Wagon(nr, 100.0) {
    generujMiejsca();
}

void WagonPrzedzialowy::generujMiejsca() {
    for (int i = 1; i <= 30; i++) {
        TypMiejsca typ;
        if (i % 6 == 1 || i % 6 == 0) {
            typ = OKNO;
        }
        else {
            typ = SRODEK;
        }

        Miejsce noweMiejsce(i, typ, cenaZaMiejsce);
        siedzenia.push_back(noweMiejsce);
    }
}

void WagonPrzedzialowy::wyswietlSchemat() {
    cout << "Wagon " << numerWagonu << " (Przedzialowy):" << endl;
    int iloscPrzedzialow = siedzenia.size() / 6;

    for (int p = 0; p < iloscPrzedzialow; p++) {
        int start = p * 6;
        cout << " P" << p + 1 << " ";

        // Gorny rzad
        for (int i = 0; i < 3; i++) {
            if (siedzenia[start + i].czyWolne() == true) {
                ustawKolor(KOLOR_ZIELONY);
                cout << "[" << setw(2) << siedzenia[start + i].pobierzNumer() << "]";
            }
            else {
                ustawKolor(KOLOR_CZERWONY);
                cout << "[XX]";
            }
            ustawKolor(KOLOR_RESET);
        }
        cout << endl << "    ";

        // Dolny rzad
        for (int i = 5; i >= 3; i--) {
            if (siedzenia[start + i].czyWolne() == true) {
                ustawKolor(KOLOR_ZIELONY);
                cout << "[" << setw(2) << siedzenia[start + i].pobierzNumer() << "]";
            }
            else {
                ustawKolor(KOLOR_CZERWONY);
                cout << "[XX]";
            }
            ustawKolor(KOLOR_RESET);
        }
        cout << endl << endl;
    }
}