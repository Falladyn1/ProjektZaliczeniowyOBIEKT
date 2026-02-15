#pragma once
#include <string>
#include <iostream>

using namespace std;

enum TypUlgi { NORMALNY, STUDENT, SENIOR };

class Pasazer {
private:
    string imie;
    string nazwisko;
    TypUlgi ulga;

public:
    Pasazer(string i, string n, TypUlgi u);

    // Gettery
    string pobierzImie();
    string pobierzNazwisko();
    TypUlgi pobierzUlge();
    double pobierzMnoznikCeny();

    friend ostream& operator<<(ostream& os, Pasazer& p);
};