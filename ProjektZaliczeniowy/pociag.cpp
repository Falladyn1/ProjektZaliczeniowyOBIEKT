#include "Pociag.h"
#include <iostream>

using namespace std;

Pociag::Pociag(std::string _nazwa) {
	nazwa = _nazwa;
}

Pociag::~Pociag() {
	for (int i = 0; i < wagony.size(); i++)
		delete wagony[i];
	wagony.clear();
}

void Pociag::dodajWagon(Wagon* wagon) {
	wagony.push_back(wagon);
}

void Pociag::zarezerwuj(int nrWagonu, int nrMiejsca) {
	for (int i = 0; i < wagony.size(); i++) {
		if (wagony[i]->pobierzNumer() == nrWagonu) {
			vector<Miejsce>& miejsca = wagony[i]->pobierzMiejsca();
			
			for (int j = 0; j < miejsca.size(); j++) {
				if (miejsca[j].pobierzNumer() == nrMiejsca) {
					if (miejsca[j].czyWolne()) {
						miejsca[j].zarezerwuj();
						cout << "Zarezerwowano pomyslnie " << nrMiejsca;
						if (miejsca[j].czyMaStolik()) {
							cout << " (ze stolikiem)";
						}
						cout << ".\n";
					}
					else {
						cout << "Miejsce zajete!\n";
					}

				}
				return;

			}
		}
	}
	cout << "Nie znaleziono.\n";
}

void Pociag::wyswietlSklad() {
	cout << "Pociag: " << nazwa << "\n";
	for (int i = 0; i < wagony.size(); i++) {
		cout << " - Wagon nr " << wagony[i]->pobierzNumer() << "\n";
	}
}

void Pociag::pokazWagon(int nrWagonu) {
	for (int i = 0; i < wagony.size(); i++) {
		if (wagony[i]->pobierzNumer() == nrWagonu) {
			wagony[i]->wyswietlSchemat();
			return;
		}
	}
	std::cout << "Nie ma takiego wagonu.\n";
}