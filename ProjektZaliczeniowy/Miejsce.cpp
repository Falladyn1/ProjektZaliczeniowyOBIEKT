#include "Miejsce.h"

Miejsce::Miejsce(int nr, TypMiejsca r, double cena) {
    numerMiejsca = nr;
    rodzaj = r;
    cenaBazowa = cena;
    pasazer = nullptr; // Na poczatku miejsce jest wolne
}

Miejsce::~Miejsce() {
    // Zwalnianie pamieci
    if (pasazer != nullptr) {
        delete pasazer;
    }
}

bool Miejsce::czyWolne() {
    if (pasazer == nullptr) return true;
    else return false;
}

int Miejsce::pobierzNumer() { return numerMiejsca; }
TypMiejsca Miejsce::pobierzRodzaj() { return rodzaj; }
Pasazer* Miejsce::pobierzPasazera() { return pasazer; }

double Miejsce::obliczCeneKoncowa() {
    if (czyWolne() == true) {
        return cenaBazowa;
    }
    return cenaBazowa * pasazer->pobierzMnoznikCeny();
}

void Miejsce::zarezerwuj(Pasazer* p) {
    if (pasazer != nullptr) {
        delete pasazer; // Usuwamy starego pasazera jakby co
    }
    pasazer = p;
}

void Miejsce::zwolnij() {
    if (pasazer != nullptr) {
        delete pasazer;
        pasazer = nullptr;
    }
}