#include "Miejsce.h"

Miejsce::Miejsce(int nr, TypMiejsca r, double cena)
    : numerMiejsca(nr), rodzaj(r), cenaBazowa(cena), pasazer(nullptr) {
}

Miejsce::~Miejsce() {
    if (pasazer != nullptr) {
        delete pasazer;
    }
}

bool Miejsce::czyWolne() const {
    return pasazer == nullptr;
}

int Miejsce::pobierzNumer() const {
    return numerMiejsca;
}

TypMiejsca Miejsce::pobierzRodzaj() const {
    return rodzaj;
}

Pasazer* Miejsce::pobierzPasazera() const {
    return pasazer;
}

double Miejsce::obliczCeneKoncowa() const {
    if (czyWolne()) return cenaBazowa;
    return cenaBazowa * pasazer->pobierzMnoznikCeny();
}

void Miejsce::zarezerwuj(Pasazer* p) {
    if (pasazer != nullptr) delete pasazer;
    pasazer = p;
}

void Miejsce::zwolnij() {
    if (pasazer != nullptr) {
        delete pasazer;
        pasazer = nullptr;
    }
}