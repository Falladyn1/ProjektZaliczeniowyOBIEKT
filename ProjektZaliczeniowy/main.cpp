#include <iostream>
#include <cstdlib>
#include "Pociag.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h"
#include "Trasa.h"
#include "Wyjatki.h"

using namespace std;

int main() {
    Trasa trasaIC("Warszawa Centralna -> Gdynia Glowna");
    trasaIC.dodajStacje("Warszawa C.");
    trasaIC.dodajStacje("Ilawa Gl.");
    trasaIC.dodajStacje("Malbork");
    trasaIC.dodajStacje("Gdansk Gl.");
    trasaIC.dodajStacje("Gdynia Gl.");

    Pociag interCity("1", trasaIC);

    interCity.dodajWagon(new WagonBezprzedzialowy(1));
    interCity.dodajWagon(new WagonPrzedzialowy(2));

    interCity.wczytajStanZPliku();

    int opcja = -1;
    string komunikat = "";

    do {
        interCity.pokazPodgladPociagu();

        if (!komunikat.empty()) {
            ustawKolor(KOLOR_ZOLTY);
            cout << "\n>> KOMUNIKAT: " << komunikat << "\n";
            ustawKolor(KOLOR_RESET);
            komunikat = "";
        }

        cout << "\n=== MENU GLOWNE ===\n";
        cout << "1. Rezerwuj miejsce\n";
        cout << "2. Anuluj rezerwacje\n";
        cout << "3. Znajdz wolne miejsce\n";
        cout << "4. Lista pasazerow\n";
        cout << "5. Zapisz stan\n";
        cout << "0. Wyjscie\n";
        cout << "> ";

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
                komunikat = "Zarezerwowano!";
                break;
            }
            case 2: {
                int w, m;
                cout << "Nr wagonu: "; cin >> w;
                cout << "Nr miejsca: "; cin >> m;
                interCity.anulujRezerwacje(w, m);
                komunikat = "Anulowano rezerwacje.";
                break;
            }
            case 3: {
                int typ;
                cout << "1-Okno, 2-Korytarz: "; cin >> typ;
                interCity.znajdzWolneMiejsce(typ);
                cout << "Wcisnij Enter..."; cin.ignore(); cin.get();
                break;
            }
            case 4:
                interCity.wyswietlListePasazerow();
                cout << "\n[Enter] powrot..."; cin.ignore(); cin.get();
                break;
            case 5:
                interCity.zapiszStanDoPliku();
                komunikat = "Zapisano do pliku.";
                break;
            case 0:
                interCity.zapiszStanDoPliku();
                cout << "Do widzenia!\n";
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