#include <iostream>
#include "pociag.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h" 

using namespace std;

void wyswietlMenu() {
    cout << "\n=== SYSTEM REZERWACJI PKP ===\n";
    cout << "1. Wyswietl schemat wagonu\n";
    cout << "2. Zarezerwuj miejsce (po numerze)\n";
    cout << "3. Znajdz wolne miejsce (wg typu)\n";
    cout << "0. Wyjscie\n";
    cout << "Wybierz opcje: ";
}

int main() {
    Pociag pkp("P1");

    pkp.dodajWagon(new WagonBezprzedzialowy(1));
    pkp.dodajWagon(new WagonPrzedzialowy(2));

    int opcja;
    do {
        wyswietlMenu();
        cin >> opcja;

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
            cout << "Podaj numer wagonu: ";
            cin >> nrW;
            cout << "Podaj numer miejsca: ";
            cin >> nrM;
            pkp.zarezerwujMiejsce(nrW, nrM);
            break;
        }
        case 3: {
            cout << "Jaki typ miejsca? (1-Okno, 2-Srodek, 3-Korytarz): ";
            int t;
            cin >> t;
            TypMiejsca szukanyTyp;
            if (t == 1) szukanyTyp = TypMiejsca::OKNO;
            else if (t == 2) szukanyTyp = TypMiejsca::SRODEK;
            else szukanyTyp = TypMiejsca::KORYTARZ;

            pkp.znajdzWolneMiejsce(szukanyTyp);
            break;
        }
        case 0:
            cout << "Zamykanie programu...\n";
            break;
        default:
            cout << "Nieznana opcja.\n";
        }

    } while (opcja != 0);

    return 0;
}