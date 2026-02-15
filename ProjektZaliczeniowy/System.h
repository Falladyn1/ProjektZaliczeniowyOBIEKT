#pragma once
#include <vector>
#include <iostream>
#include "Pociag.h"
#include "Wyszukiwarka.h"

class System {
private:
    std::vector<Pociag*> pociagi;
    Wyszukiwarka wyszukiwarka;

    void inicjalizujDane();
    void obslugaRezerwacji();
    void obslugaListyPasazerow();

public:
    System();
    ~System();

    void uruchom();
};