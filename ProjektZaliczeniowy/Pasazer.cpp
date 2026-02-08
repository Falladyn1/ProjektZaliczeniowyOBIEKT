#include "Pasazer.h"

Pasazer::Pasazer(string i, string n, TypUlgi u)
    : imie(i), nazwisko(n), ulga(u) {
}

string Pasazer::pobierzImie() const { return imie; }
string Pasazer::pobierzNazwisko() const { return nazwisko; }

double Pasazer::pobierzMnoznikCeny() const {
    switch (ulga) {
    case TypUlgi::STUDENT: return 0.49;
    case TypUlgi::SENIOR: return 0.70;
    default: return 1.0;
    }
}

bool Pasazer::operator==(const Pasazer& inny) const {
    return (this->imie == inny.imie && this->nazwisko == inny.nazwisko);
}

ostream& operator<<(ostream& os, const Pasazer& p) {
    os << p.imie << " " << p.nazwisko;
    switch (p.ulga) {
    case TypUlgi::STUDENT: os << " (Student -51%)"; break;
    case TypUlgi::SENIOR:  os << " (Senior -30%)"; break;
    default:               os << " (Normalny)"; break;
    }
    return os;
}