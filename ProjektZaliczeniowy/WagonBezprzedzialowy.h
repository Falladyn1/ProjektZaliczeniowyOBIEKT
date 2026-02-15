#pragma once
#include "Wagon.h"

class WagonBezprzedzialowy : public Wagon {
public:
    WagonBezprzedzialowy(int _nr);
    void generujMiejsca() override;
    void wyswietlSchemat() override;
};