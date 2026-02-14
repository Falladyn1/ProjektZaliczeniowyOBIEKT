#pragma once
#include <vector>
#include "Miejsce.h"

class Wagon {
protected:
    int numerWagonu;
    double cenaZaMiejsce;
    std::vector<Miejsce> siedzenia;
public:
    Wagon(int nr, double cena) : numerWagonu(nr), cenaZaMiejsce(cena) {}
    virtual ~Wagon() = default;
    virtual void generujMiejsca() = 0;
    virtual void wyswietlSchemat() = 0;
    int pobierzNumer() const { return numerWagonu; }
    std::vector<Miejsce>& pobierzMiejsca() { return siedzenia; }
};