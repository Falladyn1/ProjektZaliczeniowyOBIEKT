#include "System.h"
#include "Trasa.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h"
#include "Wyjatki.h"
#include <iostream>
#include <cstdlib> 
#include <fstream> 
#include <algorithm> 

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
    ifstream plikTras("trasy.txt");

    if (!plikTras.is_open()) {
        ustawKolor(KOLOR_CZERWONY);
        cout << "KRYTYCZNY BLAD: Nie znaleziono pliku 'trasy.txt'!\n";
        ustawKolor(KOLOR_RESET);
        system("pause");
        exit(1);
    }

    string nazwaPociagu, godzinaOdjazdu;

    while (plikTras >> nazwaPociagu >> godzinaOdjazdu) {
        int liczbaStacji;
        plikTras >> liczbaStacji;

        vector<string> nazwyStacji;
        for (int i = 0; i < liczbaStacji; ++i) {
            string stacja;
            plikTras >> stacja;
            nazwyStacji.push_back(stacja);
        }

        if (nazwyStacji.size() >= 2) {
            string nazwaRelacji = nazwyStacji.front() + " -> " + nazwyStacji.back();
            Trasa t(nazwaRelacji);

            for (const auto& s : nazwyStacji) {
                t.dodajStacje(s);
            }

            Pociag* p = new Pociag(nazwaPociagu, godzinaOdjazdu, t);
            p->dodajWagon(new WagonBezprzedzialowy(1));
            p->dodajWagon(new WagonPrzedzialowy(2));
            p->wczytajStanZPliku();

            pociagi.push_back(p);
            wyszukiwarka.dodajPociag(p);
        }
    }
    plikTras.close();
}

void System::uruchom() {
    int opcja = -1;

    do {
        system("cls");
        ustawKolor(KOLOR_NIEBIESKI);
        cout << "======================================\n";
        cout << "      SYSTEM REZERWACJI KOLEJOWEJ     \n";
        cout << "======================================\n";
        ustawKolor(KOLOR_RESET);
        cout << " [1] Znajdz polaczenie i kup bilet\n";
        cout << " [2] Lista pasazerow (Administrator)\n";
        cout << " [3] Zapisz stan systemu (Bilety)\n";
        cout << " [4] Dostepne stacje\n";
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
            obslugaListyPasazerow();
            break;
        case 3:
        {
            ofstream plik("baza_danych.txt", ios::trunc);
            plik.close();
        }
        for (auto p : pociagi) p->zapiszStanDoPliku();
        ustawKolor(KOLOR_ZIELONY);
        cout << "Zapisano dane rezerwacji wszystkich pociagow!\n";
        ustawKolor(KOLOR_RESET);
        break;
        case 4:
            system("cls");
            wyswietlDostepneStacje();
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
        cout << " " << i + 1 << ". " << wyniki[i]->pobierzNazwe() << " (Odjazd: " << wyniki[i]->pobierzGodzine() << ")\n";
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

        try {
            wybrany->zarezerwujMiejsce(w, m);
        }
        catch (const exception& e) {
            ustawKolor(KOLOR_CZERWONY);
            cout << "\nBLAD: " << e.what() << "\n";
            ustawKolor(KOLOR_RESET);
        }
    }
    else {
        cout << "Anulowano operacje.\n";
    }
}

void System::obslugaListyPasazerow() {
    cout << "\n--- LISTA PASAZEROW (ADMIN) ---\n";
    for (auto p : pociagi) {
        ustawKolor(KOLOR_ZOLTY);
        cout << ">> Pociag: " << p->pobierzNazwe() << " (Odjazd: " << p->pobierzGodzine() << ")\n";
        ustawKolor(KOLOR_RESET);
        p->wyswietlListePasazerow();
        cout << "-------------------------------\n";
    }
}

void System::wyswietlDostepneStacje() {
    vector<string> unikalneStacje;

    for (auto p : pociagi) {
        for (const auto& stacja : p->pobierzTrase().pobierzStacje()) {
            if (find(unikalneStacje.begin(), unikalneStacje.end(), stacja) == unikalneStacje.end()) {
                unikalneStacje.push_back(stacja);
            }
        }
    }

    ustawKolor(KOLOR_ZOLTY);
    cout << "\n=== LISTA DOSTEPNYCH STACJI W SYSTEMIE ===\n";
    ustawKolor(KOLOR_RESET);
    for (size_t i = 0; i < unikalneStacje.size(); ++i) {
        cout << " - " << unikalneStacje[i] << "\n";
    }
    cout << "==========================================\n";
}