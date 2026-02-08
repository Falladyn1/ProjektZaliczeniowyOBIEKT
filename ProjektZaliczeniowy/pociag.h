#pragma once
#include <vector>
#include <string>
#include "Wagon.h"

class Pociag {
private:
    std::string nazwa;
    std::vector<Wagon*> wagony;

public:
    Pociag(std::string _nazwa);
    ~Pociag();

    void dodajWagon(Wagon* w);

    // Kluczowe funkcje
    void zarezerwujMiejsce(int nrWagonu, int nrMiejsca);
    void anulujRezerwacje(int nrWagonu, int nrMiejsca);
    void znajdzWolneMiejsce(int tryb); // 1-Okno, 2-Korytarz

    void wyswietlListePasazerow();
    void pokazPodgladPociagu();

    // Obsluga plikow
    void zapiszStanDoPliku();
    void wczytajStanZPliku();
};