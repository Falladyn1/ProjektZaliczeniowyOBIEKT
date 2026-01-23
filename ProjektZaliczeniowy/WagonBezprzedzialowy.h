#pragma once
#include "Wagon.h"

class wagonBezprzedzialowy : public Wagon {
public:
    wagonBezprzedzialowy(int _nr, int liczbaRzedow);
    void generujMiejsca();
};