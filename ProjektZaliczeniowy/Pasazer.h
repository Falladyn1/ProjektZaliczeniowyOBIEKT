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

    string pobierzImie() const;
    string pobierzNazwisko() const;
    string pobierzInfoUlgi() const;

    double pobierzMnoznikCeny() const;

    string pobierzPelneInfo() const;
};