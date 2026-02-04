#include "Pociag.h"
#include <iostream>

using namespace std;

Pociag::Pociag(string _nazwa) : nazwa(_nazwa) {}

Pociag::~Pociag() {
    for (auto w : wagony) {
        delete w;
    }
    wagony.clear();
}

void Pociag::dodajWagon(Wagon* w) {
    wagony.push_back(w);
}

void Pociag::zarezerwujMiejsce(int nrWagonu, int nrMiejsca) {
    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
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

void Pociag::wyswietlWagon(int nrWagonu) {
    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
            w->wyswietlSchemat();
            return;
        }
    }
    cout << "Blad: Brak wagonu o numerze " << nrWagonu << ".\n";
}

string nazwaTypu(TypMiejsca t) {
    switch (t) {
    case TypMiejsca::OKNO: return "Przy oknie";
    case TypMiejsca::KORYTARZ: return "Przy korytarzu";
    case TypMiejsca::SRODEK: return "Srodek";
    default: return "-";
    }
}

void Pociag::znajdzWolneMiejsce(TypMiejsca typ) {
    cout << "Szukam wolnego miejsca: " << nazwaTypu(typ) << "...\n";
    bool znaleziono = false;

    for (auto w : wagony) {
        for (const auto& m : w->pobierzMiejsca()) {
            if (m.czyWolne() && m.pobierzRodzaj() == typ) {
                cout << "Znaleziono! Wagon nr " << w->pobierzNumer()
                    << ", Miejsce nr " << m.pobierzNumer() << endl;
                znaleziono = true;
                // return;
            }
        }
    }
    if (!znaleziono) {
        cout << "Niestety, brak wolnych miejsc tego typu.\n";
    }
}