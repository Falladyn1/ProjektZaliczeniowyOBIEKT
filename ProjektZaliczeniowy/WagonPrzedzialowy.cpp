#include "WagonPrzedzialowy.h"
#include <iostream>
#include <iomanip>

using namespace std;

WagonPrzedzialowy::WagonPrzedzialowy(int _nr)
    : Wagon(_nr), liczbaPrzedzialow(10) {
    klasa = 1;
    cenaZaMiejsce = 100.00;
    generujMiejsca();
}

void WagonPrzedzialowy::generujMiejsca() {
    int licznik = 1;
    for (int i = 0; i < liczbaPrzedzialow; i++) {
        int nrPrzedzialu = i + 1;
        // Przekazujemy cenaZaMiejsce
        siedzenia.push_back(Miejsce(licznik++, nrPrzedzialu, 'A', TypMiejsca::OKNO, true, false, cenaZaMiejsce));
        siedzenia.push_back(Miejsce(licznik++, nrPrzedzialu, 'B', TypMiejsca::SRODEK, true, false, cenaZaMiejsce));
        siedzenia.push_back(Miejsce(licznik++, nrPrzedzialu, 'C', TypMiejsca::KORYTARZ, true, false, cenaZaMiejsce));

        siedzenia.push_back(Miejsce(licznik++, nrPrzedzialu, 'D', TypMiejsca::KORYTARZ, true, false, cenaZaMiejsce));
        siedzenia.push_back(Miejsce(licznik++, nrPrzedzialu, 'E', TypMiejsca::SRODEK, true, false, cenaZaMiejsce));
        siedzenia.push_back(Miejsce(licznik++, nrPrzedzialu, 'F', TypMiejsca::OKNO, true, false, cenaZaMiejsce));
    }
}

void WagonPrzedzialowy::wyswietlSchemat() {
    cout << "\n                WAGON NR " << numerWagonu << " (Przedzialowy 1 kl., Cena podst: " << cenaZaMiejsce << " zl)\n";
    cout << "   +----------------------------------+\n";

    for (int p = 0; p < liczbaPrzedzialow; ++p) {
        int liczbaM = p * 6;
        int nrP = p + 1;

        cout << setw(2) << nrP << " | ";
        for (int i = 0; i < 3; ++i) {
            const Miejsce& m = siedzenia[liczbaM + i];
            if (m.czyWolne()) cout << "[ " << setw(2) << setfill('0') << m.pobierzNumer() << " ]";
            else cout << "[ XX ]";
            if (i < 2) cout << " ";
        }
        cout << " |\n   |                                  |\n   | ";
        int indeksy[] = { 5, 4, 3 };
        for (int i = 0; i < 3; ++i) {
            const Miejsce& m = siedzenia[liczbaM + indeksy[i]];
            if (m.czyWolne()) cout << "[ " << setw(2) << setfill('0') << m.pobierzNumer() << " ]";
            else cout << "[ XX ]";
            if (i < 2) cout << " ";
        }
        cout << " |\n";
        if (p < liczbaPrzedzialow - 1) cout << "   |----------------------------------|\n";
    }
    cout << "   +----------------------------------+\n";
}