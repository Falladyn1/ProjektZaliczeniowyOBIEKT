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
            bool maSkad = false;
            bool maDokad = false;

            for (const auto& s : stacje) {
                if (s == skad) maSkad = true;
                if (s == dokad) maDokad = true;
            }

            if (maSkad && maDokad) {
                znalezione.push_back(p);
            }
        }
        return znalezione;
    }
};