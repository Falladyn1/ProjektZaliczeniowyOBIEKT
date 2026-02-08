#include <iostream>
#include "pociag.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h"

using namespace std;

void wyswietlMenu() {
    cout << "\n=== SYSTEM REZERWACJI PKP ===\n";
    cout << "1. Wyswietl schemat wagonu\n";
    cout << "2. Zarezerwuj miejsce (Tworzenie pasazera)\n";
    cout << "3. Znajdz wolne miejsce (wg typu)\n";
    cout << "4. Lista pasazerow\n";
    cout << "0. Wyjscie\n";
    cout << "Wybierz opcje: ";
}

int main() {
    Pociag pkp("InterCity Kopernik");

    // Dodajemy wagony (1 - bezprzedzialowy 2 klasa, 2 - przedzialowy 1 klasa)
    pkp.dodajWagon(new WagonBezprzedzialowy(1));
    pkp.dodajWagon(new WagonPrzedzialowy(2));

    int opcja;
    do {
        wyswietlMenu();
        if (!(cin >> opcja)) { // Zabezpieczenie przed literami
            cin.clear(); cin.ignore(1000, '\n');
            continue;
        }

        switch (opcja) {
        case 1: {
            int nr;
            cout << "Podaj numer wagonu (1-2): ";
            cin >> nr;
            pkp.wyswietlWagon(nr);
            break;
        }
        case 2: {
            int nrW, nrM;
            cout << "Podaj numer wagonu: "; cin >> nrW;
            cout << "Podaj numer miejsca: "; cin >> nrM;
            pkp.zarezerwujMiejsce(nrW, nrM);
            break;
        }
        case 3: {
            cout << "Jaki typ miejsca? (1-Okno, 2-Srodek, 3-Korytarz): ";
            int t; cin >> t;
            TypMiejsca szukanyTyp = TypMiejsca::KORYTARZ;
            if (t == 1) szukanyTyp = TypMiejsca::OKNO;
            else if (t == 2) szukanyTyp = TypMiejsca::SRODEK;

            pkp.znajdzWolneMiejsce(szukanyTyp);
            break;
        }
        case 4:
            pkp.wyswietlListePasazerow();
            break;
        case 0:
            cout << "Zamykanie programu...\n";
            break;
        default:
            cout << "Nieznana opcja.\n";
        }

    } while (opcja != 0);

    return 0;
}