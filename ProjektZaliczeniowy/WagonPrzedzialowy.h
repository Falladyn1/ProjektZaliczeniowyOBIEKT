#pragma once
#include "Wagon.h"

class WagonPrzedzialowy : public Wagon {
public:
    WagonPrzedzialowy(int _nr);
    void generujMiejsca() override;
    void wyswietlSchemat() override;
};