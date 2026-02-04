#include <iostream>
#include "Pociag.h"
#include "WagonBezprzedzialowy.h"

int main() {
    Pociag express("InterCity Premium");

    express.dodajWagon(new WagonBezprzedzialowy(1));

    // Rezerwujemy kilka miejsc, ¿eby zobaczyæ "XX" na schemacie
    std::cout << "Rezerwuje miejsce 2 (bez stolika)...\n";
    express.zarezerwuj(1, 2);

    std::cout << "Rezerwuje miejsce 30 (ze stolikiem)...\n";
    express.zarezerwuj(1, 30);

    std::cout << "Rezerwuje miejsce 31 (ze stolikiem)...\n";
    express.zarezerwuj(1, 31);

    // Wyœwietlamy piêkny schemat
    express.pokazWagon(1);

    return 0;
}