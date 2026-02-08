#pragma once
#include "Wagon.h"

class WagonBezprzedzialowy : public Wagon {
private:
    int liczbaRzedow;
public:
    WagonBezprzedzialowy(int _nr);
    void generujMiejsca();
    void wyswietlSchemat();
};