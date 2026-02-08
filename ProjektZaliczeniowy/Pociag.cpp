#include "Pociag.h"
#include <iostream>
#include <iomanip>

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
                        cout << "--- REZERWACJA MIEJSCA " << nrMiejsca << " ---\n";
                        string imie, nazwisko;
                        int typ;
                        cout << "Podaj imie: "; cin >> imie;
                        cout << "Podaj nazwisko: "; cin >> nazwisko;
                        cout << "Wybierz ulge (1-Student, 2-Senior, inne-Normalny): ";
                        cin >> typ;

                        TypUlgi ulga = TypUlgi::NORMALNY;
                        if (typ == 1) ulga = TypUlgi::STUDENT;
                        else if (typ == 2) ulga = TypUlgi::SENIOR;

                        // Tworzymy pasazera i przypisujemy do miejsca
                        Pasazer* p = new Pasazer(imie, nazwisko, ulga);
                        m.zarezerwuj(p);

                        cout << "SUKCES! Zarezerwowano dla: " << p->pobierzPelneInfo() << "\n";
                        cout << "Cena biletu: " << fixed << setprecision(2) << m.obliczCeneKoncowa() << " PLN\n";
                    }
                    else {
                        cout << "BLAD: Miejsce zajete przez: " << m.pobierzInfoPasazera() << ".\n";
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
                    << ", Miejsce nr " << m.pobierzNumer()
                    << " (Cena: " << m.obliczCeneKoncowa() << " zl)" << endl;
                znaleziono = true;
            }
        }
    }
    if (!znaleziono) cout << "Brak wolnych miejsc tego typu.\n";
}

void Pociag::wyswietlListePasazerow() {
    cout << "\n=== LISTA PASAZEROW W POCIAGU " << nazwa << " ===\n";
    bool pusty = true;
    for (auto w : wagony) {
        for (const auto& m : w->pobierzMiejsca()) {
            if (!m.czyWolne()) {
                pusty = false;
                cout << "Wagon " << w->pobierzNumer() << ", Miejsce " << m.pobierzNumer()
                    << ": " << m.pobierzInfoPasazera() << endl;
            }
        }
    }
    if (pusty) cout << "(Pociag jest pusty)\n";
}