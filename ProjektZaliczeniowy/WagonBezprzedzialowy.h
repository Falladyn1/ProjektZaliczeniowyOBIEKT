#pragma once
#include "Wagon.h"

class WagonBezprzedzialowy : public Wagon {
public:
    WagonBezprzedzialowy(int nr);
    void generujMiejsca();
    void wyswietlSchemat();
};