#include "Pociag.h"
#include "Wyjatki.h"
#include <iostream>
#include <iomanip>

using namespace std;

Pociag::Pociag(string _nazwa) : nazwa(_nazwa) {}

Pociag::~Pociag() {
    for (auto w : wagony) delete w;
    wagony.clear();
}

// Przeciazenie operatora +=
Pociag& Pociag::operator+=(Wagon* w) {
    wagony.push_back(w);
    cout << ">> Dolaczono wagon nr " << w->pobierzNumer() << " do pociagu " << nazwa << ".\n";
    return *this;
}

Pasazer* Pociag::zarezerwujMiejsce(int nrWagonu, int nrMiejsca) {
    bool znalezionoWagon = false;

    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
            znalezionoWagon = true;
            for (auto& m : w->pobierzMiejsca()) {
                if (m.pobierzNumer() == nrMiejsca) {

                    if (!m.czyWolne()) {
                        // RZUCENIE WYJATKU
                        throw MiejsceZajeteException(nrMiejsca);
                    }

                    // Pobieranie danych (logika interfejsu tutaj dla uproszczenia)
                    cout << "--- REZERWACJA MIEJSCA " << nrMiejsca << " ---\n";
                    string imie, nazwisko;
                    int typ;
                    cout << "Podaj imie: "; cin >> imie;
                    cout << "Podaj nazwisko: "; cin >> nazwisko;
                    cout << "Wybierz ulge (1-Student, 2-Senior, inne-Normalny): ";

                    if (!(cin >> typ)) {
                        cin.clear(); cin.ignore(1000, '\n');
                        throw BledneDaneException();
                    }

                    TypUlgi ulga = TypUlgi::NORMALNY;
                    if (typ == 1) ulga = TypUlgi::STUDENT;
                    else if (typ == 2) ulga = TypUlgi::SENIOR;

                    Pasazer* p = new Pasazer(imie, nazwisko, ulga);
                    m.zarezerwuj(p);

                    return p; // Zwracamy wskaznik, by main mogl go dodac do Rejestru
                }
            }
            throw NieznalezionoElementuException("Nie ma miejsca nr " + to_string(nrMiejsca) + " w tym wagonie.");
        }
    }

    if (!znalezionoWagon) {
        throw NieznalezionoElementuException("Nie ma wagonu nr " + to_string(nrWagonu));
    }
    return nullptr;
}

void Pociag::wyswietlWagon(int nrWagonu) {
    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
            w->wyswietlSchemat();
            return;
        }
    }
    cout << "Blad: Brak wagonu o numerze " << nrWagonu << ".\n";
}

void Pociag::znajdzWolneMiejsce(TypMiejsca typ) {
    cout << "Szukam wolnego miejsca...\n";
    bool znaleziono = false;
    for (auto w : wagony) {
        for (const auto& m : w->pobierzMiejsca()) {
            if (m.czyWolne() && m.pobierzRodzaj() == typ) {
                cout << "Wolne: Wagon " << w->pobierzNumer() << ", Miejsce " << m.pobierzNumer() << endl;
                znaleziono = true;
            }
        }
    }
    if (!znaleziono) cout << "Brak miejsc tego typu.\n";
}