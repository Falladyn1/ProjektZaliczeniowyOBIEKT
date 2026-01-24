#pragma once
#include "Wagon.h"

class wagonBezprzedzialowy : public Wagon {
private:
    int liczbaRzedow;
public:
    // Konstruktor przyjmuje tez informacje o stolikach
    wagonBezprzedzialowy(int _nr, int _liczbaRzedow, bool czyStoliki);
    void generujMiejsca() override;
};