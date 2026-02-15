#include "Pociag.h"
#include "Wyjatki.h"
#include <iostream>
#include <fstream>

using namespace std;

Pociag::Pociag(string n, string g, Trasa t) : trasa(t) {
    nazwa = n;
    godzinaOdjazdu = g;
}

Pociag::~Pociag() {
    for (int i = 0; i < wagony.size(); i++) {
        delete wagony[i];
    }
    wagony.clear();
}

void Pociag::dodajWagon(Wagon* w) {
    wagony.push_back(w);
}

void Pociag::pokazPodgladPociagu() {
    ustawKolor(KOLOR_ZOLTY);
    cout << "POCIAG: " << nazwa << " | ODJAZD: " << godzinaOdjazdu << endl;
    ustawKolor(KOLOR_RESET);

    trasa.wyswietlPrzebieg();

    for (int i = 0; i < wagony.size(); i++) {
        wagony[i]->wyswietlSchemat();
        cout << endl;
    }
}

void Pociag::zarezerwujMiejsce(int nrWagonu, int nrMiejsca) {
    // Podwojna petla - typowe na laboratoriach z wektorami klas
    for (int i = 0; i < wagony.size(); i++) {
        if (wagony[i]->pobierzNumer() == nrWagonu) {

            for (int j = 0; j < wagony[i]->pobierzMiejsca().size(); j++) {
                if (wagony[i]->pobierzMiejsca()[j].pobierzNumer() == nrMiejsca) {

                    if (wagony[i]->pobierzMiejsca()[j].czyWolne() == false) {
                        throw BladRezerwacji("Miejsce jest juz zajete!");
                    }

                    string imie, nazwisko;
                    int wyborUlgi;
                    cout << "Imie: "; cin >> imie;
                    cout << "Nazwisko: "; cin >> nazwisko;
                    cout << "Ulga (1-Student, 2-Senior, 0-Brak): ";

                    if (!(cin >> wyborUlgi)) {
                        cin.clear(); cin.ignore(1000, '\n');
                        throw BladDanych("Nieprawidlowy format ulgi!");
                    }

                    TypUlgi ulga;
                    if (wyborUlgi == 1) ulga = STUDENT;
                    else if (wyborUlgi == 2) ulga = SENIOR;
                    else ulga = NORMALNY;

                    Pasazer* nowyPasazer = new Pasazer(imie, nazwisko, ulga);
                    wagony[i]->pobierzMiejsca()[j].zarezerwuj(nowyPasazer);

                    ustawKolor(KOLOR_ZIELONY);
                    cout << "SUKCES: Miejsce zarezerwowane." << endl;
                    ustawKolor(KOLOR_RESET);
                    return;
                }
            }
            throw BladRezerwacji("Brak miejsca o numerze " + to_string(nrMiejsca) + "\n");
        }
    }
    throw BladRezerwacji("Brak wagonu o numerze " + to_string(nrWagonu) + "\n");
}

void Pociag::anulujRezerwacje(int nrWagonu, int nrMiejsca) {
    for (int i = 0; i < wagony.size(); i++) {
        if (wagony[i]->pobierzNumer() == nrWagonu) {

            for (int j = 0; j < wagony[i]->pobierzMiejsca().size(); j++) {
                if (wagony[i]->pobierzMiejsca()[j].pobierzNumer() == nrMiejsca) {

                    if (wagony[i]->pobierzMiejsca()[j].czyWolne() == true) {
                        throw BladRezerwacji("To miejsce jest juz wolne!");
                    }

                    wagony[i]->pobierzMiejsca()[j].zwolnij();
                    ustawKolor(KOLOR_ZIELONY);
                    cout << "Rezerwacja anulowana." << endl;
                    ustawKolor(KOLOR_RESET);
                    return;
                }
            }
            throw BladRezerwacji("Brak miejsca o numerze " + to_string(nrMiejsca) + "\n");
        }
    }
    throw BladRezerwacji("Brak wagonu o numerze " + to_string(nrWagonu) + "\n");
}

void Pociag::wyswietlListePasazerow() {
    for (int i = 0; i < wagony.size(); i++) {
        for (int j = 0; j < wagony[i]->pobierzMiejsca().size(); j++) {

            if (wagony[i]->pobierzMiejsca()[j].czyWolne() == false) {
                cout << "Wagon " << wagony[i]->pobierzNumer() << " M "
                    << wagony[i]->pobierzMiejsca()[j].pobierzNumer() << " | ";

                Pasazer* p = wagony[i]->pobierzMiejsca()[j].pobierzPasazera();
                cout << *p << endl;
            }
        }
    }
}

void Pociag::zapiszStanDoPliku() {
    ofstream plik("baza_danych.txt", ios::app);
    if (plik.is_open() == false) return;

    for (int i = 0; i < wagony.size(); i++) {
        for (int j = 0; j < wagony[i]->pobierzMiejsca().size(); j++) {

            if (wagony[i]->pobierzMiejsca()[j].czyWolne() == false) {
                Pasazer* p = wagony[i]->pobierzMiejsca()[j].pobierzPasazera();

                int ulgaInt = 0;
                if (p->pobierzUlge() == STUDENT) ulgaInt = 1;
                else if (p->pobierzUlge() == SENIOR) ulgaInt = 2;

                plik << nazwa << " " << wagony[i]->pobierzNumer() << " "
                    << wagony[i]->pobierzMiejsca()[j].pobierzNumer() << " "
                    << p->pobierzImie() << " " << p->pobierzNazwisko() << " "
                    << ulgaInt << endl;
            }
        }
    }
    plik.close();
}

void Pociag::wczytajStanZPliku() {
    ifstream plik("baza_danych.txt");
    if (plik.is_open() == false) return;

    string wNazwa, imie, nazwisko;
    int w, m, u;

    while (plik >> wNazwa >> w >> m >> imie >> nazwisko >> u) {
        if (wNazwa != nazwa) {
            continue; // Pomijamy jak to nie ten pociag
        }

        TypUlgi ulga;
        if (u == 1) ulga = STUDENT;
        else if (u == 2) ulga = SENIOR;
        else ulga = NORMALNY;

        for (int i = 0; i < wagony.size(); i++) {
            if (wagony[i]->pobierzNumer() == w) {
                for (int j = 0; j < wagony[i]->pobierzMiejsca().size(); j++) {
                    if (wagony[i]->pobierzMiejsca()[j].pobierzNumer() == m) {
                        Pasazer* nowyPasazer = new Pasazer(imie, nazwisko, ulga);
                        wagony[i]->pobierzMiejsca()[j].zarezerwuj(nowyPasazer);
                    }
                }
            }
        }
    }
    plik.close();
}

string Pociag::pobierzNazwe() { return nazwa; }
string Pociag::pobierzGodzine() { return godzinaOdjazdu; }
Trasa& Pociag::pobierzTrase() { return trasa; }