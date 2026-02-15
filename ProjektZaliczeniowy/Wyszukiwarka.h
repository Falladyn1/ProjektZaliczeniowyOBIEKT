#pragma once
#include <vector>
#include <string>
#include "Pociag.h"

using namespace std;

class Wyszukiwarka {
private:
    vector<Pociag*> pociagi;

public:
    void dodajPociag(Pociag* p) {
        pociagi.push_back(p);
    }

    vector<Pociag*> znajdzPolaczenia(string skad, string dokad) {
        vector<Pociag*> znalezione;

        for (int i = 0; i < pociagi.size(); i++) {
            vector<string> stacje = pociagi[i]->pobierzTrase().pobierzStacje();

            int indeksSkad = -1;
            int indeksDokad = -1;

            // Szukanie indeksow stacji w wektorze
            for (int j = 0; j < stacje.size(); j++) {
                if (stacje[j] == skad) indeksSkad = j;
                if (stacje[j] == dokad) indeksDokad = j;
            }

            // Kierunek sprawdzamy poprzez indeks
            if (indeksSkad != -1 && indeksDokad != -1 && indeksSkad < indeksDokad) {
                znalezione.push_back(pociagi[i]);
            }
        }
        return znalezione;
    }
};