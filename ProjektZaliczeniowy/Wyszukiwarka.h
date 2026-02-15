#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Pociag.h"

class Wyszukiwarka {
private:
    std::vector<Pociag*> pociagi;

public:
    void dodajPociag(Pociag* p) {
        pociagi.push_back(p);
    }

    std::vector<Pociag*> znajdzPolaczenia(std::string skad, std::string dokad) {
        std::vector<Pociag*> znalezione;

        for (auto p : pociagi) {
            const auto& stacje = p->pobierzTrase().pobierzStacje();

            int indeksSkad = -1;
            int indeksDokad = -1;

            for (int i = 0; i < (int)stacje.size(); ++i) {
                if (stacje[i] == skad) indeksSkad = i;
                if (stacje[i] == dokad) indeksDokad = i;
            }

            if (indeksSkad != -1 && indeksDokad != -1 && indeksSkad < indeksDokad) {
                znalezione.push_back(p);
            }
        }
        return znalezione;
    }
};