#include "Pociag.h"
#include "Wyjatki.h"
#include <iostream>

using namespace std;

Pociag::Pociag(string _nazwa) : nazwa(_nazwa) {}

Pociag::~Pociag() {
    // Musimy usunac wagony bo byly tworzone przez new
    for (auto w : wagony) {
        delete w;
    }
    wagony.clear();
}

Pociag& Pociag::operator+=(Wagon* w) {
    wagony.push_back(w);
    cout << ">> Dodano wagon nr " << w->pobierzNumer() << " do pociagu.\n";
    return *this;
}

void Pociag::dodajWagon(Wagon* w) {
    *this += w; // Wywolujemy operator +=
}

void Pociag::zarezerwujMiejsce(int nrWagonu, int nrMiejsca) {
    bool znalezionoWagon = false;

    for (auto w : wagony) {
        if (w->pobierzNumer() == nrWagonu) {
            znalezionoWagon = true;

            // Szukamy miejsca w wagonie
            for (auto& m : w->pobierzMiejsca()) {
                if (m.pobierzNumer() == nrMiejsca) {

                    if (!m.czyWolne()) {
                        throw MiejsceZajeteException(nrMiejsca);
                    }

                    // Skoro wolne, to pytamy o dane
                    string imie, nazwisko;
                    int wyborUlgi;
                    cout << "Podaj imie: "; cin >> imie;
                    cout << "Podaj nazwisko: "; cin >> nazwisko;
                    cout << "Typ znizki (1-Student, 2-Senior, inne-Normalny): ";

                    if (!(cin >> wyborUlgi)) {
                        cin.clear(); cin.ignore(1000, '\n');
                        throw BledneDaneException();
                    }

                    TypUlgi ulga = TypUlgi::NORMALNY;
                    if (wyborUlgi == 1) ulga = TypUlgi::STUDENT;
                    else if (wyborUlgi == 2) ulga = TypUlgi::SENIOR;

                    // Rezerwujemy
                    Pasazer* nowyPasazer = new Pasazer(imie, nazwisko, ulga);
                    m.zarezerwuj(nowyPasazer);

                    cout << "Sukces! Zarezerwowano miejsce.\n";
                    return;
                }
            }
            throw NieznalezionoElementuException("Brak miejsca nr " + to_string(nrMiejsca) + " w wagonie " + to_string(nrWagonu));
        }
    }

    if (!znalezionoWagon) {
        throw NieznalezionoElementuException("Brak wagonu nr " + to_string(nrWagonu));
    }
}

void Pociag::wyswietlListePasazerow() {
    cout << "\n--- LISTA PASAZEROW POCIAGU " << nazwa << " ---\n";
    bool pusty = true;

    for (auto w : wagony) {
        for (const auto& m : w->pobierzMiejsca()) {
            if (!m.czyWolne()) {
                pusty = false;
                cout << "Wagon " << w->pobierzNumer()
                    << " | Miejsce " << m.pobierzNumer() << " | ";
                cout << *(m.pobierzPasazera()); // Uzycie operatora << z Pasazer.h
                cout << " | Cena: " << m.obliczCeneKoncowa() << " PLN\n";
            }
        }
    }

    if (pusty) cout << "(Pociag jest pusty)\n";
}