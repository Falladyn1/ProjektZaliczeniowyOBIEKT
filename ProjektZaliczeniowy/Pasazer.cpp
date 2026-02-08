#include "Pasazer.h"

Pasazer::Pasazer(string i, string n, TypUlgi u)
    : imie(i), nazwisko(n), ulga(u) {
}

string Pasazer::pobierzImie() const { return imie; }
string Pasazer::pobierzNazwisko() const { return nazwisko; }

string Pasazer::pobierzInfoUlgi() const {
    switch (ulga) {
    case TypUlgi::STUDENT: return "Student (-51%)";
    case TypUlgi::SENIOR: return "Senior (-30%)";
    default: return "Normalny";
    }
}

double Pasazer::pobierzMnoznikCeny() const {
    switch (ulga) {
    case TypUlgi::STUDENT: return 0.49;
    case TypUlgi::SENIOR: return 0.70;
    default: return 1.0;
    }
}

string Pasazer::pobierzPelneInfo() const {
    return imie + " " + nazwisko + " (" + pobierzInfoUlgi() + ")";
}