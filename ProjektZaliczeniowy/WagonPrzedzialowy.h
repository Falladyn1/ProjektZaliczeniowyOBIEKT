#pragma once
#include "Wagon.h"

class WagonPrzedzialowy : public Wagon {
private:
    int liczbaPrzedzialow;
public:
    WagonPrzedzialowy(int _nr);
    void generujMiejsca();
    void wyswietlSchemat();
};