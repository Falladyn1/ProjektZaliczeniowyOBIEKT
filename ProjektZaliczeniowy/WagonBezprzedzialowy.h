#pragma once
#include "wagon.h"
class wagonBezprzedzialowy :
    public Wagon
{
    wagonBezprzedzialowy(int _nr, int liczbaRzedow);
    void generujMiejsca();
};

