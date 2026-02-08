#pragma once
#include <string>
#include <iostream>

enum class TypUlgi {
    NORMALNY,
    STUDENT,
    SENIOR
};

class Pasazer {
private:
    std::string imie;
    std::string nazwisko;
    TypUlgi ulga;

public:
    Pasazer(std::string i, std::string n, TypUlgi u);

    std::string pobierzImie() const;
    std::string pobierzNazwisko() const;
    double pobierzMnoznikCeny() const;

    friend std::ostream& operator<<(std::ostream& os, const Pasazer& p);
};