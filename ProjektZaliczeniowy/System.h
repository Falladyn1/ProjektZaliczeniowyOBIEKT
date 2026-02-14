#pragma once
#include <vector>
#include <iostream>
#include "Pociag.h"
#include "Wyszukiwarka.h"

class System {
private:
    std::vector<Pociag*> pociagi;
    Wyszukiwarka wyszukiwarka;

    // Metody wewnêtrzne
    void inicjalizujDane();
    void obslugaRezerwacji();
    void obslugaListyPasazerow();

public:
    System();
    ~System();

    void uruchom(); // G³ówna pêtla menu
};