#include "Miejsce.h"

Miejsce::Miejsce(int nr, int rz, char kol, TypMiejsca rodz, bool przedzial, bool stolik, double cena)
    : numerMiejsca(nr), rzad(rz), kolumna(kol), rodzaj(rodz),
    czyPrzedzial(przedzial), czyStolik(stolik), cenaBazowa(cena) {

    pasazer = nullptr;
}

Miejsce::~Miejsce() {
    if (pasazer != nullptr) {
        delete pasazer;
    }
}

bool Miejsce::czyWolne() const {
    return (pasazer == nullptr);
}

int Miejsce::pobierzNumer() const { return numerMiejsca; }
TypMiejsca Miejsce::pobierzRodzaj() const { return rodzaj; }

double Miejsce::obliczCeneKoncowa() const {
    if (czyWolne()) return cenaBazowa;
    return cenaBazowa * pasazer->pobierzMnoznikCeny();
}

string Miejsce::pobierzInfoPasazera() const {
    if (czyWolne()) return "Wolne";
    return pasazer->pobierzPelneInfo();
}

void Miejsce::zarezerwuj(Pasazer* nowyPasazer) {
    if (pasazer != nullptr) delete pasazer;
    pasazer = nowyPasazer;
}

void Miejsce::zwolnij() {
    if (pasazer != nullptr) {
        delete pasazer;
        pasazer = nullptr;
    }
}