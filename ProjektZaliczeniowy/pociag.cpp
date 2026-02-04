#include "pociag.h"
#include <iostream>

using namespace std;

pociag::pociag(string _nazwa) : nazwa(_nazwa) {}

pociag::~pociag() {
    // Poniewa¿ u¿ywamy zwyk³ych wskaŸników, musimy rêcznie usun¹æ wagony
    for (auto w : wagony) {
        delete w;
    }
    wagony.clear();
}

void pociag::dodajWagon(Wagon* w) {
    wagony.push_back(w);
}

void pociag::zarezerwujMiejsce(int nrWagonu, int nrMiejsca) {
    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
            // Szukamy miejsca w wektorze siedzeñ wagonu
            for (auto& m : w->pobierzMiejsca()) {
                if (m.pobierzNumer() == nrMiejsca) {
                    if (m.czyWolne()) {
                        m.zarezerwuj();
                        cout << "Sukces: Zarezerwowano miejsce " << nrMiejsca << ".\n";
                    }
                    else {
                        cout << "Blad: Miejsce " << nrMiejsca << " jest juz zajete.\n";
                    }
                    return;
                }
            }
        }
    }
    cout << "Blad: Nie znaleziono wagonu lub miejsca.\n";
}

void pociag::wyswietlWagon(int nrWagonu) {
    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
            w->wyswietlSchemat(); // Wywo³anie metody rysuj¹cej ASCII Art
            return;
        }
    }
    cout << "Blad: Brak wagonu o numerze " << nrWagonu << ".\n";
}