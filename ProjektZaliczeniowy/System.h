#pragma once
#include <vector>
#include "Pociag.h"
#include "Wyszukiwarka.h"

class System {
private:
    std::vector<Pociag*> pociagi;
    Wyszukiwarka wyszukiwarka;

    void inicjalizujDane();
    void obslugaRezerwacji();
    void obslugaAnulowania();
    void obslugaListyPasazerow();
    void wyswietlDostepneStacje();

public:
    System();
    ~System();
    void uruchom();
};