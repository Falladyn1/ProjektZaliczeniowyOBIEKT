#include "WagonBezprzedzialowy.h"
#include <iostream>
#include <iomanip> 

using namespace std;

WagonBezprzedzialowy::WagonBezprzedzialowy(int _nr) 
    : Wagon(_nr), liczbaRzedow(20) {
    generujMiejsca();
}

void WagonBezprzedzialowy::generujMiejsca() {
    int licznik = 1;
    for (int r = 1; r <= liczbaRzedow; ++r) {
        bool maStolik = (r >= 8 && r <= 11);

        siedzenia.push_back(Miejsce(licznik++, r, 'A', TypMiejsca::OKNO, false, maStolik));
        siedzenia.push_back(Miejsce(licznik++, r, 'B', TypMiejsca::KORYTARZ, false, maStolik));
        siedzenia.push_back(Miejsce(licznik++, r, 'C', TypMiejsca::KORYTARZ, false, maStolik));
        siedzenia.push_back(Miejsce(licznik++, r, 'D', TypMiejsca::OKNO, false, maStolik));
    }
}

void WagonBezprzedzialowy::wyswietlSchemat() {
    cout << "\n                WAGON NR " << numerWagonu << "\n";
    cout << "   +----------------------------------+\n";

    for (int r = 0; r < liczbaRzedow; ++r) {
        int iloscM = r * 4;
        int numerRzedu = r + 1;

        cout << setw(2) << numerRzedu << " | ";

        for (int i = 0; i < 4; ++i) {
            const Miejsce& m = siedzenia[iloscM + i];

            if (m.czyWolne()) {
                cout << "[ " << setw(2) << setfill('0') << m.pobierzNumer() << " ]";
            }
            else {
                cout << "[ XX ]";
            }

            if (i == 0 || i == 2) cout << " ";
            if (i == 1) cout << "       "; 
        }
        cout << "|\n";
        cout << setfill(' ');

        if (numerRzedu == 8 || numerRzedu == 10) {
            cout << "   |  __STOLIK__          __STOLIK__  |\n";
        }
    }
    cout << "   +----------------------------------+\n";
}