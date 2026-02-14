#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "Pociag.h"

class Wyszukiwarka {
private:
    std::vector<Pociag*> pociagi;

public:
    // Dodaje poci¹g do bazy wyszukiwarki
    void dodajPociag(Pociag* p) {
        pociagi.push_back(p);
    }

    // Zwraca listê poci¹gów, które jad¹ przez obie stacje
    std::vector<Pociag*> znajdzPolaczenia(std::string skad, std::string dokad) {
        std::vector<Pociag*> znalezione;

        for (auto p : pociagi) {
            const auto& stacje = p->pobierzTrase().pobierzStacje();
            bool maSkad = false;
            bool maDokad = false;

            // Sprawdzamy czy stacje wystêpuj¹ w trasie
            for (const auto& s : stacje) {
                if (s == skad) maSkad = true;
                if (s == dokad) maDokad = true;
            }

            // Poci¹g musi przeje¿d¿aæ przez obie stacje
            if (maSkad && maDokad) {
                znalezione.push_back(p);
            }
        }
        return znalezione;
    }
};