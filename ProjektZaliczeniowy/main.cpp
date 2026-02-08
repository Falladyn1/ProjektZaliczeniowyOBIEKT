#include <iostream>
#include "Pociag.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h"
#include "Wyjatki.h"

using namespace std;

int main() {
    // Tworzenie pociagu
    Pociag interCity("Kopernik");

    // Dodawanie wagonow
    interCity.dodajWagon(new WagonBezprzedzialowy(1)); // Wagon nr 1
    interCity.dodajWagon(new WagonPrzedzialowy(2));    // Wagon nr 2

    int opcja;
    do {
        cout << "\n=== SYSTEM REZERWACJI PKP ===\n";
        cout << "1. Zarezerwuj miejsce\n";
        cout << "2. Lista pasazerow\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";

        if (!(cin >> opcja)) {
            cout << "To nie jest liczba!\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        try {
            switch (opcja) {
            case 1: {
                int w, m;
                cout << "Podaj numer wagonu (1 lub 2): "; cin >> w;
                cout << "Podaj numer miejsca: "; cin >> m;
                // Proba rezerwacji moze rzucic wyjatek
                interCity.zarezerwujMiejsce(w, m);
                break;
            }
            case 2:
                interCity.wyswietlListePasazerow();
                break;
            case 0:
                cout << "Zamykanie programu...\n";
                break;
            default:
                cout << "Nieznana opcja.\n";
            }
        }
        catch (const MiejsceZajeteException& e) {
            cerr << "[BLAD] " << e.what() << endl;
        }
        catch (const NieznalezionoElementuException& e) {
            cerr << "[BLAD] " << e.what() << endl;
        }
        catch (const BledneDaneException& e) {
            cerr << "[BLAD] " << e.what() << endl;
        }
        catch (...) {
            cerr << "[BLAD] Wystapil nieznany blad.\n";
        }

    } while (opcja != 0);

    return 0;
}