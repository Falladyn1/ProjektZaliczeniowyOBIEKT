#pragma once
#include "Wagon.h"

class wagonBezprzedzialowy : public Wagon {
private:
    int liczbaRzedow;
public:
    wagonBezprzedzialowy(int _nr, bool _stoliki, int _rzedy);

    void generujMiejsca();
};