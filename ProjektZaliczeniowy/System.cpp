#include "System.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h"
#include "Wyjatki.h"
#include <iostream>
#include <fstream>

using namespace std;

System::System() {
    inicjalizujDane();
}

System::~System() {
    for (int i = 0; i < pociagi.size(); i++) {
        delete pociagi[i];
    }
    pociagi.clear();
}

void System::inicjalizujDane() {
    ifstream plikTras("trasy.txt");

    if (plikTras.good() == false) {
        ustawKolor(KOLOR_CZERWONY);
        cout << "KRYTYCZNY BLAD: Nie znaleziono pliku 'trasy.txt'!" << endl;
        ustawKolor(KOLOR_RESET);
        exit(1);
    }

    string nazwa, godzina;
    while (plikTras >> nazwa >> godzina) {
        int liczbaStacji;
        plikTras >> liczbaStacji;

        Trasa t(nazwa);
        for (int i = 0; i < liczbaStacji; i++) {
            string stacja;
            plikTras >> stacja;
            t.dodajStacje(stacja);
        }

        Pociag* p = new Pociag(nazwa, godzina, t);

        Wagon* w1 = new WagonBezprzedzialowy(1);
        Wagon* w2 = new WagonPrzedzialowy(2);

        p->dodajWagon(w1);
        p->dodajWagon(w2);
        p->wczytajStanZPliku();

        pociagi.push_back(p);
        wyszukiwarka.dodajPociag(p);
    }
    plikTras.close();
}

