#include <iostream>
#include "pociag.h"
#include "WagonBezprzedzialowy.h"
#include "WagonPrzedzialowy.h" 

int main() {
    pociag pkp("P1");

    pkp.dodajWagon(new WagonBezprzedzialowy(1)); // Bezprzedzia³owy
    pkp.dodajWagon(new WagonPrzedzialowy(2));    // Przedzia³owy

    std::cout << "--- Rezerwacja miejsc ---\n";

    pkp.zarezerwujMiejsce(1, 30);

    pkp.zarezerwujMiejsce(2, 1);
    pkp.zarezerwujMiejsce(2, 2);
    pkp.zarezerwujMiejsce(2, 3);
    pkp.zarezerwujMiejsce(2, 4);

    pkp.wyswietlWagon(1); 
    pkp.wyswietlWagon(2);

    return 0;
}