#include <iostream>
#include <cstdlib>
#include "Pociag.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h"
#include "Wyjatki.h"

using namespace std;

void wyczyscEkran() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    Pociag interCity("Kopernik");
    interCity.dodajWagon(new WagonBezprzedzialowy(1));
    interCity.dodajWagon(new WagonPrzedzialowy(2));

    int opcja = -1;
    string komunikat = "";

    do {
        wyczyscEkran();

        // 1. Wyœwietlanie stanu poci¹gu (nowy, czysty wygl¹d)
        interCity.pokazPodgladPociagu();

        // 2. Proste powiadomienia i menu
        if (!komunikat.empty()) {
            cout << "\n>> " << komunikat << "\n";
            komunikat = "";
        }

        cout << "\n1. Rezerwuj miejsce";
        cout << "\n2. Lista pasazerow";
        cout << "\n0. Wyjscie";
        cout << "\n> ";

        if (!(cin >> opcja)) {
            cin.clear(); cin.ignore(1000, '\n');
            continue;
        }

        try {
            switch (opcja) {
            case 1: {
                int w, m;
                cout << "Nr wagonu: "; cin >> w;
                cout << "Nr miejsca: "; cin >> m;
                interCity.zarezerwujMiejsce(w, m);
                komunikat = "Zarezerwowano.";
                break;
            }
            case 2:
                wyczyscEkran();
                interCity.wyswietlListePasazerow();
                cout << "\n[Enter] powrot...";
                cin.ignore(); cin.get();
                break;
            case 0:
                break;
            default:
                komunikat = "Nieznana opcja.";
            }
        }
        catch (const std::exception& e) {
            komunikat = e.what();
        }

    } while (opcja != 0);

    return 0;
}