#pragma once
#include "Wagon.h"

class WagonPrzedzialowy : public Wagon {
public:
    WagonPrzedzialowy(int nr);
    void generujMiejsca();
    void wyswietlSchemat();
};