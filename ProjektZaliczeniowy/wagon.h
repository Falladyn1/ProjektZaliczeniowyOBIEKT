#pragma once
#include <vector>
#include "Miejsce.h"

class Wagon {
protected:
    int numerWagonu;
    int klasa;
    bool czySaStoliki; 
    std::vector<Miejsce> siedzenia;

public:
    Wagon(int _nr, bool _stoliki);
    virtual ~Wagon() = default;

    virtual void generujMiejsca() = 0;

    int pobierzNumer() const { return numerWagonu; }
    std::vector<Miejsce>& pobierzMiejsca() { return siedzenia; }
};