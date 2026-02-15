#include "System.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h"
#include "Wyjatki.h"
#include <iostream>

using namespace std;

System::System() { inicjalizujDane(); }
System::~System() { for (auto p : pociagi) delete p; }

void System::inicjalizujDane() {
    Trasa t1("Warszawa -> Gdynia");
    t1.dodajStacje("Warszawa"); t1.dodajStacje("Gdynia");
    Pociag* p1 = new Pociag("IC Neptun", t1);
    p1->dodajWagon(new WagonBezprzedzialowy(1));
    p1->wczytajStanZPliku();
    pociagi.push_back(p1);
    wyszukiwarka.dodajPociag(p1);
}

void System::uruchom() {
    int o = -1;
    do {
        system("cls");
        cout << "1. Rezerwacja\n2. Lista\n0. Wyjscie\nWybor: ";
        if (!(cin >> o)) { cin.clear(); cin.ignore(100, '\n'); continue; }
        if (o == 1) obslugaRezerwacji();
        else if (o == 2) { for (auto p : pociagi) p->wyswietlListePasazerow(); cin.ignore(); cin.get(); }
    } while (o != 0);
}

void System::obslugaRezerwacji() {
    string s, d;
    cout << "Skad: "; cin >> s; cout << "Dokad: "; cin >> d;
    auto wyniki = wyszukiwarka.znajdzPolaczenia(s, d);
    if (wyniki.empty()) return;
    wyniki[0]->pokazPodgladPociagu();
    int w, m;
    cout << "Wagon: "; cin >> w; cout << "Miejsce: "; cin >> m;
    wyniki[0]->zarezerwujMiejsce(w, m);
}