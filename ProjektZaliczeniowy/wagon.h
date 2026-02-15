#pragma once
#include <vector>
#include "Miejsce.h"

using namespace std;

class Wagon {
protected:
    int numerWagonu;
    double cenaZaMiejsce;
    vector<Miejsce> siedzenia;

public:
    Wagon(int nr, double cena) {
        numerWagonu = nr;
        cenaZaMiejsce = cena;
    }
    virtual ~Wagon() {} 

    virtual void generujMiejsca() = 0;
    virtual void wyswietlSchemat() = 0;

    int pobierzNumer() { return numerWagonu; }
    vector<Miejsce>& pobierzMiejsca() { return siedzenia; }
};