void System::uruchom() {
    int opcja = -1;
    do {
        system("cls");
        ustawKolor(KOLOR_NIEBIESKI);
        cout << "======================================" << endl;
        cout << "      SYSTEM REZERWACJI KOLEJOWEJ     " << endl;
        cout << "======================================" << endl;
        ustawKolor(KOLOR_RESET);
        cout << " [1] Znajdz polaczenie i kup bilet" << endl;
        cout << " [2] Anuluj rezerwacje" << endl; 
        cout << " [3] Lista pasazerow (Administrator)" << endl;
        cout << " [4] Zapisz stan systemu (Bilety)" << endl;
        cout << " [5] Dostepne stacje" << endl;
        cout << " [0] WYJSCIE" << endl;
        cout << "======================================" << endl;
        cout << " Wybor > ";

        if (!(cin >> opcja)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (opcja == 1) {
            obslugaRezerwacji();
        }
        else if (opcja == 2) {
            obslugaAnulowania();
        }
        else if (opcja == 3) {
            system("cls");
            obslugaListyPasazerow();
        }
        else if (opcja == 4) {
            ofstream plik("baza_danych.txt", ios::trunc);
            plik.close(); 

            for (int i = 0; i < pociagi.size(); i++) {
                pociagi[i]->zapiszStanDoPliku();
            }

            ustawKolor(KOLOR_ZIELONY);
            cout << "Zapisano dane rezerwacji wszystkich pociagow!" << endl;
            ustawKolor(KOLOR_RESET);
        }
        else if (opcja == 5) {
            system("cls");
            wyswietlDostepneStacje();
        }
        else if (opcja == 0) {
            cout << "Do widzenia!" << endl;
        }
        else {
            cout << "Nieznana opcja." << endl;
        }

        if (opcja != 0) {
            cout << endl << "Nacisnij [Enter], aby wrocic do menu...";
            cin.ignore();
            cin.get();
        }

    } while (opcja != 0);
}

void System::obslugaRezerwacji() {
    string skad, dokad;
    cout << endl << "--- WYSZUKIWANIE POLACZEN ---" << endl;
    cout << "Podaj stacje poczatkowa: "; cin >> skad;
    cout << "Podaj stacje koncowa:    "; cin >> dokad;

    vector<Pociag*> wyniki = wyszukiwarka.znajdzPolaczenia(skad, dokad);

    if (wyniki.size() == 0) {
        ustawKolor(KOLOR_CZERWONY);
        cout << " [!] Brak polaczen na trasie " << skad << " -> " << dokad << "." << endl;
        ustawKolor(KOLOR_RESET);
        return;
    }

    cout << endl << "Znaleziono nastepujace polaczenia:" << endl;
    for (int i = 0; i < wyniki.size(); i++) {
        ustawKolor(KOLOR_ZIELONY);
        cout << " " << i + 1 << ". " << wyniki[i]->pobierzNazwe() << " (Odjazd: " << wyniki[i]->pobierzGodzine() << ")" << endl;
        ustawKolor(KOLOR_RESET);
    }

    int wybor;
    cout << endl << "Wybierz numer pociagu (0 aby anulowac): ";
    cin >> wybor;

    if (wybor > 0 && wybor <= wyniki.size()) {
        Pociag* wybrany = wyniki[wybor - 1];
        system("cls");
        wybrany->pokazPodgladPociagu();

        int w, m;
        cout << endl << "--- KUPNO BILETU ---" << endl;
        cout << "Numer wagonu: "; cin >> w;
        cout << "Numer miejsca: "; cin >> m;

        try {
            wybrany->zarezerwujMiejsce(w, m);
        }
        catch (BladRezerwacji& e) {
            ustawKolor(KOLOR_CZERWONY);
            cout << endl << "BLAD: " << e.what() << endl;
            ustawKolor(KOLOR_RESET);
        }
        catch (BladDanych& e) {
            ustawKolor(KOLOR_CZERWONY);
            cout << endl << "BLAD: " << e.what() << endl;
            ustawKolor(KOLOR_RESET);
        }
    }
}

void System::obslugaAnulowania() {
    string nazwa;
    int w, m;

    cout << endl << "--- ANULOWANIE REZERWACJI ---" << endl;
    cout << "Podaj nazwe pociagu (np. EIP_Poludnie): ";
    cin >> nazwa;

    Pociag* znalezionyPociag = nullptr;

    for (int i = 0; i < pociagi.size(); i++) {
        if (pociagi[i]->pobierzNazwe() == nazwa) {
            znalezionyPociag = pociagi[i];
            break; 
        }
    }

    if (znalezionyPociag == nullptr) {
        ustawKolor(KOLOR_CZERWONY);
        cout << " [!] Nie znaleziono pociagu o takiej nazwie w systemie." << endl;
        ustawKolor(KOLOR_RESET);
        return;
    }

    cout << "Podaj numer wagonu: "; cin >> w;
    cout << "Podaj numer miejsca: "; cin >> m;

    try {
        znalezionyPociag->anulujRezerwacje(w, m);
    }
    catch (BladRezerwacji& e) {
        ustawKolor(KOLOR_CZERWONY);
        cout << endl << "BLAD: " << e.what() << endl;
        ustawKolor(KOLOR_RESET);
    }
}

void System::obslugaListyPasazerow() {
    cout << endl << "--- LISTA PASAZEROW (ADMIN) ---" << endl;
    for (int i = 0; i < pociagi.size(); i++) {
        ustawKolor(KOLOR_ZOLTY);
        cout << ">> Pociag: " << pociagi[i]->pobierzNazwe() << " (Odjazd: " << pociagi[i]->pobierzGodzine() << ")" << endl;
        ustawKolor(KOLOR_RESET);

        pociagi[i]->wyswietlListePasazerow();
        cout << "-------------------------------" << endl;
    }
}

void System::wyswietlDostepneStacje() {
    vector<string> unikalne;

    for (int i = 0; i < pociagi.size(); i++) {
        vector<string> stacjePociagu = pociagi[i]->pobierzTrase().pobierzStacje();

        for (int j = 0; j < stacjePociagu.size(); j++) {
            string stacja = stacjePociagu[j];
            bool jest = false;

            for (int k = 0; k < unikalne.size(); k++) {
                if (unikalne[k] == stacja) {
                    jest = true;
                    break;
                }
            }

            if (jest == false) {
                unikalne.push_back(stacja);
            }
        }
    }

    ustawKolor(KOLOR_ZOLTY);
    cout << endl << "=== LISTA DOSTEPNYCH STACJI ===" << endl;
    ustawKolor(KOLOR_RESET);

    for (int i = 0; i < unikalne.size(); i++) {
        cout << " - " << unikalne[i] << endl;
    }

    cout << "===============================" << endl;
}