#pragma once
#include <vector>
#include <string>
#include "Wagon.h"
#include "Trasa.h"

class Pociag {
private:
    std::string nazwa;
    std::string godzinaOdjazdu; // NOWE
    Trasa trasa;
    std::vector<Wagon*> wagony;

public:
    Pociag(std::string _nazwa, std::string _godzina, Trasa _trasa);
    ~Pociag();

    void dodajWagon(Wagon* w);

    void zarezerwujMiejsce(int nrWagonu, int nrMiejsca);
    void anulujRezerwacje(int nrWagonu, int nrMiejsca);
    void znajdzWolneMiejsce(int tryb);

    void wyswietlListePasazerow();
    void pokazPodgladPociagu();

    void zapiszStanDoPliku();
    void wczytajStanZPliku();

    std::string pobierzNazwe() const { return nazwa; }
    std::string pobierzGodzine() const { return godzinaOdjazdu; } // NOWE
    const Trasa& pobierzTrase() const { return trasa; }
};