#pragma once
#include <string>
#include <iostream>

using namespace std;

enum class TypUlgi {
    NORMALNY,
    STUDENT, // -51%
    SENIOR   // -30%
};

class Pasazer {
private:
    string imie;
    string nazwisko;
    TypUlgi ulga;

public:
    Pasazer(string i, string n, TypUlgi u);

    // Gettery
    string pobierzImie() const;
    string pobierzNazwisko() const;
    double pobierzMnoznikCeny() const;

    // Przeciazenie operatora ==
    bool operator==(const Pasazer& inny) const;

    // Funkcja zaprzyjazniona (FRIEND) do wypisywania
    friend ostream& operator<<(ostream& os, const Pasazer& p);
};