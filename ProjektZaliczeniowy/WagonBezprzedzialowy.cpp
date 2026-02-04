#include "WagonBezprzedzialowy.h"
#include <iostream>
#include <iomanip>

WagonBezprzedzialowy::WagonBezprzedzialowy(int _nr) : Wagon(_nr), liczbaRzedow(20) {
    generujMiejsca();
}

void WagonBezprzedzialowy::generujMiejsca() {
    int licznikNumeru = 1;

    for (int r = 1; r <= liczbaRzedow; ++r) {

        bool czyJestStolik = false;

        if (r >= 8 && r <= 11) {
            czyJestStolik = true;
        }

        //A - okno B - korytarz |przejscie| C - korytarz D -okno
        siedzenia.push_back(Miejsce(licznikNumeru++, r, 'A', TypMiejsca::OKNO, false, czyJestStolik));
        siedzenia.push_back(Miejsce(licznikNumeru++, r, 'B', TypMiejsca::KORYTARZ, false, czyJestStolik));
        siedzenia.push_back(Miejsce(licznikNumeru++, r, 'C', TypMiejsca::KORYTARZ, false, czyJestStolik));
        siedzenia.push_back(Miejsce(licznikNumeru++, r, 'D', TypMiejsca::OKNO, false, czyJestStolik));
    }
}

void rysujSiedzenie(const Miejsce& m) {
    if (m.czyWolne()) {
        std::cout << "[ " << std::setw(2) << std::setfill('0') << m.pobierzNumer() << " ]";
    }
    else {
        std::cout << "[ XX ]";
    }
}

void WagonBezprzedzialowy::wyswietlSchemat() {
    std::cout << "\n      SCHEMAT WAGONU NR " << numerWagonu << "\n";
    std::cout << "      (A)    (B)           (C)    (D)\n";
    std::cout << "     OKNO  KORYTARZ      KORYTARZ OKNO\n";
    std::cout << "   +------------------------------------+\n";


    for (int r = 0; r < liczbaRzedow; ++r) {
        int idx = r * 4;

        std::cout << std::setw(2) << std::setfill(' ') << (r + 1) << " | ";

        // Miejsce A
        rysujSiedzenie(siedzenia[idx]);
        std::cout << " ";

        // Miejsce B
        rysujSiedzenie(siedzenia[idx + 1]);

        if (siedzenia[idx].czyMaStolik()) {
            std::cout << " _STOL_ ";
        }
        else {
            std::cout << "        "; 
        }

        // Miejsce C
        rysujSiedzenie(siedzenia[idx + 2]);
        std::cout << " ";

        // Miejsce D
        rysujSiedzenie(siedzenia[idx + 3]);

        std::cout << " |\n";
    }
    std::cout << "   +------------------------------------+\n";
    std::cout << "     LEGENDA: [XX] - Zajete, _STOL_ - Stolik\n\n";
}