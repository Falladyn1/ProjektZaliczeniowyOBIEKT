#include "System.h"
#include "Trasa.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h"
#include "Wyjatki.h"
#include <iostream>
#include <cstdlib> 
#include <fstream> // Doda³em to, co naprawia b³êdy C2079 i E0070

using namespace std;

System::System() {
    inicjalizujDane();
}

System::~System() {
    for (auto p : pociagi) {
        delete p;
    }
    pociagi.clear();
}

void System::inicjalizujDane() {
    Trasa trasaIC("Warszawa -> Gdynia");
    trasaIC.dodajStacje("Warszawa");
    trasaIC.dodajStacje("Ilawa");
    trasaIC.dodajStacje("Malbork");
    trasaIC.dodajStacje("Gdansk");
    trasaIC.dodajStacje("Gdynia");

    Pociag* p1 = new Pociag("IC Neptun", trasaIC);
    p1->dodajWagon(new WagonBezprzedzialowy(1));
    p1->dodajWagon(new WagonPrzedzialowy(2));
    p1->wczytajStanZPliku();

    Trasa trasaEIP("Krakow -> Warszawa");
    trasaEIP.dodajStacje("Krakow");
    trasaEIP.dodajStacje("Warszawa");

    Pociag* p2 = new Pociag("EIP Poludnie", trasaEIP);
    p2->dodajWagon(new WagonBezprzedzialowy(1));
    p2->dodajWagon(new WagonPrzedzialowy(2));

    pociagi.push_back(p1);
    pociagi.push_back(p2);

    wyszukiwarka.dodajPociag(p1);
    wyszukiwarka.dodajPociag(p2);
}

void System::uruchom() {
    int opcja = -1;

    do {
        system("cls"); // Czyœci ekran
        ustawKolor(KOLOR_NIEBIESKI);
        cout << "======================================\n";
        cout << "      SYSTEM REZERWACJI KOLEJOWEJ     \n";
        cout << "======================================\n";
        ustawKolor(KOLOR_RESET);
        cout << " [1] Znajdz polaczenie i kup bilet\n";
        cout << " [2] Pokaz podglad wszystkich pociagow\n";
        cout << " [3] Lista pasazerow (Administrator)\n";
        cout << " [4] Zapisz stan systemu\n";
        cout << " [0] WYJSCIE\n";
        cout << "======================================\n";
        cout << " Wybor > ";

        if (!(cin >> opcja)) {
            cin.clear(); cin.ignore(1000, '\n');
            continue;
        }

        switch (opcja) {
        case 1:
            obslugaRezerwacji();
            break;
        case 2:
            system("cls");
            for (auto p : pociagi) p->pokazPodgladPociagu();
            break;
        case 3:
            system("cls");
            obslugaListyPasazerow();
            break;
        case 4:
        {
            // Tworzymy plik na nowo i czyœcimy jego zawartoœæ
            ofstream plik("baza_danych.txt", ios::trunc);
            plik.close();
        }
        for (auto p : pociagi) p->zapiszStanDoPliku();
        ustawKolor(KOLOR_ZIELONY);
        cout << "Zapisano dane wszystkich pociagow!\n";
        ustawKolor(KOLOR_RESET);
        break;
        case 0:
            cout << "Do widzenia!\n";
            break;
        default:
            cout << "Nieznana opcja.\n";
        }

        if (opcja != 0) {
            cout << "\nNacisnij [Enter], aby wrocic do menu...";
            cin.ignore(); cin.get();
        }

    } while (opcja != 0);
}

void System::obslugaRezerwacji() {
    string skad, dokad;
    cout << "\n--- WYSZUKIWANIE POLACZEN ---\n";
    cout << "Podaj stacje poczatkowa: "; cin >> skad;
    cout << "Podaj stacje koncowa:    "; cin >> dokad;

    vector<Pociag*> wyniki = wyszukiwarka.znajdzPolaczenia(skad, dokad);

    if (wyniki.empty()) {
        ustawKolor(KOLOR_CZERWONY);
        cout << " [!] Brak bezposrednich polaczen na trasie " << skad << " -> " << dokad << ".\n";
        ustawKolor(KOLOR_RESET);
        return;
    }

    cout << "\nZnaleziono nastepujace polaczenia:\n";
    for (size_t i = 0; i < wyniki.size(); ++i) {
        ustawKolor(KOLOR_ZIELONY);
        cout << " " << i + 1 << ". " << wyniki[i]->pobierzNazwe() << "\n";
        ustawKolor(KOLOR_RESET);
        wyniki[i]->pobierzTrase().wyswietlPrzebieg();
    }

    int wyborPociagu;
    cout << "Wybierz numer pociagu (0 aby anulowac): ";
    cin >> wyborPociagu;

    if (wyborPociagu > 0 && wyborPociagu <= (int)wyniki.size()) {
        Pociag* wybrany = wyniki[wyborPociagu - 1];

        system("cls");
        wybrany->pokazPodgladPociagu();

        int w, m;
        cout << "\n--- KUPNO BILETU ---\n";
        cout << "Numer wagonu: "; cin >> w;
        cout << "Numer miejsca: "; cin >> m;

        wybrany->zarezerwujMiejsce(w, m);
    }
    else {
        cout << "Anulowano operacje.\n";
    }
}

void System::obslugaListyPasazerow() {
    cout << "\n--- LISTA PASAZEROW (ADMIN) ---\n";
    for (auto p : pociagi) {
        ustawKolor(KOLOR_ZOLTY);
        cout << ">> Pociag: " << p->pobierzNazwe() << "\n";
        ustawKolor(KOLOR_RESET);
        p->wyswietlListePasazerow();
        cout << "-------------------------------\n";
    }
}