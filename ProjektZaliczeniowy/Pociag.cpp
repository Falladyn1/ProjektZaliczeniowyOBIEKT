#include "Pociag.h"
#include "Wyjatki.h"
#include <iostream>
#include <fstream>

using namespace std;

Pociag::Pociag(string _nazwa, Trasa _trasa)
    : nazwa(_nazwa), trasa(_trasa) {
}

Pociag::~Pociag() {
    for (auto w : wagony) delete w;
    wagony.clear();
}

void Pociag::dodajWagon(Wagon* w) {
    wagony.push_back(w);
}

void Pociag::pokazPodgladPociagu() {
    ustawKolor(KOLOR_ZOLTY);
    cout << "POCIAG: " << nazwa << "\n";
    ustawKolor(KOLOR_RESET);

    // Wyswietlanie trasy
    trasa.wyswietlPrzebieg();

    for (auto w : wagony) {
        w->wyswietlSchemat();
        cout << "\n";
    }
}

void Pociag::zarezerwujMiejsce(int nrWagonu, int nrMiejsca) {
    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
            for (auto& m : w->pobierzMiejsca()) {
                if (m.pobierzNumer() == nrMiejsca) {
                    if (!m.czyWolne()) throw MiejsceZajeteException(nrMiejsca);

                    string imie, nazwisko;
                    int wyborUlgi;
                    cout << "Imie: "; cin >> imie;
                    cout << "Nazwisko: "; cin >> nazwisko;
                    cout << "Ulga (1-Student, 2-Senior, 0-Brak): "; cin >> wyborUlgi;

                    TypUlgi ulga = TypUlgi::NORMALNY;
                    if (wyborUlgi == 1) ulga = TypUlgi::STUDENT;
                    else if (wyborUlgi == 2) ulga = TypUlgi::SENIOR;

                    m.zarezerwuj(new Pasazer(imie, nazwisko, ulga));
                    return;
                }
            }
            throw NieznalezionoElementuException("Brak miejsca.");
        }
    }
    throw NieznalezionoElementuException("Brak wagonu.");
}

void Pociag::anulujRezerwacje(int nrWagonu, int nrMiejsca) {
    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
            for (auto& m : w->pobierzMiejsca()) {
                if (m.pobierzNumer() == nrMiejsca) {
                    if (m.czyWolne()) throw logic_error("To miejsce jest wolne!");
                    m.zwolnij();
                    ustawKolor(KOLOR_ZIELONY);
                    cout << "Rezerwacja anulowana.\n";
                    ustawKolor(KOLOR_RESET);
                    return;
                }
            }
        }
    }
    throw NieznalezionoElementuException("Nie znaleziono miejsca.");
}

void Pociag::znajdzWolneMiejsce(int tryb) {
    TypMiejsca szukany = (tryb == 1) ? TypMiejsca::OKNO : TypMiejsca::SRODEK;
    cout << "Szukam...\n";

    for (auto w : wagony) {
        for (const auto& m : w->pobierzMiejsca()) {
            bool pasuje = (m.pobierzRodzaj() == szukany);
            if (tryb == 2 && m.pobierzRodzaj() != TypMiejsca::OKNO) pasuje = true;

            if (m.czyWolne() && pasuje) {
                ustawKolor(KOLOR_ZOLTY);
                cout << "ZNALEZIONO: Wagon " << w->pobierzNumer() << " Miejsce " << m.pobierzNumer() << "\n";
                ustawKolor(KOLOR_RESET);
                return;
            }
        }
    }
    cout << "Brak miejsc tego typu.\n";
}

void Pociag::wyswietlListePasazerow() {
    cout << "--- LISTA PASAZEROW ---\n";
    for (auto w : wagony) {
        for (const auto& m : w->pobierzMiejsca()) {
            if (!m.czyWolne()) {
                cout << "Wagon " << w->pobierzNumer() << " M " << m.pobierzNumer() << " | ";
                cout << *(m.pobierzPasazera()) << "\n";
            }
        }
    }
}

void Pociag::zapiszStanDoPliku() {
    ofstream plik("baza_danych.txt");
    if (!plik.is_open()) return;

    for (auto w : wagony) {
        for (const auto& m : w->pobierzMiejsca()) {
            if (!m.czyWolne()) {
                Pasazer* p = m.pobierzPasazera();
                int ulgaInt = 0;
                if (p->pobierzUlge() == TypUlgi::STUDENT) ulgaInt = 1;
                if (p->pobierzUlge() == TypUlgi::SENIOR) ulgaInt = 2;

                plik << w->pobierzNumer() << " " << m.pobierzNumer() << " "
                    << p->pobierzImie() << " " << p->pobierzNazwisko() << " " << ulgaInt << "\n";
            }
        }
    }
    plik.close();
    cout << "Zapisano dane.\n";
}

void Pociag::wczytajStanZPliku() {
    ifstream plik("baza_danych.txt");
    if (!plik.is_open()) return;

    int w, m, u;
    string imie, nazwisko;
    while (plik >> w >> m >> imie >> nazwisko >> u) {
        TypUlgi ulga = TypUlgi::NORMALNY;
        if (u == 1) ulga = TypUlgi::STUDENT;
        if (u == 2) ulga = TypUlgi::SENIOR;

        for (auto wag : wagony) {
            if (wag->pobierzNumer() == w) {
                for (auto& mies : wag->pobierzMiejsca()) {
                    if (mies.pobierzNumer() == m) {
                        mies.zarezerwuj(new Pasazer(imie, nazwisko, ulga));
                    }
                }
            }
        }
    }
    plik.close();
}