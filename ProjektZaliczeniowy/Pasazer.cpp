#include "Pasazer.h"

Pasazer::Pasazer(std::string i, std::string n, TypUlgi u)
    : imie(i), nazwisko(n), ulga(u) {
}

std::string Pasazer::pobierzImie() const {
    return imie;
}

std::string Pasazer::pobierzNazwisko() const {
    return nazwisko;
}

double Pasazer::pobierzMnoznikCeny() const {
    if (ulga == TypUlgi::STUDENT) return 0.49; 
    if (ulga == TypUlgi::SENIOR) return 0.70; 
    return 1.0;
}

std::ostream& operator<<(std::ostream& os, const Pasazer& p) {
    os << p.imie << " " << p.nazwisko;
    if (p.ulga == TypUlgi::STUDENT) os << " [ULGA STUDENCKA]";
    else if (p.ulga == TypUlgi::SENIOR) os << " [ULGA SENIOR]";
    return os;
}