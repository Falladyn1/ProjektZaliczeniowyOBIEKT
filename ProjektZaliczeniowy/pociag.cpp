#include "Pociag.h"
#include "Wyjatki.h"
#include <iostream>
#include <fstream>

using namespace std;

Pociag::Pociag(string _nazwa, Trasa _trasa) : nazwa(_nazwa), trasa(_trasa) {}
Pociag::~Pociag() { for (auto w : wagony) delete w; }

void Pociag::dodajWagon(Wagon* w) { wagony.push_back(w); }

void Pociag::pokazPodgladPociagu() {
    ustawKolor(KOLOR_ZOLTY);
    cout << "POCIAG: " << nazwa << "\n";
    ustawKolor(KOLOR_RESET);
    trasa.wyswietlPrzebieg();
    for (auto w : wagony) { w->wyswietlSchemat(); cout << "\n"; }
}

void Pociag::zarezerwujMiejsce(int nrWagonu, int nrMiejsca) {
    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
            for (auto& m : w->pobierzMiejsca()) {
                if (m.pobierzNumer() == nrMiejsca) {
                    if (!m.czyWolne()) { cout << "Miejsce zajete!\n"; return; }
                    string imie, nazwisko; int u;
                    cout << "Imie: "; cin >> imie;
                    cout << "Nazwisko: "; cin >> nazwisko;
                    cout << "Ulga (1-Student, 2-Senior, 0-Brak): "; cin >> u;
                    TypUlgi ulga = (u == 1) ? TypUlgi::STUDENT : (u == 2 ? TypUlgi::SENIOR : TypUlgi::NORMALNY);
                    m.zarezerwuj(new Pasazer(imie, nazwisko, ulga));
                    return;
                }
            }
        }
    }
    cout << "Nie znaleziono miejsca/wagonu.\n";
}

void Pociag::wyswietlListePasazerow() {
    for (auto w : wagony) {
        for (const auto& m : w->pobierzMiejsca()) {
            if (!m.czyWolne()) cout << "Wagon " << w->pobierzNumer() << " M " << m.pobierzNumer() << " | " << *(m.pobierzPasazera()) << "\n";
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
                int u = (p->ulga_get() == TypUlgi::STUDENT) ? 1 : (p->ulga_get() == TypUlgi::SENIOR ? 2 : 0);
                plik << w->pobierzNumer() << " " << m.pobierzNumer() << " " << p->pobierzImie() << " " << p->pobierzNazwisko() << " " << u << "\n";
            }
        }
    }
}

void Pociag::wczytajStanZPliku() {
    ifstream plik("baza_danych.txt");
    if (!plik.is_open()) return;
    int w, m, u; string i, n;
    while (plik >> w >> m >> i >> n >> u) {
        for (auto wag : wagony) {
            if (wag->pobierzNumer() == w) {
                for (auto& mies : wag->pobierzMiejsca()) {
                    if (mies.pobierzNumer() == m) mies.zarezerwuj(new Pasazer(i, n, (u == 1 ? TypUlgi::STUDENT : (u == 2 ? TypUlgi::SENIOR : TypUlgi::NORMALNY))));
                }
            }
        }
    }
}